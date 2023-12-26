# This file was created automatically by SWIG.
import DImagec
class DImage:
    __setmethods__ = {}
    for _s in []: __setmethods__.update(_s.__setmethods__)
    def __setattr__(self,name,value):
        if (name == "this"):
            if isinstance(value,DImage):
                self.__dict__[name] = value.this
                if hasattr(value,"thisown"): self.__dict__["thisown"] = value.thisown
                del value.thisown
                return
        method = DImage.__setmethods__.get(name,None)
        if method: return method(self,value)
        self.__dict__[name] = value

    __getmethods__ = {}
    for _s in []: __getmethods__.update(_s.__getmethods__)
    def __getattr__(self,name):
        method = DImage.__getmethods__.get(name,None)
        if method: return method(self)
        raise AttributeError,name

    def __init__(self,*args):
        self.this = apply(DImagec.new_DImage,args)
        self.thisown = 1
    def __del__(self,DImagec=DImagec):
        if getattr(self,'thisown',0):
            DImagec.delete_DImage(self)
    def DecompileBIOS(*args): return apply(DImagec.DImage_DecompileBIOS,args)
    def DecompileEXE(*args): return apply(DImagec.DImage_DecompileEXE,args)
    def DecompileSF(*args): return apply(DImagec.DImage_DecompileSF,args)
    def __repr__(self):
        return "<C DImage instance at %s>" % (self.this,)

class DImagePtr(DImage):
    def __init__(self,this):
        self.this = this
        if not hasattr(self,"thisown"): self.thisown = 0
        self.__class__ = DImage
DImagec.DImage_swigregister(DImagePtr)
MemSize = DImagec.MemSize
FakePPStart = DImagec.FakePPStart
FakePPLast = DImagec.FakePPLast
FakeSPStart = DImagec.FakeSPStart
FakeSPLast = DImagec.FakeSPLast
FakeHRStart = DImagec.FakeHRStart
FakeHRLast = DImagec.FakeHRLast
FakeM1Start = DImagec.FakeM1Start
FakeM1Last = DImagec.FakeM1Last
FakeM2Start = DImagec.FakeM2Start
FakeM2Last = DImagec.FakeM2Last
FakeBStart = DImagec.FakeBStart
FakeBLast = DImagec.FakeBLast
RealKStart = DImagec.RealKStart
RealKLast = DImagec.RealKLast
RealUStart = DImagec.RealUStart
RealULast = DImagec.RealULast
RealPPStart = DImagec.RealPPStart
RealPPLast = DImagec.RealPPLast
RealSPStart = DImagec.RealSPStart
RealSPLast = DImagec.RealSPLast
RealHRStart = DImagec.RealHRStart
RealHRLast = DImagec.RealHRLast
RealBStart = DImagec.RealBStart
RealBLast = DImagec.RealBLast

