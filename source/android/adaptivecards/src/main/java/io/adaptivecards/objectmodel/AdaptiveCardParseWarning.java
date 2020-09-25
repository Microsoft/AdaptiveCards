/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.2
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package io.adaptivecards.objectmodel;

public class AdaptiveCardParseWarning {
  private transient long swigCPtr;
  private transient boolean swigCMemOwn;

  protected AdaptiveCardParseWarning(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(AdaptiveCardParseWarning obj) {
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
        AdaptiveCardObjectModelJNI.delete_AdaptiveCardParseWarning(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public AdaptiveCardParseWarning(WarningStatusCode statusCode, String message) {
    this(AdaptiveCardObjectModelJNI.new_AdaptiveCardParseWarning(statusCode.swigValue(), message), true);
  }

  public WarningStatusCode GetStatusCode() {
    return WarningStatusCode.swigToEnum(AdaptiveCardObjectModelJNI.AdaptiveCardParseWarning_GetStatusCode(swigCPtr, this));
  }

  public String GetReason() {
    return AdaptiveCardObjectModelJNI.AdaptiveCardParseWarning_GetReason(swigCPtr, this);
  }

}
