/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.0
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package io.adaptivecards.objectmodel;

public class HostConfig {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected HostConfig(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(HostConfig obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        AdaptiveCardObjectModelJNI.delete_HostConfig(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public HostConfig() {
    this(AdaptiveCardObjectModelJNI.new_HostConfig(), true);
  }

  public static HostConfig Deserialize(JsonValue json) {
    return new HostConfig(AdaptiveCardObjectModelJNI.HostConfig_Deserialize(JsonValue.getCPtr(json), json), true);
  }

  public static HostConfig DeserializeFromString(String jsonString) {
    return new HostConfig(AdaptiveCardObjectModelJNI.HostConfig_DeserializeFromString(jsonString), true);
  }

  public FontTypeDefinition GetFontType(FontType fontType) {
    return new FontTypeDefinition(AdaptiveCardObjectModelJNI.HostConfig_GetFontType(swigCPtr, this, fontType.swigValue()), true);
  }

  public String GetFontFamily(FontType fontType) {
    return AdaptiveCardObjectModelJNI.HostConfig_GetFontFamily__SWIG_0(swigCPtr, this, fontType.swigValue());
  }

  public long GetFontSize(FontType fontType, TextSize size) {
    return AdaptiveCardObjectModelJNI.HostConfig_GetFontSize(swigCPtr, this, fontType.swigValue(), size.swigValue());
  }

  public long GetFontWeight(FontType fontType, TextWeight weight) {
    return AdaptiveCardObjectModelJNI.HostConfig_GetFontWeight(swigCPtr, this, fontType.swigValue(), weight.swigValue());
  }

  public String GetBackgroundColor(ContainerStyle style) {
    return AdaptiveCardObjectModelJNI.HostConfig_GetBackgroundColor(swigCPtr, this, style.swigValue());
  }

  public String GetForegroundColor(ContainerStyle style, ForegroundColor color, boolean isSubtle) {
    return AdaptiveCardObjectModelJNI.HostConfig_GetForegroundColor(swigCPtr, this, style.swigValue(), color.swigValue(), isSubtle);
  }

  public String GetHighlightColor(ContainerStyle style, ForegroundColor color, boolean isSubtle) {
    return AdaptiveCardObjectModelJNI.HostConfig_GetHighlightColor(swigCPtr, this, style.swigValue(), color.swigValue(), isSubtle);
  }

  public String GetBorderColor(ContainerStyle style) {
    return AdaptiveCardObjectModelJNI.HostConfig_GetBorderColor(swigCPtr, this, style.swigValue());
  }

  public long GetBorderThickness(ContainerStyle style) {
    return AdaptiveCardObjectModelJNI.HostConfig_GetBorderThickness(swigCPtr, this, style.swigValue());
  }

  public String GetFontFamily() {
    return AdaptiveCardObjectModelJNI.HostConfig_GetFontFamily__SWIG_1(swigCPtr, this);
  }

  public void SetFontFamily(String value) {
    AdaptiveCardObjectModelJNI.HostConfig_SetFontFamily(swigCPtr, this, value);
  }

  public FontSizesConfig GetFontSizes() {
    return new FontSizesConfig(AdaptiveCardObjectModelJNI.HostConfig_GetFontSizes(swigCPtr, this), true);
  }

  public void SetFontSizes(FontSizesConfig value) {
    AdaptiveCardObjectModelJNI.HostConfig_SetFontSizes(swigCPtr, this, FontSizesConfig.getCPtr(value), value);
  }

  public FontWeightsConfig GetFontWeights() {
    return new FontWeightsConfig(AdaptiveCardObjectModelJNI.HostConfig_GetFontWeights(swigCPtr, this), true);
  }

  public void SetFontWeights(FontWeightsConfig value) {
    AdaptiveCardObjectModelJNI.HostConfig_SetFontWeights(swigCPtr, this, FontWeightsConfig.getCPtr(value), value);
  }

  public FontTypesDefinition GetFontTypes() {
    return new FontTypesDefinition(AdaptiveCardObjectModelJNI.HostConfig_GetFontTypes(swigCPtr, this), true);
  }

  public void SetFontTypes(FontTypesDefinition value) {
    AdaptiveCardObjectModelJNI.HostConfig_SetFontTypes(swigCPtr, this, FontTypesDefinition.getCPtr(value), value);
  }

  public boolean GetSupportsInteractivity() {
    return AdaptiveCardObjectModelJNI.HostConfig_GetSupportsInteractivity(swigCPtr, this);
  }

  public void SetSupportsInteractivity(boolean value) {
    AdaptiveCardObjectModelJNI.HostConfig_SetSupportsInteractivity(swigCPtr, this, value);
  }

  public String GetImageBaseUrl() {
    return AdaptiveCardObjectModelJNI.HostConfig_GetImageBaseUrl(swigCPtr, this);
  }

  public void SetImageBaseUrl(String value) {
    AdaptiveCardObjectModelJNI.HostConfig_SetImageBaseUrl(swigCPtr, this, value);
  }

  public ImageSizesConfig GetImageSizes() {
    return new ImageSizesConfig(AdaptiveCardObjectModelJNI.HostConfig_GetImageSizes(swigCPtr, this), true);
  }

  public void SetImageSizes(ImageSizesConfig value) {
    AdaptiveCardObjectModelJNI.HostConfig_SetImageSizes(swigCPtr, this, ImageSizesConfig.getCPtr(value), value);
  }

  public ImageConfig GetImage() {
    return new ImageConfig(AdaptiveCardObjectModelJNI.HostConfig_GetImage(swigCPtr, this), true);
  }

  public void SetImage(ImageConfig value) {
    AdaptiveCardObjectModelJNI.HostConfig_SetImage(swigCPtr, this, ImageConfig.getCPtr(value), value);
  }

  public SeparatorConfig GetSeparator() {
    return new SeparatorConfig(AdaptiveCardObjectModelJNI.HostConfig_GetSeparator(swigCPtr, this), true);
  }

  public void SetSeparator(SeparatorConfig value) {
    AdaptiveCardObjectModelJNI.HostConfig_SetSeparator(swigCPtr, this, SeparatorConfig.getCPtr(value), value);
  }

  public SpacingConfig GetSpacing() {
    return new SpacingConfig(AdaptiveCardObjectModelJNI.HostConfig_GetSpacing(swigCPtr, this), true);
  }

  public void SetSpacing(SpacingConfig value) {
    AdaptiveCardObjectModelJNI.HostConfig_SetSpacing(swigCPtr, this, SpacingConfig.getCPtr(value), value);
  }

  public AdaptiveCardConfig GetAdaptiveCard() {
    return new AdaptiveCardConfig(AdaptiveCardObjectModelJNI.HostConfig_GetAdaptiveCard(swigCPtr, this), true);
  }

  public void SetAdaptiveCard(AdaptiveCardConfig value) {
    AdaptiveCardObjectModelJNI.HostConfig_SetAdaptiveCard(swigCPtr, this, AdaptiveCardConfig.getCPtr(value), value);
  }

  public ImageSetConfig GetImageSet() {
    return new ImageSetConfig(AdaptiveCardObjectModelJNI.HostConfig_GetImageSet(swigCPtr, this), true);
  }

  public void SetImageSet(ImageSetConfig value) {
    AdaptiveCardObjectModelJNI.HostConfig_SetImageSet(swigCPtr, this, ImageSetConfig.getCPtr(value), value);
  }

  public FactSetConfig GetFactSet() {
    return new FactSetConfig(AdaptiveCardObjectModelJNI.HostConfig_GetFactSet(swigCPtr, this), true);
  }

  public void SetFactSet(FactSetConfig value) {
    AdaptiveCardObjectModelJNI.HostConfig_SetFactSet(swigCPtr, this, FactSetConfig.getCPtr(value), value);
  }

  public ActionsConfig GetActions() {
    return new ActionsConfig(AdaptiveCardObjectModelJNI.HostConfig_GetActions(swigCPtr, this), true);
  }

  public void SetActions(ActionsConfig value) {
    AdaptiveCardObjectModelJNI.HostConfig_SetActions(swigCPtr, this, ActionsConfig.getCPtr(value), value);
  }

  public ContainerStylesDefinition GetContainerStyles() {
    return new ContainerStylesDefinition(AdaptiveCardObjectModelJNI.HostConfig_GetContainerStyles(swigCPtr, this), true);
  }

  public void SetContainerStyles(ContainerStylesDefinition value) {
    AdaptiveCardObjectModelJNI.HostConfig_SetContainerStyles(swigCPtr, this, ContainerStylesDefinition.getCPtr(value), value);
  }

  public MediaConfig GetMedia() {
    return new MediaConfig(AdaptiveCardObjectModelJNI.HostConfig_GetMedia(swigCPtr, this), true);
  }

  public void SetMedia(MediaConfig value) {
    AdaptiveCardObjectModelJNI.HostConfig_SetMedia(swigCPtr, this, MediaConfig.getCPtr(value), value);
  }

}
