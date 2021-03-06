/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.2
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package io.adaptivecards.objectmodel;

public class TextElementProperties {
  private transient long swigCPtr;
  private transient boolean swigCMemOwn;

  protected TextElementProperties(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(TextElementProperties obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void swigSetCMemOwn(boolean own) {
    swigCMemOwn = own;
  }

  @SuppressWarnings("deprecation")
  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        AdaptiveCardObjectModelJNI.delete_TextElementProperties(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public TextElementProperties() {
    this(AdaptiveCardObjectModelJNI.new_TextElementProperties__SWIG_0(), true);
  }

  public TextElementProperties(TextStyleConfig arg0, String arg1, String arg2) {
    this(AdaptiveCardObjectModelJNI.new_TextElementProperties__SWIG_1(TextStyleConfig.getCPtr(arg0), arg0, arg1, arg2), true);
  }

  public TextElementProperties(TextElementProperties arg0) {
    this(AdaptiveCardObjectModelJNI.new_TextElementProperties__SWIG_2(TextElementProperties.getCPtr(arg0), arg0), true);
  }

  public JsonValue SerializeToJsonValue(JsonValue root) {
    return new JsonValue(AdaptiveCardObjectModelJNI.TextElementProperties_SerializeToJsonValue(swigCPtr, this, JsonValue.getCPtr(root), root), true);
  }

  public String GetText() {
    return AdaptiveCardObjectModelJNI.TextElementProperties_GetText(swigCPtr, this);
  }

  public void SetText(String value) {
    AdaptiveCardObjectModelJNI.TextElementProperties_SetText(swigCPtr, this, value);
  }

  public DateTimePreparser GetTextForDateParsing() {
    return new DateTimePreparser(AdaptiveCardObjectModelJNI.TextElementProperties_GetTextForDateParsing(swigCPtr, this), true);
  }

  public @androidx.annotation.Nullable TextSize GetTextSize() {
    StdOptionalTextSize optvalue = new StdOptionalTextSize(AdaptiveCardObjectModelJNI.TextElementProperties_GetTextSize(swigCPtr, this), false);
    return optvalue.has_value() ? optvalue.value() : null;
  }

  public void SetTextSize(@androidx.annotation.Nullable TextSize value) {
    StdOptionalTextSize optvalue = (value == null) ? new StdOptionalTextSize() : new StdOptionalTextSize(value);
    {
      AdaptiveCardObjectModelJNI.TextElementProperties_SetTextSize(swigCPtr, this, StdOptionalTextSize.getCPtr(optvalue), optvalue);
    }
  }

  public @androidx.annotation.Nullable TextWeight GetTextWeight() {
    StdOptionalTextWeight optvalue = new StdOptionalTextWeight(AdaptiveCardObjectModelJNI.TextElementProperties_GetTextWeight(swigCPtr, this), false);
    return optvalue.has_value() ? optvalue.value() : null;
  }

  public void SetTextWeight(@androidx.annotation.Nullable TextWeight value) {
    StdOptionalTextWeight optvalue = (value == null) ? new StdOptionalTextWeight() : new StdOptionalTextWeight(value);
    {
      AdaptiveCardObjectModelJNI.TextElementProperties_SetTextWeight(swigCPtr, this, StdOptionalTextWeight.getCPtr(optvalue), optvalue);
    }
  }

  public @androidx.annotation.Nullable FontType GetFontType() {
    StdOptionalFontType optvalue = new StdOptionalFontType(AdaptiveCardObjectModelJNI.TextElementProperties_GetFontType(swigCPtr, this), false);
    return optvalue.has_value() ? optvalue.value() : null;
  }

  public void SetFontType(@androidx.annotation.Nullable FontType value) {
    StdOptionalFontType optvalue = (value == null) ? new StdOptionalFontType() : new StdOptionalFontType(value);
    {
      AdaptiveCardObjectModelJNI.TextElementProperties_SetFontType(swigCPtr, this, StdOptionalFontType.getCPtr(optvalue), optvalue);
    }
  }

  public @androidx.annotation.Nullable ForegroundColor GetTextColor() {
    StdOptionalForegroundColor optvalue = new StdOptionalForegroundColor(AdaptiveCardObjectModelJNI.TextElementProperties_GetTextColor(swigCPtr, this), false);
    return optvalue.has_value() ? optvalue.value() : null;
  }

  public void SetTextColor(@androidx.annotation.Nullable ForegroundColor value) {
    StdOptionalForegroundColor optvalue = (value == null) ? new StdOptionalForegroundColor() : new StdOptionalForegroundColor(value);
    {
      AdaptiveCardObjectModelJNI.TextElementProperties_SetTextColor(swigCPtr, this, StdOptionalForegroundColor.getCPtr(optvalue), optvalue);
    }
  }

  public @androidx.annotation.Nullable Boolean GetIsSubtle() {
    StdOptionalBool optvalue = new StdOptionalBool(AdaptiveCardObjectModelJNI.TextElementProperties_GetIsSubtle(swigCPtr, this), false);
    return optvalue.has_value() ? optvalue.value() : null;
  }

  public void SetIsSubtle(@androidx.annotation.Nullable Boolean value) {
    StdOptionalBool optvalue = (value == null) ? new StdOptionalBool() : new StdOptionalBool(value);
    {
      AdaptiveCardObjectModelJNI.TextElementProperties_SetIsSubtle(swigCPtr, this, StdOptionalBool.getCPtr(optvalue), optvalue);
    }
  }

  public void SetLanguage(String value) {
    AdaptiveCardObjectModelJNI.TextElementProperties_SetLanguage(swigCPtr, this, value);
  }

  public String GetLanguage() {
    return AdaptiveCardObjectModelJNI.TextElementProperties_GetLanguage(swigCPtr, this);
  }

  public void Deserialize(ParseContext context, JsonValue root) {
    AdaptiveCardObjectModelJNI.TextElementProperties_Deserialize(swigCPtr, this, ParseContext.getCPtr(context), context, JsonValue.getCPtr(root), root);
  }

  public void PopulateKnownPropertiesSet(SWIGTYPE_p_std__unordered_setT_std__string_t knownProperties) {
    AdaptiveCardObjectModelJNI.TextElementProperties_PopulateKnownPropertiesSet(swigCPtr, this, SWIGTYPE_p_std__unordered_setT_std__string_t.getCPtr(knownProperties));
  }

}
