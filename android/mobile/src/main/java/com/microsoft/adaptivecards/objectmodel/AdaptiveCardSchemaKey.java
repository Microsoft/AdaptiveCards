/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.12
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.microsoft.adaptivecards.objectmodel;

public final class AdaptiveCardSchemaKey {
  public final static AdaptiveCardSchemaKey Size = new AdaptiveCardSchemaKey("Size", AdaptiveCardObjectModelJNI.AdaptiveCardSchemaKey_Size_get());
  public final static AdaptiveCardSchemaKey TextSize = new AdaptiveCardSchemaKey("TextSize");
  public final static AdaptiveCardSchemaKey TextWeight = new AdaptiveCardSchemaKey("TextWeight");
  public final static AdaptiveCardSchemaKey TextWrap = new AdaptiveCardSchemaKey("TextWrap");
  public final static AdaptiveCardSchemaKey TextColor = new AdaptiveCardSchemaKey("TextColor");
  public final static AdaptiveCardSchemaKey HorizontalAlignment = new AdaptiveCardSchemaKey("HorizontalAlignment");
  public final static AdaptiveCardSchemaKey ImageStyle = new AdaptiveCardSchemaKey("ImageStyle");
  public final static AdaptiveCardSchemaKey CardElement = new AdaptiveCardSchemaKey("CardElement");
  public final static AdaptiveCardSchemaKey Text = new AdaptiveCardSchemaKey("Text");
  public final static AdaptiveCardSchemaKey Speak = new AdaptiveCardSchemaKey("Speak");
  public final static AdaptiveCardSchemaKey Type = new AdaptiveCardSchemaKey("Type");

  public final int swigValue() {
    return swigValue;
  }

  public String toString() {
    return swigName;
  }

  public static AdaptiveCardSchemaKey swigToEnum(int swigValue) {
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (int i = 0; i < swigValues.length; i++)
      if (swigValues[i].swigValue == swigValue)
        return swigValues[i];
    throw new IllegalArgumentException("No enum " + AdaptiveCardSchemaKey.class + " with value " + swigValue);
  }

  private AdaptiveCardSchemaKey(String swigName) {
    this.swigName = swigName;
    this.swigValue = swigNext++;
  }

  private AdaptiveCardSchemaKey(String swigName, int swigValue) {
    this.swigName = swigName;
    this.swigValue = swigValue;
    swigNext = swigValue+1;
  }

  private AdaptiveCardSchemaKey(String swigName, AdaptiveCardSchemaKey swigEnum) {
    this.swigName = swigName;
    this.swigValue = swigEnum.swigValue;
    swigNext = this.swigValue+1;
  }

  private static AdaptiveCardSchemaKey[] swigValues = { Size, TextSize, TextWeight, TextWrap, TextColor, HorizontalAlignment, ImageStyle, CardElement, Text, Speak, Type };
  private static int swigNext = 0;
  private final int swigValue;
  private final String swigName;
}

