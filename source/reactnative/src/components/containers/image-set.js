/**
 * ImageSet Component.
 * 
 * Refer https://docs.microsoft.com/en-us/adaptive-cards/authoring-cards/card-schema#schema-imageset
 */

import React, { PureComponent } from "react";
import { View, ScrollView, Text, StyleSheet, Button, Platform } from 'react-native';
import { Registry } from '../registration/registry'
import Input from '../inputs/input';
import * as Constants from '../../utils/constants';

const FlexWrap = 'wrap';
const SizeKey = "size";
const ImageSetKey = "fromImageSet";

export class ImageSet extends PureComponent {
    
    constructor(props) {
        super(props);
        
        this.renderedElement = [];
        this.payload = props.json;
    }

    /**
     * 
     * @description Parse the given payload and render the card accordingly
     */
    parsePayload = (imageSetJson,onParseError) => {
        if (!this.payload)
            return this.renderedElement;

        const register = new Registry();
        // parse elements 
        // TODO: This function is repetitive across containers. Needs to be made Generic.
        imageSetJson.images.map((element, index) => {
            element[SizeKey] = this.payload.imageSize;
            element[ImageSetKey] = true;
            const Element = register.getComponentOfType(element.type);
            if (Element) {
                this.renderedElement.push(<Element json={element} 
                    key={`ELEMENT-${this.generateNumber()}`} />);
            } else {
                let error = {"type":"ParseError", "error": "Unknown Type encountered"};        
                onParseError(error);
              return null;
            }
        });
        return this.renderedElement;
    }

    /**
     * @description Generates a random number
     */
    generateNumber = () => {
        min = 1;
        max = 100000;
        const rndNum = Math.floor(Math.random() * (max - min + 1) + min)
        return rndNum
    };

    internalRenderer(imageSetJson) {
        return (
                <Input json={imageSetJson} style={[styles.container, styles.defaultBGStyle]}>
                    {this.parsePayload(imageSetJson)}
                </Input>
        );
    }

    render() {
        let containerRender = this.internalRenderer(this.props.json);
        return containerRender;
    }
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
        flexDirection: Constants.FlexRow,
        flexWrap: FlexWrap,
    },
    defaultBGStyle: {
        backgroundColor: Constants.TransparentString,
    },
});