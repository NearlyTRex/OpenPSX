# This file was created automatically by SWIG.
import PSMemc
class PSMem:
    __setmethods__ = {}
    for _s in []: __setmethods__.update(_s.__setmethods__)
    def __setattr__(self,name,value):
        if (name == "this"):
            if isinstance(value,PSMem):
                self.__dict__[name] = value.this
                if hasattr(value,"thisown"): self.__dict__["thisown"] = value.thisown
                del value.thisown
                return
        method = PSMem.__setmethods__.get(name,None)
        if method: return method(self,value)
        self.__dict__[name] = value

    __getmethods__ = {}
    for _s in []: __getmethods__.update(_s.__getmethods__)
    def __getattr__(self,name):
        method = PSMem.__getmethods__.get(name,None)
        if method: return method(self)
        raise AttributeError,name

    def __init__(self,*args):
        self.this = apply(PSMemc.new_PSMem,args)
        self.thisown = 1
    def __del__(self,PSMemc=PSMemc):
        if getattr(self,'thisown',0):
            PSMemc.delete_PSMem(self)
    def LoadByte(*args): return apply(PSMemc.PSMem_LoadByte,args)
    def LoadByteUnsigned(*args): return apply(PSMemc.PSMem_LoadByteUnsigned,args)
    def LoadHalfword(*args): return apply(PSMemc.PSMem_LoadHalfword,args)
    def LoadHalfwordUnsigned(*args): return apply(PSMemc.PSMem_LoadHalfwordUnsigned,args)
    def LoadWord(*args): return apply(PSMemc.PSMem_LoadWord,args)
    def LoadWordLeft(*args): return apply(PSMemc.PSMem_LoadWordLeft,args)
    def LoadWordRight(*args): return apply(PSMemc.PSMem_LoadWordRight,args)
    def LoadWordToCOP0(*args): return apply(PSMemc.PSMem_LoadWordToCOP0,args)
    def LoadWordToCOP2(*args): return apply(PSMemc.PSMem_LoadWordToCOP2,args)
    def StoreByte(*args): return apply(PSMemc.PSMem_StoreByte,args)
    def StoreHalfword(*args): return apply(PSMemc.PSMem_StoreHalfword,args)
    def StoreWord(*args): return apply(PSMemc.PSMem_StoreWord,args)
    def StoreWordLeft(*args): return apply(PSMemc.PSMem_StoreWordLeft,args)
    def StoreWordRight(*args): return apply(PSMemc.PSMem_StoreWordRight,args)
    def StoreWordFromCOP0(*args): return apply(PSMemc.PSMem_StoreWordFromCOP0,args)
    def StoreWordFromCOP2(*args): return apply(PSMemc.PSMem_StoreWordFromCOP2,args)
    def Copy(*args): return apply(PSMemc.PSMem_Copy,args)
    def ImportBIOS(*args): return apply(PSMemc.PSMem_ImportBIOS,args)
    def ImportEXE(*args): return apply(PSMemc.PSMem_ImportEXE,args)
    def Export(*args): return apply(PSMemc.PSMem_Export,args)
    def Backup(*args): return apply(PSMemc.PSMem_Backup,args)
    def Restore(*args): return apply(PSMemc.PSMem_Restore,args)
    def ResetMem(*args): return apply(PSMemc.PSMem_ResetMem,args)
    def __repr__(self):
        return "<C PSMem instance at %s>" % (self.this,)

class PSMemPtr(PSMem):
    def __init__(self,this):
        self.this = this
        if not hasattr(self,"thisown"): self.thisown = 0
        self.__class__ = PSMem
PSMemc.PSMem_swigregister(PSMemPtr)
MemSize = PSMemc.MemSize
FakePPStart = PSMemc.FakePPStart
FakePPLast = PSMemc.FakePPLast
FakeSPStart = PSMemc.FakeSPStart
FakeSPLast = PSMemc.FakeSPLast
FakeHRStart = PSMemc.FakeHRStart
FakeHRLast = PSMemc.FakeHRLast
FakeM1Start = PSMemc.FakeM1Start
FakeM1Last = PSMemc.FakeM1Last
FakeM2Start = PSMemc.FakeM2Start
FakeM2Last = PSMemc.FakeM2Last
FakeBStart = PSMemc.FakeBStart
FakeBLast = PSMemc.FakeBLast
RealKStart = PSMemc.RealKStart
RealKLast = PSMemc.RealKLast
RealUStart = PSMemc.RealUStart
RealULast = PSMemc.RealULast
RealPPStart = PSMemc.RealPPStart
RealPPLast = PSMemc.RealPPLast
RealSPStart = PSMemc.RealSPStart
RealSPLast = PSMemc.RealSPLast
RealHRStart = PSMemc.RealHRStart
RealHRLast = PSMemc.RealHRLast
RealBStart = PSMemc.RealBStart
RealBLast = PSMemc.RealBLast

