/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.12
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package io.adaptivecards.objectmodel;

public class UnknownActionElementParser extends ActionElementParser {
  private transient long swigCPtr;

  protected UnknownActionElementParser(long cPtr, boolean cMemoryOwn) {
    super(AdaptiveCardObjectModelJNI.UnknownActionElementParser_SWIGUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(UnknownActionElementParser obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        AdaptiveCardObjectModelJNI.delete_UnknownActionElementParser(swigCPtr);
      }
      swigCPtr = 0;
    }
    super.delete();
  }

  public UnknownActionElementParser() {
    this(AdaptiveCardObjectModelJNI.new_UnknownActionElementParser__SWIG_0(), true);
  }

  public UnknownActionElementParser(UnknownActionElementParser arg0) {
    this(AdaptiveCardObjectModelJNI.new_UnknownActionElementParser__SWIG_1(UnknownActionElementParser.getCPtr(arg0), arg0), true);
  }

  public BaseActionElement Deserialize(ParseContext context, JsonValue root) {
    long cPtr = AdaptiveCardObjectModelJNI.UnknownActionElementParser_Deserialize(swigCPtr, this, ParseContext.getCPtr(context), context, JsonValue.getCPtr(root), root);
    return (cPtr == 0) ? null : new BaseActionElement(cPtr, true);
  }

}
