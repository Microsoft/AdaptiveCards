/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.0
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package io.adaptivecards.objectmodel;

public class Paragraph {
  private transient long swigCPtr;
  private transient boolean swigCMemOwn;

  protected Paragraph(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(Paragraph obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void swigSetCMemOwn(boolean own) {
    swigCMemOwn = own;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        AdaptiveCardObjectModelJNI.delete_Paragraph(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public Paragraph() {
    this(AdaptiveCardObjectModelJNI.new_Paragraph__SWIG_0(), true);
  }

  public Paragraph(Paragraph arg0) {
    this(AdaptiveCardObjectModelJNI.new_Paragraph__SWIG_1(Paragraph.getCPtr(arg0), arg0), true);
  }

  public JsonValue SerializeToJsonValue() {
    return new JsonValue(AdaptiveCardObjectModelJNI.Paragraph_SerializeToJsonValue(swigCPtr, this), true);
  }

  public InlineVector GetInlines() {
    return new InlineVector(AdaptiveCardObjectModelJNI.Paragraph_GetInlines__SWIG_0(swigCPtr, this), false);
  }

  public static Paragraph Deserialize(ParseContext context, JsonValue root) {
    long cPtr = AdaptiveCardObjectModelJNI.Paragraph_Deserialize(ParseContext.getCPtr(context), context, JsonValue.getCPtr(root), root);
    return (cPtr == 0) ? null : new Paragraph(cPtr, true);
  }

  public JsonValue GetAdditionalProperties() {
    return new JsonValue(AdaptiveCardObjectModelJNI.Paragraph_GetAdditionalProperties(swigCPtr, this), true);
  }

  public void SetAdditionalProperties(JsonValue additionalProperties) {
    AdaptiveCardObjectModelJNI.Paragraph_SetAdditionalProperties(swigCPtr, this, JsonValue.getCPtr(additionalProperties), additionalProperties);
  }

}
