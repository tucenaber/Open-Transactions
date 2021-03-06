/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


using System;
using System.Runtime.InteropServices;

public class TradeListNym : Storable {
  private HandleRef swigCPtr;

  internal TradeListNym(IntPtr cPtr, bool cMemoryOwn) : base(otapiPINVOKE.TradeListNym_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(TradeListNym obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~TradeListNym() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          otapiPINVOKE.delete_TradeListNym(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public uint GetTradeDataNymCount() {
    uint ret = otapiPINVOKE.TradeListNym_GetTradeDataNymCount(swigCPtr);
    return ret;
  }

  public TradeDataNym GetTradeDataNym(uint nIndex) {
    IntPtr cPtr = otapiPINVOKE.TradeListNym_GetTradeDataNym(swigCPtr, nIndex);
    TradeDataNym ret = (cPtr == IntPtr.Zero) ? null : new TradeDataNym(cPtr, false);
    return ret;
  }

  public bool RemoveTradeDataNym(uint nIndexTradeDataNym) {
    bool ret = otapiPINVOKE.TradeListNym_RemoveTradeDataNym(swigCPtr, nIndexTradeDataNym);
    return ret;
  }

  public bool AddTradeDataNym(TradeDataNym disownObject) {
    bool ret = otapiPINVOKE.TradeListNym_AddTradeDataNym(swigCPtr, TradeDataNym.getCPtr(disownObject));
    if (otapiPINVOKE.SWIGPendingException.Pending) throw otapiPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public new static TradeListNym ot_dynamic_cast(Storable pObject) {
    IntPtr cPtr = otapiPINVOKE.TradeListNym_ot_dynamic_cast(Storable.getCPtr(pObject));
    TradeListNym ret = (cPtr == IntPtr.Zero) ? null : new TradeListNym(cPtr, false);
    return ret;
  }

}
