"""Module for extracting design element's properties"""

import base64
import math
import operator
from io import BytesIO
from typing import Tuple, Dict, List

import numpy as np
from PIL import Image
from mystique import config, default_host_configs
from pytesseract import pytesseract, Output


class ExtractProperties:
    """
    Class handles of property extraction from the identified design
    elements.
    from all the design elements - extracts text
    from textual elements - extracts size, color, weight
    from actionset elements - extracts style based on the background
                              color
    from image objects - extracts image size
    """

    def get_actionset_type(self, image=None, coords=None):
        """
        Returns the actionset style by finding the
        closes background color of the obejct
        @param image: input PIL image
        @param coords: object's coordinate
        @return : style string of the actionset
        """
        cropped_image = image.crop(coords)
        # get 2 dominant colors
        quantized = cropped_image.quantize(colors=2, method=2)
        # extract the background color
        background_color = quantized.getpalette()[:3]
        colors = {
            "destructive": [
                (255, 0, 0),
                (180, 8, 0),
                (220, 54, 45),
                (194, 25, 18),
                (143, 7, 0)
            ],
            "positive": [
                (0, 0, 255),
                (7, 47, 95),
                (18, 97, 160),
                (56, 149, 211)
            ]
        }
        style = "default"
        found_colors = []
        distances = []
        # find the dominant background colors based on the RGB difference
        for key, values in colors.items():
            for value in values:
                distance = np.sqrt(
                    np.sum(
                        (np.asarray(value) - np.asarray(
                            background_color)) ** 2
                    )
                )
                if distance <= 150:
                    found_colors.append(key)
                    distances.append(distance)
        if found_colors:
            index = distances.index(min(distances))
            style = found_colors[index]
        return style

    def get_text(self, image=None, coords=None):
        """
        Extract the text from the object coordinates
        in the input deisgn image using pytesseract.
        @param image: input PIL image
        @param coords: tuple of coordinates from which
                       text should be extracted
        @return: ocr text
        """
        coords = (coords[0] - 5, coords[1], coords[2] + 5, coords[3])
        cropped_image = image.crop(coords)
        cropped_image = cropped_image.convert("LA")
        w, h = cropped_image.size
        cropped_image = cropped_image.resize((w * 10, h * 10),
                                             Image.ANTIALIAS)

        return pytesseract.image_to_string(
            cropped_image, lang="eng", config="--psm 6")

    def get_size_and_weight(self, image=None, coords=None):
        """
        Extract the size and weight of textual contents from
        the input image by taking an average of each edge
        countour's of height and width of each character.

        @param image : input PIL image
        @param coords: list of coordinated from which
                       text and height should be extracted
        @return: size and weight
        """
        cropped_image = image.crop(coords)
        image_width, image_height = image.size
        img = np.asarray(cropped_image)
        # edge detection
        img_data = pytesseract.image_to_data(img, output_type=Output.DICT)
        box_height = []
        box_width = []
        n_boxes = len(img_data['level'])
        for i in range(n_boxes):
            if len(img_data['text'][i]) > 1:  # to ignore img with wrong bbox
                (_, _, w, h) = (img_data['left'][i], img_data['top'][i],
                                img_data['width'][i], img_data['height'][i])
                # h = text_size_processing(img_data['text'][i], h)
                w = w/len(img_data['text'][i])  # Approximate character width
                box_height.append(h)
                box_width.append(w)
        font_size = default_host_configs.FONT_SIZE
        font_weight = default_host_configs.FONT_WEIGHT

        # Handling of unrecognized characters
        if len(box_height) == 0:
            heights_ratio = font_size['default']
            weights_ratio = font_weight['default']
        else:
            heights = int(np.mean(box_height))
            heights_ratio = round((heights/image_height), 4)
            weights = int(np.mean(box_width))
            weights_ratio = round((weights/image_width), 4)

        if font_size['small'] < heights_ratio < font_size['default']:
            size = "Small"
        elif font_size['default'] < heights_ratio < font_size['medium']:
            size = "Default"
        elif font_size['medium'] < heights_ratio < font_size['large']:
            size = "Medium"
        elif font_size['large'] < heights_ratio < font_size['extralarge']:
            size = "Large"
        elif font_size['extralarge'] < heights_ratio:
            size = "ExtraLarge"
        else:
            size = "Default"

        # TODO: Fine tune weights threshold
        if font_weight['lighter'] > weights_ratio:
            weight = "Lighter"
        elif font_weight['bolder'] < weights_ratio:
            weight = "Bolder"
        else:
            weight = "Default"

        return size, weight

    def get_alignment(self, image=None, xmin=None, xmax=None):
        """
        Get the horizontal alignment of the elements by defining a
        ratio based on the xmin and xmax center of each object.
        if a element's xmin and xmax avg lies within:
        0 - 45 % [ left range ] of the image width
        45 - 55% [ center rance ] of the image width
        > 55% [ right range ] of the image width
        @param image: input PIL image
        @param xmin: xmin of the object detected
        @param xmax: xmax of the object detected
        @return: position string[Left/Right/Center]
        """

        avg = math.ceil((xmin + xmax) / 2)
        w, h = image.size
        #  if an object lies within the 15% of the start of the image then the
        #  object is considered as left by default [to avoid any lengthy
        # textbox coming into center when considering the xmin and xmax center]
        left_range = (w * 15) / 100
        if math.floor(xmin) <= math.ceil(left_range) or abs(
                xmin - left_range) < 10:
            return "Left"

        if 0 <= (avg / w) * 100 < 45:
            return "Left"
        elif 45 <= (avg / w) * 100 < 55:
            return "Center"
        else:
            return "Right"

    def get_colors(self, image=None, coords=None):
        """
        EXtract the text color by quantaizing the image i.e
        [cropped to the coordiantes] into 2 colors mainly
        background and foreground and find the closest matching
        foreground color.
        @param image: input PIL image
        @param coords: coordinates from which color needs to be
                       extracted
        @return: foreground color name
        """
        cropped_image = image.crop(coords)
        # get 2 dominant colors
        q = cropped_image.quantize(colors=2, method=2)
        dominant_color = q.getpalette()[3:6]

        colors = {
            "Attention": [
                (255, 0, 0),
                (180, 8, 0),
                (220, 54, 45),
                (194, 25, 18),
                (143, 7, 0)
            ],
            "Accent": [
                (0, 0, 255),
                (7, 47, 95),
                (18, 97, 160),
                (56, 149, 211)
            ],
            "Good": [
                (0, 128, 0),
                (145, 255, 0),
                (30, 86, 49),
                (164, 222, 2),
                (118, 186, 27),
                (76, 154, 42),
                (104, 187, 89)
            ],
            "Dark": [
                (0, 0, 0),
                (76, 76, 76),
                (51, 51, 51),
                (102, 102, 102),
                (153, 153, 153)
            ],
            "Light": [
                (255, 255, 255)
            ],
            "Warning": [
                (255, 255, 0),
                (255, 170, 0),
                (184, 134, 11),
                (218, 165, 32),
                (234, 186, 61),
                (234, 162, 33)
            ]
        }
        color = "Default"
        found_colors = []
        distances = []
        # find the dominant text colors based on the RGB difference
        for key, values in colors.items():
            for value in values:
                distance = np.sqrt(np.sum(
                    (np.asarray(value) - np.asarray(dominant_color)) ** 2))
                if distance <= 150:
                    found_colors.append(key)
                    distances.append(distance)
        # If the color is predicted as LIGHT check for false cases
        # where both dominan colors are White
        if found_colors:
            index = distances.index(min(distances))
            color = found_colors[index]
            if found_colors[index] == "Light":
                background = q.getpalette()[:3]
                foreground = q.getpalette()[3:6]
                distance = np.sqrt(
                    np.sum(
                        (np.asarray(background) -
                         np.asarray(foreground)) ** 2))
                if distance < 150:
                    color = "Default"
        return color

    def get_column_width_keys(self, default_config: Dict, ratio: Tuple,
                              column_set: Dict, column_number: int) -> None:
        """
        Extract the column width key from the default config which is minimum
        in distance with the given point / ratio
        @param default_config: default host config dict for the column width
        @param ratio: the point derived from the column coordinates
        @param column_set: dict of columns
        @param column_number: the position of the column
        """
        keys = list(default_config.keys())
        distances = [np.sqrt(np.sum(((np.asarray(ratio) -
                                      np.asarray(tuple(point))) ** 2)))
                     for point in keys]
        key = keys[distances.index(min(distances))]
        column_set["columns"][column_number]["width"] = default_config[key]

    def extract_column_width(self, column_set: Dict,
                             column_coords: List[List], image: Image) -> None:
        """
        Extract column width property for the given columnset based on the
        mid point distance between 2 design objects.
        @param column_set: list of column design objects
        @param column_coords: each column's coordinate values of a column set
        @param image: input PIL image
        """
        column_xmin, column_ymin, column_xmax, column_ymax = column_coords
        for ctr, column in enumerate(column_set["columns"]):
            if ctr + 1 < len(column_set["columns"]):
                mid_point1 = np.asarray(
                    ((column_xmin[ctr] + column_xmax[ctr])/2,
                     (column_ymin[ctr] + column_ymax[ctr])/2))
                mid_point2 = np.asarray(
                    ((column_xmin[ctr+1] + column_xmax[ctr+1]) / 2,
                     (column_ymin[ctr+1] + column_ymax[ctr+1]) / 2))

                a = np.asarray((column_xmin[ctr], column_ymin[ctr]))
                b = np.asarray((column_xmax[ctr+1], column_ymax[ctr+1]))
                end_distance = np.sqrt(np.sum(((a - b) ** 2)))
                mid_distance = np.sqrt(np.sum(((mid_point1 - mid_point2)
                                               ** 2)))
                mid_distance = (mid_distance / end_distance) * 100
                ratio = (1, mid_distance)
                self.get_column_width_keys(
                    config.COLUMN_WIDTH_DISTANCE, ratio,
                    column_set, ctr)
            if ctr == len(column_set["columns"]) - 1:
                w, h = image.size
                last_diff = (abs(column_xmax[ctr] - w) / w) * 100
                ratio = (1, last_diff)
                self.get_column_width_keys(
                    config.LAST_COLUMN_THRESHOLD, ratio,
                    column_set, ctr)

    def extract_image_size(self, cropped_image: Image,
                           pil_image: Image) -> str:
        """
        Returns the image size value based on the width and height ratios
        of the image objects to the actual design image.
        @param cropped_image: image object
        @param pil_image: input design image
        @return: image width value
        """
        img_width, img_height = cropped_image.size
        width, height = pil_image.size
        width_ratio = (img_width / width) * 100
        height_ratio = (img_height / height) * 100
        # if the width and height ratio differs more the 25% return the size as
        # Auto
        if abs(width_ratio - height_ratio) > 20:
            return "Auto"
        else:
            # select the image size based on the minimum distance with
            # the default host config values for image size
            keys = list(config.IMAGE_SIZE_RATIOS.keys())
            ratio = (width_ratio, height_ratio)
            distances = [np.sqrt(np.sum(((np.asarray(ratio) -
                                          np.asarray(tuple(point))) ** 2)))
                         for point in keys]
            key = keys[distances.index(min(distances))]
            return config.IMAGE_SIZE_RATIOS[key]


