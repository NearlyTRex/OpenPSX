// Copyright (c) 2001, OpenPSX team
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following
// conditions are met:
//
//    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer
//       in the documentation and/or other materials provided with the distribution.
//    * Neither the name of the author nor the names of contributors may be used to endorse or promote
//       products derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
// OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
// OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
// IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#ifndef CONSTANTS_H
#define CONSTANTS_H

// Memory size
#define MemSize     0x00292400

// Fake (emulated system memory) defines
#define FakePPStart 0x1F000000
#define FakePPLast  0x1F00FFFF
#define FakeSPStart 0x1F800000
#define FakeSPLast  0x1F8003FF
#define FakeHRStart 0x1F801000
#define FakeHRLast  0x1F802FFF
#define FakeM1Start 0x80000000
#define FakeM1Last  0x801FFFFF
#define FakeM2Start 0xA0000000
#define FakeM2Last  0xA01FFFFF
#define FakeBStart  0xBFC00000
#define FakeBLast   0xBFC7FFFF

// Real (actual array addresses) defines
#define RealKStart  0x00000000
#define RealKLast   0x0000FFFF
#define RealUStart  0x00010000
#define RealULast   0x001FFFFF
#define RealPPStart 0x00200000
#define RealPPLast  0x0020FFFF
#define RealSPStart 0x00210000
#define RealSPLast  0x002103FF
#define RealHRStart 0x00210400
#define RealHRLast  0x002123FF
#define RealBStart  0x00212400
#define RealBLast   0x002923FF

// Difference factors
#define PPDiff      0x1EE00000
#define SPDiff      0x1F5F0000
#define HRDiff      0x1F5F0C00
#define M1Diff      0x80000000
#define M2Diff      0xA0000000
#define BDiff       0xBF9EDC00

#define BiosStart	0xBFC00000
#define BiosEnd		0xBFC7FFFC

#endif
