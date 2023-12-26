// Memory size
%constant int MemSize     = 0x00292400;

// Fake (emulated system memory) defines
%constant int FakePPStart = 0x1F000000;
%constant int FakePPLast  = 0x1F00FFFF;
%constant int FakeSPStart = 0x1F800000;
%constant int FakeSPLast  = 0x1F8003FF;
%constant int FakeHRStart = 0x1F801000;
%constant int FakeHRLast  = 0x1F802FFF;
%constant int FakeM1Start = 0x80000000;
%constant int FakeM1Last  = 0x801FFFFF;
%constant int FakeM2Start = 0xA0000000;
%constant int FakeM2Last  = 0xA01FFFFF;
%constant int FakeBStart  = 0xBFC00000;
%constant int FakeBLast   = 0xBFC7FFFF;

// Real (actual array addresses) defines
%constant int RealKStart  = 0x00000000;
%constant int RealKLast   = 0x0000FFFF;
%constant int RealUStart  = 0x00010000;
%constant int RealULast   = 0x001FFFFF;
%constant int RealPPStart = 0x00200000;
%constant int RealPPLast  = 0x0020FFFF;
%constant int RealSPStart = 0x00210000;
%constant int RealSPLast  = 0x002103FF;
%constant int RealHRStart = 0x00210400;
%constant int RealHRLast  = 0x002123FF;
%constant int RealBStart  = 0x00212400;
%constant int RealBLast   = 0x002923FF;
