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
#include "Include/Main.h"
using namespace std;

// ==============================================================================
// Translates the given address to the internal format of the simulated memory.
// ==============================================================================
UINT32 PSMem::TranslateAddress(const UINT32 Address)
{
	UINT32 LocalAddr = Address;
	
	// Translate effective address
	if ((LocalAddr >= FakePPStart) && (LocalAddr <= FakePPLast + 1))
	{
		// If address is within Parallel Port, make an adjustment to address
		LocalAddr = LocalAddr - PPDiff;
	}
	else if ((LocalAddr >= FakeSPStart) && (LocalAddr <= FakeSPLast + 1))
	{
		// If address is within Scratch Pad, make an adjustment to address
		LocalAddr = LocalAddr - SPDiff;
	}
	else if ((LocalAddr >= FakeHRStart) && (LocalAddr <= FakeHRLast + 1))
	{
		// If address is within Hardware Reg, make an adjustment to address
		LocalAddr = LocalAddr - HRDiff;
	}
	else if ((LocalAddr >= FakeM1Start) && (LocalAddr <= FakeM1Last + 1))
	{
		// If address is within KU Mirror1, make an adjustment to address
		LocalAddr = LocalAddr - M1Diff;
	}
	else if ((LocalAddr >= FakeM2Start) && (LocalAddr <= FakeM2Last + 1))
	{
		// If address is within KU Mirror2, make an adjustment to address
		LocalAddr = LocalAddr - M2Diff;
	}
	else if ((LocalAddr >= FakeBStart) && (LocalAddr <= FakeBLast + 1))
	{
		// If address is within BIOS, make an adjustment to address
		LocalAddr = LocalAddr - BDiff;
	}
	else if ((LocalAddr >= RealKStart) && (LocalAddr <= RealULast + 1))
	{
		// If address is within KU, make no adjustments
	}
	else
	{
		// Since address is not a usable address, throw exception
		throw PSXException(ERROR_GIVEN_ADDR_INVALID);
	}
	return LocalAddr;
}

// ==============================================================================
// Does a check to see if both Start and End addresses are within the same segment.
// ==============================================================================
void PSMem::SameSegment(const UINT32 Start, const UINT32 End)
{
	// Check to make sure that both addresses are within the same segment
	if (((Start >= FakePPStart) && (Start <= FakePPLast + 1)) && ((End >= FakePPStart) && (End <= FakePPLast + 1)))
	{
		// Okay
	}
	else if (((Start >= FakeSPStart) && (Start <= FakeSPLast + 1)) && ((End >= FakeSPStart) && (End <= FakeSPLast + 1)))
	{
		// Okay
	}
	else if (((Start >= FakeHRStart) && (Start <= FakeHRLast + 1)) && ((End >= FakeHRStart) && (End <= FakeHRLast + 1)))
	{
		// Okay
	}
	else if (((Start >= FakeM1Start) && (Start <= FakeM1Last + 1)) && ((End >= FakeM1Start) && (End <= FakeM1Last + 1)))
	{
		// Okay
	}
	else if (((Start >= FakeM2Start) && (Start <= FakeM2Last + 1)) && ((End >= FakeM2Start) && (End <= FakeM2Last + 1)))
	{
		// Okay
	}
	else if (((Start >= FakeBStart) && (Start <= FakeBLast + 1)) && ((End >= FakeBStart) && (End <= FakeBLast + 1)))
	{
		// Okay
	}
	else if (((Start >= RealKStart) && (Start <= RealULast + 1)) && ((End >= RealKStart) && (End <= RealULast + 1)))
	{
		// Okay
	}
	else
	{
		// Not okay, addresses must be within the same segment
		throw PSXException(ERROR_NOT_SAME_SEGMENT);
	}
}
