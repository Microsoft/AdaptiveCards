/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.0
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package io.adaptivecards.objectmodel;

public class ShowCardAction extends BaseActionElement {
  private transient long swigCPtr;
  private transient boolean swigCMemOwnDerived;

  protected ShowCardAction(long cPtr, boolean cMemoryOwn) {
    super(AdaptiveCardObjectModelJNI.ShowCardAction_SWIGSmartPtrUpcast(cPtr), true);
    swigCMemOwnDerived = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(ShowCardAction obj) {
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
        AdaptiveCardObjectModelJNI.delete_ShowCardAction(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public ShowCardAction() {
    this(AdaptiveCardObjectModelJNI.new_ShowCardAction__SWIG_0(), true);
  }

  public ShowCardAction(ShowCardAction arg0) {
    this(AdaptiveCardObjectModelJNI.new_ShowCardAction__SWIG_1(ShowCardAction.getCPtr(arg0), arg0), true);
  }

  public JsonValue SerializeToJsonValue() {
    return new JsonValue(AdaptiveCardObjectModelJNI.ShowCardAction_SerializeToJsonValue(swigCPtr, this), true);
  }

  public AdaptiveCard GetCard() {
    long cPtr = AdaptiveCardObjectModelJNI.ShowCardAction_GetCard(swigCPtr, this);
    return (cPtr == 0) ? null : new AdaptiveCard(cPtr, true);
  }

  public void SetCard(AdaptiveCard arg0) {
    AdaptiveCardObjectModelJNI.ShowCardAction_SetCard(swigCPtr, this, AdaptiveCard.getCPtr(arg0), arg0);
  }

  public void SetLanguage(String value) {
    AdaptiveCardObjectModelJNI.ShowCardAction_SetLanguage(swigCPtr, this, value);
  }

  public void GetResourceInformation(RemoteResourceInformationVector resourceInfo) {
    AdaptiveCardObjectModelJNI.ShowCardAction_GetResourceInformation(swigCPtr, this, RemoteResourceInformationVector.getCPtr(resourceInfo), resourceInfo);
  }

  public static ShowCardAction dynamic_cast(BaseActionElement baseActionElement) {
    long cPtr = AdaptiveCardObjectModelJNI.ShowCardAction_dynamic_cast(BaseActionElement.getCPtr(baseActionElement), baseActionElement);
    return (cPtr == 0) ? null : new ShowCardAction(cPtr, true);
  }

}
