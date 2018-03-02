/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.12
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.microsoft.adaptivecards.objectmodel;

public class ImageSetParser extends BaseCardElementParser {
  private transient long swigCPtr;
  private transient boolean swigCMemOwnDerived;

  protected ImageSetParser(long cPtr, boolean cMemoryOwn) {
    super(AdaptiveCardObjectModelJNI.ImageSetParser_SWIGSmartPtrUpcast(cPtr), true);
    swigCMemOwnDerived = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(ImageSetParser obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwnDerived) {
        swigCMemOwnDerived = false;
        AdaptiveCardObjectModelJNI.delete_ImageSetParser(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public BaseCardElement Deserialize(ElementParserRegistration elementParserRegistration, ActionParserRegistration actionParserRegistration, SWIGTYPE_p_Json__Value root) {
    long cPtr = AdaptiveCardObjectModelJNI.ImageSetParser_Deserialize(swigCPtr, this, ElementParserRegistration.getCPtr(elementParserRegistration), elementParserRegistration, ActionParserRegistration.getCPtr(actionParserRegistration), actionParserRegistration, SWIGTYPE_p_Json__Value.getCPtr(root));
    return (cPtr == 0) ? null : new BaseCardElement(cPtr, true);
  }

  public BaseCardElement DeserializeFromString(ElementParserRegistration elementParserRegistration, ActionParserRegistration actionParserRegistration, String jsonString) {
    long cPtr = AdaptiveCardObjectModelJNI.ImageSetParser_DeserializeFromString(swigCPtr, this, ElementParserRegistration.getCPtr(elementParserRegistration), elementParserRegistration, ActionParserRegistration.getCPtr(actionParserRegistration), actionParserRegistration, jsonString);
    return (cPtr == 0) ? null : new BaseCardElement(cPtr, true);
  }

  public ImageSetParser() {
    this(AdaptiveCardObjectModelJNI.new_ImageSetParser(), true);
  }

}
