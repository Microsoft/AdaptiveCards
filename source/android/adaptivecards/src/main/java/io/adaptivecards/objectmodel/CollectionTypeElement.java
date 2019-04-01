/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.0
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package io.adaptivecards.objectmodel;

public class CollectionTypeElement extends BaseCardElement {
  private transient long swigCPtr;
  private transient boolean swigCMemOwnDerived;

  protected CollectionTypeElement(long cPtr, boolean cMemoryOwn) {
    super(AdaptiveCardObjectModelJNI.CollectionTypeElement_SWIGSmartPtrUpcast(cPtr), true);
    swigCMemOwnDerived = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(CollectionTypeElement obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void swigSetCMemOwn(boolean own) {
    swigCMemOwnDerived = own;
    super.swigSetCMemOwn(own);
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwnDerived) {
        swigCMemOwnDerived = false;
        AdaptiveCardObjectModelJNI.delete_CollectionTypeElement(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public ContainerStyle GetStyle() {
    return ContainerStyle.swigToEnum(AdaptiveCardObjectModelJNI.CollectionTypeElement_GetStyle(swigCPtr, this));
  }

  public void SetStyle(ContainerStyle value) {
    AdaptiveCardObjectModelJNI.CollectionTypeElement_SetStyle(swigCPtr, this, value.swigValue());
  }

  public VerticalContentAlignment GetVerticalContentAlignment() {
    return VerticalContentAlignment.swigToEnum(AdaptiveCardObjectModelJNI.CollectionTypeElement_GetVerticalContentAlignment(swigCPtr, this));
  }

  public void SetVerticalContentAlignment(VerticalContentAlignment value) {
    AdaptiveCardObjectModelJNI.CollectionTypeElement_SetVerticalContentAlignment(swigCPtr, this, value.swigValue());
  }

  public boolean GetPadding() {
    return AdaptiveCardObjectModelJNI.CollectionTypeElement_GetPadding(swigCPtr, this);
  }

  public void SetPadding(boolean value) {
    AdaptiveCardObjectModelJNI.CollectionTypeElement_SetPadding(swigCPtr, this, value);
  }

  public boolean GetBleed() {
    return AdaptiveCardObjectModelJNI.CollectionTypeElement_GetBleed(swigCPtr, this);
  }

  public void SetBleed(boolean value) {
    AdaptiveCardObjectModelJNI.CollectionTypeElement_SetBleed(swigCPtr, this, value);
  }

  public boolean GetCanBleed() {
    return AdaptiveCardObjectModelJNI.CollectionTypeElement_GetCanBleed(swigCPtr, this);
  }

  public ContainerBleedDirection GetBleedDirection() {
    return ContainerBleedDirection.swigToEnum(AdaptiveCardObjectModelJNI.CollectionTypeElement_GetBleedDirection(swigCPtr, this));
  }

  public void ConfigForContainerStyle(ParseContext context) {
    AdaptiveCardObjectModelJNI.CollectionTypeElement_ConfigForContainerStyle(swigCPtr, this, ParseContext.getCPtr(context), context);
  }

  public void SetParentalId(InternalId id) {
    AdaptiveCardObjectModelJNI.CollectionTypeElement_SetParentalId(swigCPtr, this, InternalId.getCPtr(id), id);
  }

  public InternalId GetParentalId() {
    return new InternalId(AdaptiveCardObjectModelJNI.CollectionTypeElement_GetParentalId(swigCPtr, this), true);
  }

  public BaseActionElement GetSelectAction() {
    long cPtr = AdaptiveCardObjectModelJNI.CollectionTypeElement_GetSelectAction(swigCPtr, this);
    return (cPtr == 0) ? null : new BaseActionElement(cPtr, true);
  }

  public void SetSelectAction(BaseActionElement action) {
    AdaptiveCardObjectModelJNI.CollectionTypeElement_SetSelectAction(swigCPtr, this, BaseActionElement.getCPtr(action), action);
  }

  public BackgroundImage GetBackgroundImage() {
    long cPtr = AdaptiveCardObjectModelJNI.CollectionTypeElement_GetBackgroundImage(swigCPtr, this);
    return (cPtr == 0) ? null : new BackgroundImage(cPtr, true);
  }

  public void SetBackgroundImage(BackgroundImage value) {
    AdaptiveCardObjectModelJNI.CollectionTypeElement_SetBackgroundImage(swigCPtr, this, BackgroundImage.getCPtr(value), value);
  }

  public void DeserializeChildren(ParseContext context, JsonValue value) {
    AdaptiveCardObjectModelJNI.CollectionTypeElement_DeserializeChildren(swigCPtr, this, ParseContext.getCPtr(context), context, JsonValue.getCPtr(value), value);
  }

  public JsonValue SerializeToJsonValue() {
    return new JsonValue(AdaptiveCardObjectModelJNI.CollectionTypeElement_SerializeToJsonValue(swigCPtr, this), true);
  }

}