class CollectProperties(ExtractProperties):
    """
    Helps to collect the properties for respective design object.
    """

    def __init__(self, image=None):
        self.pil_imgae = image

    def column(self, columns: Dict):
        """
        Updates the horizontal alignment property for the columns,
        based on the horizontal alignment of each items inside the column
        @param columns: List of columns  [ for a columnset ]
        """
        for column in columns:
            alignment = list(map(operator.itemgetter('horizontalAlignment'),
                                 column["items"]))
            alignment = max(alignment, key=alignment.count)
            column.update({"horizontalAlignment": alignment})

    def columnset(self, columnset: Dict, column_coords: List[List],
                  image: Image):
        """
        Updates the horizontal alignment property for the columnset,
        based on the horizontal alignment of each column inside the columnset.
        @param columnset: Columnset dict
        @param image: input PIL image
        @param column_coords: each column's coordinates values of a column set
        """
        alignment = list(map(operator.itemgetter('horizontalAlignment'),
                             columnset["columns"]))
        alignment = max(alignment, key=alignment.count)
        columnset.update({"horizontalAlignment": alignment})
        self.extract_column_width(columnset, column_coords, image)

    def actionset(self, coords: Tuple) -> Dict:
        """
        Returns the actionset properties of the extracted design object
        @return: property object
        """
        return {
            "horizontal_alignment": self.get_alignment(
                image=self.pil_imgae,
                xmin=coords[0],
                xmax=coords[2]
            ),
            "data": self.get_text(image=self.pil_imgae, coords=coords),
            "style": self.get_actionset_type(
                image=self.pil_imgae,
                coords=coords
            )
        }

    def textbox(self, coords: Tuple) -> Dict:
        """
        Returns the textbox properties of the extracted design object
        @return: property object
        """
        size, weight = self.get_size_and_weight(image=self.pil_imgae,
                                                coords=coords)
        return {
            "horizontal_alignment": self.get_alignment(
                image=self.pil_imgae,
                xmin=coords[0],
                xmax=coords[2]
            ),
            "data": self.get_text(image=self.pil_imgae, coords=coords),
            "size": size,
            "weight": weight,
            "color": self.get_colors(image=self.pil_imgae, coords=coords)

        }

    def radiobutton(self, coords: Tuple) -> Dict:
        """
        Returns the radiobutton properties of the extracted design object
        @return: property object
        """
        return {
            "horizontal_alignment": self.get_alignment(
                image=self.pil_imgae,
                xmin=coords[0],
                xmax=coords[2]
            ),
            "data": self.get_text(image=self.pil_imgae, coords=coords),
        }

    def checkbox(self, coords: Tuple) -> Dict:
        """
        Returns the checkbox properties of the extracted design object
        @return: property object
        """
        return {
            "horizontal_alignment": self.get_alignment(
                image=self.pil_imgae,
                xmin=coords[0],
                xmax=coords[2]
            ),
            "data": self.get_text(image=self.pil_imgae, coords=coords),
        }

    def image(self, coords: Tuple) -> Dict:
        """
        Returns the image properties of the extracted design object
        @return: property object
        """
        cropped = self.pil_imgae.crop(coords)
        buff = BytesIO()
        cropped.save(buff, format="PNG")
        base64_string = base64.b64encode(
            buff.getvalue()).decode()
        data = f'data:image/png;base64,{base64_string}'

        size = self.extract_image_size(cropped, self.pil_imgae)
        return {
            "horizontal_alignment": self.get_alignment(
                image=self.pil_imgae,
                xmin=coords[0],
                xmax=coords[2]
            ),
            "data": data,
            "size": size
        }
