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

// ================================
// Function - DBios::setBios
// Use - Sets and loads the given BIOS file
// # This function uses the 'new' operator #
// ================================
int DBios::setBios(const char* BIOS)
{
	int BiosSize;

	// Check to see if set already, and if not, then set
	if (setBIOS == false)
	{
		Biofile.open(BIOS, ifstream::binary);
		setBIOS = true;
	}
	else
	{
		puts("BIOS is already set");
		return -1;
	}

	// Get filesize
	Biofile.seekg (0, ios::end);
	BiosSize = Biofile.tellg();
	Biofile.seekg (0, ios::beg);

	// Allocate memory for BIOS
	Memory = new UINT32 [BiosSize];

	// Copy over BIOS data to memory
	Biofile.read(Memory, BiosSize);

	return 0;
}

// ================================
// Function - DBios::setDec
// Use - Sets and loads the given DEC file
// # This function uses the 'new' operator #
// ================================
int DBios::setDec(const char* DEC)
{
	// Check to see if set already, and if not, then set
	if (setDEC == false)
	{
		Decfile.open(DEC);
		setDEC = true;
		return 0;
	}
	else
	{
		puts("DEC is already set");
		return -1;
	}
}

