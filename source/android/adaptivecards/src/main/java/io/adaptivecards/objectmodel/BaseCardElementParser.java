/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.2
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package io.adaptivecards.objectmodel;

public class BaseCardElementParser {
  private transient long swigCPtr;
  private transient boolean swigCMemOwn;

  protected BaseCardElementParser(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(BaseCardElementParser obj) {
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
        AdaptiveCardObjectModelJNI.delete_BaseCardElementParser(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  protected void swigDirectorDisconnect() {
    swigSetCMemOwn(false);
    delete();
  }

  public void swigReleaseOwnership() {
    swigSetCMemOwn(false);
    AdaptiveCardObjectModelJNI.BaseCardElementParser_change_ownership(this, swigCPtr, false);
  }

  public void swigTakeOwnership() {
    swigSetCMemOwn(true);
    AdaptiveCardObjectModelJNI.BaseCardElementParser_change_ownership(this, swigCPtr, true);
  }

  public BaseCardElement Deserialize(ParseContext context, JsonValue value) {
    long cPtr = AdaptiveCardObjectModelJNI.BaseCardElementParser_Deserialize(swigCPtr, this, ParseContext.getCPtr(context), context, JsonValue.getCPtr(value), value);
    return (cPtr == 0) ? null : new BaseCardElement(cPtr, true);
  }

  public BaseCardElement DeserializeFromString(ParseContext context, String value) {
    long cPtr = AdaptiveCardObjectModelJNI.BaseCardElementParser_DeserializeFromString(swigCPtr, this, ParseContext.getCPtr(context), context, value);
    return (cPtr == 0) ? null : new BaseCardElement(cPtr, true);
  }

  public BaseCardElementParser() {
    this(AdaptiveCardObjectModelJNI.new_BaseCardElementParser(), true);
    AdaptiveCardObjectModelJNI.BaseCardElementParser_director_connect(this, swigCPtr, true, true);
  }

}
