/**
 * InputText Component.
 * 
 * Refer https://docs.microsoft.com/en-us/adaptive-cards/authoring-cards/card-schema#inputtext
 */

import React from "react";
import { StyleSheet, TextInput } from 'react-native';
import Input from './input';
import { StyleManager } from "../../styles/style-config";
import * as Utils from '../../utils/util';
import * as Enums from '../../utils/enums';
import * as Constants from '../../utils/constants';
import { InputContextConsumer } from '../../utils/context'
import { HostConfigManager } from '../../utils/host-config'

const EMAIL_REGEX = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
const URL_REGEX = /((([A-Za-z]{3,9}:(?:\/\/)?)(?:[\-;:&=\+\$,\w]+@)?[A-Za-z0-9\.\-]+|(?:www\.|[\-;:&=\+\$,\w]+@)[A-Za-z0-9\.\-]+)((?:\/[\+~%\/\.\w\-_]*)?\??(?:[\-\+=&;%@\.\w_]*)#?(?:[\.\!\/\\\w]*))?)/;
const TEL_REGEX = /^[2-9]\d{2}[2-9]\d{2}\d{4}$/;

export class InputText extends React.Component {

    styleConfig = StyleManager.getManager().styles;

    constructor(props) {
        super(props);

        this.payload = props.json;
        this.id = Constants.EmptyString;
        this.isMultiline = Boolean;
        this.maxlength = 0;
        this.placeHolder = Constants.EmptyString;
        this.style = Constants.EmptyString;
        this.type = Constants.EmptyString;
        this.value = Constants.EmptyString;
        this.keyboardType = Constants.EmptyString;
        this.state = {
            isError: false,
            text: '',
        }
    }

    /**
     * @description Invoked on every change in Input field
     * @param {string} text
     */
    textValueChanged = (text, addInputItem) => {
        this.setState({ text });
        addInputItem(this.id, text);
    }

    render() {

        if (HostConfigManager.getHostConfig().supportsInteractivity === false) {
            let error = {
                "error": Error.ValidationError.InteractivityNotAllowed,
                "message": `Interactivity is not allowed based on schema`
            };
            onParseError(error);

            return null;
        }

        this.parseHostConfig();

        const {
            id,
            type,
            isMultiline,
            placeholder,
            maxLength,
            style,
            keyboardType
        } = this;

        if (!id || !type) {
            return null;
        }

        return (
            <InputContextConsumer>
                {({ addInputItem }) => (
                    <Input json={this.payload}>
                        <TextInput
                            style={this.getComputedStyles()}
                            autoCapitalize={Constants.NoneString}
                            autoCorrect={false}
                            placeholder={placeholder}
                            multiline={isMultiline}
                            maxLength={maxLength}
                            underlineColorAndroid={Constants.TransparentString}
                            clearButtonMode={Constants.WhileEditingString}
                            textContentType={style}
                            keyboardType={keyboardType}
                            onFocus={this.handleFocus}
                            onBlur={this.handleBlur}
                            onChangeText={(text) => { this.textValueChanged(text, addInputItem) }}
                            value={this.state.text}
                        />
                    </Input>
                )}
            </InputContextConsumer>
        );
    }

    /**
     * @description Return the input styles applicable based on the given payload
     */
    getComputedStyles = () => {
        const { isMultiline } = this;

        let inputComputedStyles = [styles.input, this.styleConfig.fontConfig];
        isMultiline ?
            inputComputedStyles.push(styles.multiLineHeight) :
            inputComputedStyles.push(styles.singleLineHeight);
        this.state.isError ?
            inputComputedStyles.push(this.styleConfig.borderAttention) :
            inputComputedStyles.push(styles.withBorderColor);

        return inputComputedStyles;
    }

    /**
     * @description validate the text in the textinput field based on style of the textinput.
     */
    validate = () => {
        let isError = true;
        let REGEX;
        let text = this.state.text;

        if (text === Constants.EmptyString) {
            isError = false;
        }
        else {
            switch (this.style) {
                case Enums.InputTextStyle.Email: {
                    REGEX = EMAIL_REGEX;
                }
                    break;
                case Enums.InputTextStyle.Url: {
                    REGEX = URL_REGEX;
                }
                    break;
                case Enums.InputTextStyle.Tel: {
                    REGEX = TEL_REGEX;
                    text = text.replace(/\D/g, Constants.EmptyString);
                }
                    break;
            }

            if (REGEX) {
                isError = !REGEX.test(text);
            }
        }
        this.setState({ isError });
    };

    /**
     * @description Parse hostconfig specific to this element
     */
    parseHostConfig = () => {
        this.id = this.payload.id;
        this.type = this.payload.type;
        this.isMultiline = this.payload.isMultiline;
        this.maxLength = this.payload.maxLength;
        this.placeholder = this.payload.placeholder;
        let styleValue = Utils.parseHostConfigEnum(
            Enums.InputTextStyle,
            this.payload.style,
            Enums.InputTextStyle.Text);
        this.style = Utils.getEffectiveInputStyle(styleValue);
        this.keyboardType = Utils.getKeyboardType(styleValue);
    }

    /**
     * @description handle textinput when in focus
     */
    handleFocus = () => {
        this.setState({
            isError: false
        });
    }

    /**
     * @description handle textinput when out of focus
     */
    handleBlur = () => {
        this.validate();
    }
}

const styles = StyleSheet.create({
    withBorderColor: {
        borderColor: Constants.LightGreyColor,
    },
    multiLineHeight: {
        height: 88,
    },
    singleLineHeight: {
        height: 44,
    },
    input: {
        width: Constants.FullWidth,
        padding: 5,
        marginTop: 15,
        borderWidth: 1,
        backgroundColor: Constants.WhiteColor,
        borderRadius: 5,
    },
});


