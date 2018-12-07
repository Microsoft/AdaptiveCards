/**
 * Render the adaptive card for the given payload.
 */

import React from 'react';
import PropTypes from 'prop-types';
import { StyleSheet, View, ScrollView,ImageBackground } from 'react-native';

import { Registry } from './components/registration/registry';
import { InputContextProvider } from './utils/context';

import { HostConfigManager } from './utils/host-config';
import * as Utils from './utils/util';

export default class AdaptiveCards extends React.Component {

  // Input elements with its identifier and value
  inputArray = {};

  constructor(props) {
    super(props);

    this.payload = props.payload;

    // hostconfig
    if (props.hostConfig) {
      HostConfigManager.setHostConfig(this.props.hostConfig);
    }
  }

  /**
   * @description Input elements present in the cards are added here with its value.
   */
  addInputItem = (key, value) => {
    this.inputArray[key] = value;
  }

  /**
   * @description Parse the given payload and render the card accordingly
   */
  parsePayload = () => {

    const renderedElement = [];
    const { body, actions } = this.payload;

    if (!body){
      return renderedElement;
    }
    else{
      renderedElement.push(Registry.getManager().parseRegistryComponents(body,this.props.onParseError));
    }

    // parse actions
    if (actions) {
      renderedElement.push(<View key="AC-CONTAINER" style={styles.actionContainer} />);
      renderedElement.push(Registry.getManager().parseRegistryComponents(actions,this.props.onParseError));
    }
    return renderedElement;
  }

  getAdaptiveCardConent() {
    var adaptiveCardContent =
      (
        <View style={styles.container}>
          <ScrollView>
            {this.parsePayload()}
          </ScrollView>
        </View>
      );

    if (!Utils.isNullOrEmpty(this.payload.backgroundImage)) {
      return (
        <ImageBackground source={{ uri: this.payload.backgroundImage }} style={styles.backgroundImage}>
          {adaptiveCardContent}
        </ImageBackground>
      );
    }
    else {
      return adaptiveCardContent;
    }
  }

  render() {
    const { addInputItem, inputArray } = this;
    const onExecuteAction = this.props.onExecuteAction;
    const isTransparent = this.payload.backgroundImage ? true : false;
    const onParseError = this.props.onParseError;

    return (

      <InputContextProvider value={{ addInputItem, inputArray, onExecuteAction, isTransparent, onParseError }}>
        {
          this.getAdaptiveCardConent()
        }
      </InputContextProvider>
    );
  }
}

// AdaptiveCards.propTypes
AdaptiveCards.propTypes = {
  payload: PropTypes.object.isRequired,
  hostConfig: PropTypes.object,
  onExecuteAction: PropTypes.func,
  onParseError: PropTypes.func
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: 'transparent',
  },
  actionContainer: {
    marginVertical: 10
  },
  backgroundImage: {
    width: "100%",
    flex: 1
  }
});

