/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.2
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package io.adaptivecards.objectmodel;

public class StdOptionalForegroundColor {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected StdOptionalForegroundColor(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(StdOptionalForegroundColor obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  @SuppressWarnings("deprecation")
  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        AdaptiveCardObjectModelJNI.delete_StdOptionalForegroundColor(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public StdOptionalForegroundColor() {
    this(AdaptiveCardObjectModelJNI.new_StdOptionalForegroundColor__SWIG_0(), true);
  }

  public StdOptionalForegroundColor(ForegroundColor arg0) {
    this(AdaptiveCardObjectModelJNI.new_StdOptionalForegroundColor__SWIG_1(arg0.swigValue()), true);
  }

  public boolean has_value() {
    return AdaptiveCardObjectModelJNI.StdOptionalForegroundColor_has_value(swigCPtr, this);
  }

  public ForegroundColor value() {
    return ForegroundColor.swigToEnum(AdaptiveCardObjectModelJNI.StdOptionalForegroundColor_value(swigCPtr, this));
  }

}
