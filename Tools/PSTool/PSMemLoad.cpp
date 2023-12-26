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
// Return sign-extended contents of addressed byte.
// ==============================================================================
UINT32 PSMem::LoadByte(const UINT32 Address)
{
	UINT32 reg;
	try {
		reg = LoadByteUnsigned(Address);
	}
	catch (PSXException e) {
		throw PSXException(ERROR_GIVEN_ADDR_INVALID);
	}
	return (UINT32)(INT8)reg;
}

// ==============================================================================
// Return zero-extended contents of addressed byte.
// ==============================================================================
UINT32 PSMem::LoadByteUnsigned(const UINT32 Address)
{
	UINT32 address;
	
	// Translate Address
	try {
		address = TranslateAddress(Address);
	}
	catch (PSXException e) {
		throw PSXException(ERROR_GIVEN_ADDR_INVALID);
	}
	return (UINT32)Memory[address];
}

// ==============================================================================
// Return sign-extended contents of addressed halfword.
// ==============================================================================
UINT32 PSMem::LoadHalfword(const UINT32 Address)
{
	UINT32 reg;
	try {
		reg = LoadHalfwordUnsigned(Address);
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
	return (UINT32)(INT16)reg;
}

// ==============================================================================
// Return zero-extended contents of addressed halfword.
// ==============================================================================
UINT32 PSMem::LoadHalfwordUnsigned(const UINT32 Address)
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
		return (UINT32)((UINT16*)Memory)[address / 2];
	}
}

// ==============================================================================
// Return addressed word.
// ==============================================================================
UINT32 PSMem::LoadWord(const UINT32 Address)
{
	UINT32 address;
	
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
		return ((UINT32*)Memory)[address / 4];
	}
}

// ==============================================================================
// Shift addressed word left so that the addressed byte is the leftmost byte of
// a word.  Merge bytes from memory with contents of Register and load the result
// into Register.
// ==============================================================================
void PSMem::LoadWordLeft(const UINT32 Address, UINT32 Register)
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
			Register = (Register & 0x00FFFFFF) | (Data << 0x18);
		break;
		
		case 0x1:
			Register = (Register & 0x0000FFFF) | (Data << 0x10);
		break;
		
		case 0x2:
			Register = (Register & 0x000000FF) | (Data << 0x8);
		break;
		
		case 0x3:
			Register = Data;
		break;
	}
}

// ==============================================================================
// Shift addressed word right so that addressed byte is the rightmost byte of a
// word.  Merge bytes from memory with contents of Register and load the result
// into Register.
// ==============================================================================
void PSMem::LoadWordRight(const UINT32 Address, UINT32 Register)
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
			Register = Data;
		break;
		
		case 0x1:
			Register = (Register & 0xFF000000) | (Data >> 0x8);
		break;
		
		case 0x2:
			Register = (Register & 0xFFFF0000) | (Data >> 0x10);
		break;
		
		case 0x3:
			Register = (Register & 0xFFFFFF00) | (Data >> 0x18);
		break;
	}
}

// ==============================================================================
// Return contents of addressed word.
// ==============================================================================
UINT32 PSMem::LoadWordToCOP0(const UINT32 Address)
{
	UINT32 reg;
	try {
		reg = LoadWord(Address);
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
	return reg;
}
// ==============================================================================
// Return contents of addressed word.
// ==============================================================================
UINT32 PSMem::LoadWordToCOP2(const UINT32 Address)
{
	UINT32 reg;
	try {
		reg = LoadWord(Address);
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
	return reg;
}
