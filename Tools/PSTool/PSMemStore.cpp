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
// Store least significant byte of Register at addressed location.
// ==============================================================================
void PSMem::StoreByte(const UINT32 Address, const UINT32 Register)
{
	UINT32 address;
	
	// Translate Address
	try {
		address = TranslateAddress(Address);
	}
	catch (PSXException e) {
		throw PSXException(ERROR_GIVEN_ADDR_INVALID);
	}
	Memory[address] = Register;
}

// ==============================================================================
// Store least significant halfword of Register at addressed location.
// ==============================================================================
void PSMem::StoreHalfword(const UINT32 Address, const UINT32 Register)
{
	UINT32 address;
	
	// Check for alignment of address
	if (Address & 0x1)
	{
		throw PSXException(ERROR_GIVEN_ADDR_UNALIGNED);
	}
	else
	{
		// Translate Address
		try {
			address = TranslateAddress(Address);
		}
		catch (PSXException e) {
			throw PSXException(ERROR_GIVEN_ADDR_INVALID);
		}
		((UINT16*)Memory)[address / 2] = Register;
	}
}

// ==============================================================================
// Store least significant word of Register at addressed location.
// ==============================================================================
void PSMem::StoreWord(const UINT32 Address, const UINT32 Register)
{
	UINT32 address;
	
	// Some memory write protection I still have to figure out
	if (Address == 0xFFFE0130)
	{
		ControlMem(Register);
	}
	else
	{
		// Check for alignment of address
		if (Address & 0x3)
		{
			throw PSXException(ERROR_GIVEN_ADDR_UNALIGNED);
		}
		else
		{
			// Translate Address
			try {
				address = TranslateAddress(Address);
			}
			catch (PSXException e) {
				throw PSXException(ERROR_GIVEN_ADDR_INVALID);
			}
			((UINT32*)Memory)[address / 4] = Register;
		}
	}
}

// ==============================================================================
// Shift contents of register Register right so that the leftmost byte of the word
// is in position of addressed byte.  Store bytes containing original data into
// corresponding bytes at addressed byte.
// ==============================================================================
void PSMem::StoreWordLeft(const UINT32 Address, const UINT32 Register)
{
	UINT32 address;
	UINT32 Data;
	
	// Translate Address
	try {
		address = TranslateAddress(Address);
	}
	catch (PSXException e) {
		throw PSXException(ERROR_GIVEN_ADDR_INVALID);
	}
	Data = ((UINT32*)Memory)[(address / 4) & 0xFFFFFFFC];
	switch (Address & 0x3)
	{
		case 0x0:
			Data = (Data & 0xFFFFFF00) | (Register >> 0x18);
		break;
		
		case 0x1:
			Data = (Data & 0xFFFF0000) | (Register >> 0x10);
		break;
		
		case 0x2:
			Data = (Data & 0xFF000000) | (Register >> 0x8);
		break;
		
		case 0x3:
			Data = Register;
		break;
	}
	((UINT32*)Memory)[address & 0xFFFFFFFC] = Data;
}

// ==============================================================================
// Shift contents of register Register so that the rightmost byte of the word is in
// position of addressed byte.  Store bytes containing original data into
// corresponding bytes at addressed byte.
// ==============================================================================
void PSMem::StoreWordRight(const UINT32 Address, const UINT32 Register)
{
	UINT32 address;
	UINT32 Data;
	
	// Translate Address
	try {
		address = TranslateAddress(Address);
	}
	catch (PSXException e) {
		throw PSXException(ERROR_GIVEN_ADDR_INVALID);
	}
	Data = ((UINT32*)Memory)[(address / 4) & 0xFFFFFFFC];
	switch(Address & 0x3)
	{
		case 0x0:
			Data = Register;
		break;
		
		case 0x1:
			Data = (Data & 0x000000ff) | (Register << 0x8);
		break;
		
		case 0x2:
			Data = (Data & 0x0000ffff) | (Register << 0x10);
		break;
		
		case 0x3:
			Data = (Data & 0x00ffffff) | (Register << 0x18);
		break;
	}
	((UINT32*)Memory)[address & 0xFFFFFFFC] = Data;
}

// ==============================================================================
// Store contents of COP0 register Register at addressed memory word.
// ==============================================================================
void PSMem::StoreWordFromCOP0(const UINT32 Address, const UINT32 Register)
{
	try {
		StoreWord(Address, Register);
	}
	catch (PSXException e) {
		if (e.GetError() == ERROR_GIVEN_ADDR_UNALIGNED)
		{
			throw PSXException(ERROR_GIVEN_ADDR_UNALIGNED);
		}
		else if (e.GetError() == ERROR_GIVEN_ADDR_INVALID)
		{
			throw PSXException(ERROR_GIVEN_ADDR_INVALID);
		}
	}
}
// ==============================================================================
// Store contents of COP2 register Register at addressed memory word.
// ==============================================================================
void PSMem::StoreWordFromCOP2(const UINT32 Address, const UINT32 Register)
{
	try {
		StoreWord(Address, Register);
	}
	catch (PSXException e) {
		if (e.GetError() == ERROR_GIVEN_ADDR_UNALIGNED)
		{
			throw PSXException(ERROR_GIVEN_ADDR_UNALIGNED);
		}
		else if (e.GetError() == ERROR_GIVEN_ADDR_INVALID)
		{
			throw PSXException(ERROR_GIVEN_ADDR_INVALID);
		}
	}
}
