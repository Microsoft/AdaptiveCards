/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.1
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package io.adaptivecards.objectmodel;

public enum WarningStatusCode {
  UnknownElementType(0),
  UnknownActionElementType,
  UnknownPropertyOnElement,
  UnknownEnumValue,
  NoRendererForType,
  InteractivityNotSupported,
  MaxActionsExceeded,
  AssetLoadFailed,
  UnsupportedSchemaVersion,
  UnsupportedMediaType,
  InvalidMediaMix,
  InvalidColorFormat,
  InvalidDimensionSpecified,
  InvalidLanguage,
  InvalidValue,
  CustomWarning,
  EmptyLabelInRequiredInput;

  public final int swigValue() {
    return swigValue;
  }

  public static WarningStatusCode swigToEnum(int swigValue) {
    WarningStatusCode[] swigValues = WarningStatusCode.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (WarningStatusCode swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + WarningStatusCode.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private WarningStatusCode() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private WarningStatusCode(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private WarningStatusCode(WarningStatusCode swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

