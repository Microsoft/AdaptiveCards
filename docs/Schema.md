# Table of Contents

[Cards](#cards)
* [AdaptiveCard](#adaptivecard) - top level card

[Elements](#elements)
* [TextBlock](#textblock) - text element
* [Image](#image) - image element
* [TextInput](#textinput) - get text input from user    
* [ChoiceInput](#choiceinput) - get choice input from user
    * [Choice](#choice) - choice object

[Containers](#containers) 
* [Container](#container) - logical container of elements
* [ColumnGroup](#columngrup) - logical container of columns
    * [Column](#column) - container of elements
* [ImageGallery](#container) - container of Images
* [FactGroup](#factgroup) - container of facts
    * [Fact](#fact) - fact object

[Actions](#actions)
* [OpenUrlAction](#openurlaction) - defines action which opens a url either in external browser or embedded browser
* [HttpAction](#httpaction) - defines action which collects input and does raw HTTP call to arbitrary Http endpoint
* [SubmitAction](#submitaction) - defines action which collects input and sends via client appropriate mechanism (it's up to client)
* [CancelAction](#cancelaction) - defines action which resets input fields and if opened card closes the card
* [ShowCardAction](#showcardaction) - defines action which shows a card to the user



# Cards

## AdaptiveCard
AdaptiveCard is top level object which represents a card 

| Property | Type | Required | Description |
|---|---|---|---|
| **type**| string | true | **"AdaptiveCard"** |
| **body** | [CardElement](#cardelement)[] | true | The elements that are to be displayed in this container. |
| **actions** |[Action](#action)[]| false | Actions |

# Elements

## CardElement
CardElement is the base type for all elements that can be used to define an Adaptive Card

> NOTE: You cannot add an Input directly, only the derived types.

| Property | Type |  Required |Description |
|---|---|---|---|
| **size** | [Size](#size) | false | Specifies the horizontal size of the element. |
| **horizontalAlignment** | [HorizontalAlignment](#horizontalalignment) | false |Specifies how the element should be aligned horizontally within its container. |
| **speak** | [Speak](/Microsoft/AdaptiveCards/blob/master/docs/SpeechAndAdvancedCustomization.md) | false |  Specifies what should be spoken for this entire element.  This is simple text or SSML fragment |

## TextBlock 
*Extends [CardElement](#cardelement)*

The TextBlock element allows for the inclusion of text, with various font sizes, weight and color, in Adaptive Cards.

| Property | Type | Required | Description |
|---|---|---|---|
| **type**| string | true | **"TextBlock"** |
| **text** | string | true |The actual text to display |
| **textSize** | [TextSize](#textsize) | false |The size of the text |
| **textWeight** | [TextWeight](#textweight) | false |The weight of the text |
| **textColor** | [TextColor](#textcolor) | false |The color of the text |
| **isSubtle** | boolean |false | Indicates whether the color of the text should be slightly toned down to appear less prominent |
| **speak** | [Speak](/Microsoft/AdaptiveCards/blob/master/docs/SpeechAndAdvancedCustomization.md) |false | Specifies what should be spoken for this entire element.  This is simple text or SSML fragment |

## Image 

*Extends [CardElement](#cardelement)*

The Image element allows for the inclusion of images in an Adaptive Card.

| Property | Type | Required |Description |
|---|---|---|---|
| **type**| string | true | **"Image"** |
| **url** | string | true | The URL to the image. |
| **style** | [ImageStyle](#imagestyle) | false | The style in which the image is displayed. |
| **action** | [Action](#action) | false | Action to perform for a tap on this image, (this allows image to act as an action) |

## Input
*Extends [CardElement](#cardelement)*

Input is a base CardElement which describes shared properties for input to collect information from a user. 

>NOTE: You cannot add an Input directly, only the derived types.

>NOTE: You need to define an SubmitAction or HttpAction to gather the information from input and do something with it.

| Property | Type | Required | Description |
|---|---|---|---|
| **id** | string | true  | Id for the value (will be used to identify collected input when SUBMIT is clicked) |
| **title** | string | true | Title Description of the input desired|
| **value** | string | false | The initial value for a field |
| **placeholder** | string | false | Hint of expected value desired *(may be ignored by some clients)*|

### TextInput
*Extends [Input](#input)*

TextInput collects text from the user

| Property | Type | Required | Description |
|---|---|---|---|
| **type**| string | true | **"TextInput"** |
| **style**| [TextInputStyle](#textinputstyle) | false | Hint of style of input, if client doesn't support the style it will become simple text input || **isMultiline** | bool | false | true to collect multiple lines of text (default is false)|
| **maxLength** | number | false | hint of maximum length characters to collect *(may be ignored by some clients)* |
| **min** | string | false | hint of minimum value *(may be ignored by some clients)*|
| **max** | string | false | hint of maximum value *(may be ignored by some clients)* |
| **step** | number | false | hint of step value *(may be ignored by some clients)* |

## ChoiceInput
*Extends [Input](#input)*

Shows an array of Choice objects

| Property | Type | Required | Description |
|---|---|---|---|
| **type**| string | true |  **"ChoiceInput"** || **style** | [ChoiceInputStyle](#choiceinputstyle) | false | Style for choice | 
| **style**| [ChoiceInputStyle](#choiceinputstyle) | false | Hint of style of input |
| **multiSelect** | boolean | false | allow multiple choices to be selected (Default=false)|
| **choices** | Choice[] | true | the choice options |

### Choice
Represents a single Choice

| Property | Type | Required | Description |
|---|---|---|---|
| **display** | string | true  | The display text for a choice|
| **value** | string | true  | the raw value for the choice|
| **isSelected** | bool |  false |is the choice selected |

# Containers

## Container 
*Extends [CardElement](#cardelement)*

The Container is a CardElement which contains a list of CardElements that are logically grouped.

| Property | Type | Required | Description |
|---|---|---|---|
| **type**| string | true | **"Container"** |
| **items** |  [CardElement](#cardelement)[] | true | The elemenXts that are to be displayed in this container. |
| **backgroundImageUrl** | string | false | The URL of an image to be used to fill the background of the container. The image is strached horizontally so it fills the entire available width of the container, and its original aspect ratio is maintained. |
| **backgroundColor** | string | false | The color of the container's background. This can be any color, and must be expressed in the RGB format with each color component expressed as a 2 digit hexadecimal number. Example: FFFFFF for white, 000000 for black, and 8C8C8C for a shade of gray. |
| **action** | [Action](#action) | false | Action to perform for a tap on this container, (this allows entire container to act as an action) |
| **actions** | [Action](#action)[] | false | Actions associated with this container |
| **separation** | [SeparationStyle](#separationstyle) | false | visually separate this container from preiovus or pending containers |

## ColumnGroup 
*Extends [CardElement](#cardelement)*

The column group element adds the ability to have a set of Column objects.

| Property | Type | Required | Description |
|---|---|---|---|
| **type**| string | true | **"ColumnGroup"** |
| **columns** | [Column](#column)[] | true | array of columns (each a container of elements)  |

## Column
**Extends [Container](#container)**

A Column is a container which contains a list of cardElements that are logically grouped.

| Property | Type | Required |  Description |
|---|---|---|---|
| **type**| string | true |  **"Column"** |
| **weight** | string | false | The weight to apply to this column |


## ImageGallery 
*Extends [CardElement](#cardelement)*

The ImageGallery allows for the inclusion of a collection images like a photogallery.

| Property | Type | Required | Description |
|---|---|---|---|
| **type**| string | true | **"ImageGallery"** |
| **images**| [Image](#image)[] | true | Array of Image objects |
| **size** | [Size](#size) | false | Specifies the horizontal size of each image in the gallery. |

## FactGroup 
*Extends [CardElement](#cardelement)*

The FactGroup element makes it simple to display a se  ries of "facts" (e.g. name/value pairs) in a tabular form.

| Property | Type | Required | Description |
|---|---|---|---|
| **type**| string | true | **"FactGroup"** |
| **facts** | [Fact](#fact)[] | true| The facts to be displayed. |

### Fact 
Represents one "fact" in a [FactGroup](#factgroup) element.

| Property | Type | Required | Description |
|---|---|---|---|
| **name** | string | true | The fact's name. |
| **value** | string | true |The fact's value. |
| **speak** | [Speak](/Microsoft/AdaptiveCards/blob/master/docs/SpeechAndAdvancedCustomization.md) | false | Specifies what should be spoken for this entire element.  This is simple text or SSML fragment |


# Actions
Actions define clickable targets that do something.

## Action
Base class for all actions

> NOTE: You cannot add a Action directly, you can only add derived action types

| Property | Type | Required | Description |
|---|---|---|---|
| **title** | string | true | Label for button or link that represents this action |

## OpenUrlAction
*Extends [Action](#action)*

When OpenUrlAction is invoked it will show the given url, either by launching it to an external web browser or showing in-situ 
with embedded web browser.

| Property | Type | Required | Description |
|---|---|---|---|
| **type**| string | true | **"OpenUrlAction"** |
| **url** | string | true | Default (browser) url to use  |
| **platformUrls** | [PlatformUrl](#platformurl)[] | false |  candidate array of PlatformUrls 's that can be used |

### PlatformUrl

A PlatformUrl represents a specific url appropriate for different platforms.  For example, you can target a url for the web, for iOS, for Android, etc. allowing deep
mobile linking to applications.

| Property | Type | Required| Description |
|---|---|---|---|
| **os** | string | true | platform filter, If it is "default" or missing then it will simply use browser. Other platforms are: (iOS?, Android?, ...?) |
| **url** | string | true | url to use on this platform os|

## HttpAction
*Extends [Action](#action)*

HttpAction represents the properties needed to do an Http request. All input properties are available for use via 
data binding.  Properties can be data bound to the Uri and Body properties, allowing you to send a request
to an arbitrary url.

| Property | Type | Required | Description |
|---|---|---|---|
| **type**| string | true | **"HttpAction"** |
| **url** | string | true | url to use (can have binding information) |
| **method** | string | true | Http method (Example: POST) |
| **headers** | object | false | Object which represents headers Example: { "content-type":"application/json" }  |
| **body** | string | false | content to post (can have binding information) |
| **SuccessMessage** | string | false | Message to show when success (OPTIONAL)|
| **ErrorMessage** | string | false | Message to show when failed (OPTIONAL)|

## ShowCardAction
*Extends [Action](#action)*

ShowCard defines an inline AdaptiveCard which is shown to the user when it is clicked.

| Property | Type | Required | Description |
|---|---|---|---|
| **type**| string | true | **"ShowCardAction"** |
| **card** | [AdaptiveCard](#adaptivecard) | true |inline card defining the card to be shown when this action is invoked. It is up to client to decide how to show this inline card. |

## SubmitAction
*Extends [Action](#action)*

Submit action gathers up input fields, merges with optional data field and generates event to 
client asking for data to be submitted.  It is up to the client to determine how that data is processed.
For example: With BotFramework bots the client would send an activity through the messaging medium to the bot.

| Property | Type | Required | Description |
|---|---|---|---|
| **type**| string | true | **"SubmitAction"** |
| **data** | object | false | initial data that input fields will be combined with.  This is essentially 'hidden' properties |

## CancelAction
*Extends [Action](#action)*

When CancelAction is invoked it resets any input that is in scope, and closes a card if it is part of a card which was shown via ShowCardAction.

| Property | Type | Required | Description |
|---|---|---|---|
| **type**| string | true | **"CancelAction"** |


# Enumerations
The following enumerations are used by various element types.

## Size
Controls the horizontal size (width) of element.  

| Value | Meaning |
|---|---|
| **auto** | The width of the element is optimally chosen depending on the space available in the element's container |
| **stretch** | The width of the element adjusts to match that of its container |
| **small** | Small width |
| **medium** | Medium width |
| **large** | Large width |

## HorizontalAlignment
Controls how elements are horizontally positioned within their container.

| Value | Meaning |
|---|---|
| **left** | The element is left aligned |
| **center** | The element is centered inside its container |
| **right** | The element is right aligned |

## TextSize
Controls the size of TextBlock elements.

| Value | Meaning |
|---|---|
| **small** | The smallest text size |
| **normal** | The default text size |
| **medium** | Slightly larger than normal |
| **large** | Slightly larger than medium |
| **extraLarge** | The maximum text size |

## TextWeight
Controls the weight of TextBlock elements.

| Value | Meaning |
|---|---|
| **lighter** | Lighter text (thinner stroke) |
| **normal** | The default text weight |
| **bolder** | Bolder text (wider stroke) |

## TextColor
Controls the color of TextBlock elements.

| Value | Meaning |
|---|---|
| **default** | The default color, which guarantees appropriate contrast. |
| **dark** | Forces text to be rendered in a dark color that is suitable when displayed over a light background. |
| **light** | Forces text to be rendered in a light color that is suitable when displayed over a dark background. |
| **accent** | The accent color. |
| **good** | Good (such as green) |
| **warning** | Warning (such as yellow) |
| **Attention** | Highlight as needing attechment (such as red)|

## ImageStyle
Controls the way Image elements are displayed.

| Value | Meaning |
|---|---|
| **normal** | The image is displayed within a rectangle. |
| **person** | The image is cropped to a circle, a common way to represent people photos. |

## SeparationStyle
Controls the separation style for the current container

| Value | Meaning |
|---|---|
| **before** | separate the current container from the previous container |
| **after** | separate the current container from the following container |
| **both** | separate the current container from the previous and following container |

## TextInputStyle
Style hint for [TextInput](#textinput).

| Value | Meaning |
|---|---|
| **tel** | Input is a telephone number and the client may use this information to provide optimized keyboard input for the user.|
| **url** | Input is a url and the client may use this information to provide optimized keyboard input for the user.|
| **email** | Input is a email and the client may use this information to provide optimized keyboard input for the user.|
| **password** | Input is text but should be hidden to protect the typed information in the textbox. |
| **number** | Input is a number. **min**, **max** and **step** properties expressed as numbers may be used by client to help user input number into text box.|
| **range** | Input is a range. **min**, **max** and **step** properties expressed as numbersmay be used by client to help user input a number on a range into text box|
| **date** | Input is date. **min**, **max** properties expressed as Date may be used by client to help user to select a date via a text box|
| **datetime** | Input is date and time. **min**, **max** expressed as DateTime properties may be used by client to help user to select a date and a time via a text box|
| **time**  | Input is time. **min**, **max** properties expressed as time may be used by client to help user to select a time via a text box|
| **month** | Input is month. **min**, **max** properties expressed as Date may be used by client to help user to select a month via a text box|
| **week**  | Input is week. **min**, **max** properties expressed as Date may be used by client to help user to select a week via a text box|

## ChoiceInputStyle
Style hint for [ChoiceInput](#choiceinput).

| Value | Meaning |
|---|---|
| **compact** | choices are preffered to be compactly displayed. Example: ComboBox ) |
| **expanded** | choices are preferred to be displayed for easy input. Example: Checkbox or Radio buttons) |


