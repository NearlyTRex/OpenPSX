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


void DImage::DecompileSF(const char* SF, const char* Outfile)
{
	// Variables
	int SFSize;
	char printstring1[5];
	char printstring2[5];
	UINT32 Opcode1;
	UINT32 Opcode2;
	UINT32* Memory;
	char* buffer;
	ifstream SFile;
	
	// Store the contents of the given SF into memory
	SFile.open(SF);
	
	// Check that file opened correctly
	if (SFile.is_open() == false)
	{
		throw PSXException(ERROR_COULD_NOT_FIND_SF);
	}
	
	// Get filesize
	SFile.seekg (0, ios::end);
	SFSize = SFile.tellg();
	SFile.seekg (0, ios::beg);
	
	// Allocate memory for temporary SFile memory
	try {
		buffer = new char [SFSize];
	}
	catch (bad_alloc e) 
	{
		delete [] buffer;
		throw PSXException(ERROR_NOT_ENOUGH_MEMORY);
	}
	
	// Copy SF data to temporary buffer
	SFile.read(buffer, SFSize);
	
	// Allocate 32-bit memory for SFile data
	try {
		Memory = new UINT32 [SFSize/4];
	}
	catch (bad_alloc e) 
	{
		delete [] Memory;
		throw PSXException(ERROR_NOT_ENOUGH_MEMORY);
	}
	
	// Copy over SFile data to Memory in 32 bit chunks
	for (int x = 0; x < (SFSize / 4); x++)
	{
		Memory[x] = ((UINT32*)buffer)[x];
	}
	
	// Open Decfile for writing
	Decfile.open(Outfile);
	
	// Check that file opened correctly
	if (Decfile.is_open() == false)
	{
		throw PSXException(ERROR_COULD_NOT_WRITE_OFILE);
	}
	
	// Begin line by line decompilation
	// Decompilation should use a loop of the original indexes, and
	// only translate to UINT32 Opcode and PC when passing data to
	// Opcode2String and WriteLine
	
	for (int index = 2; index < (SFSize / 4); index++)
	{
		// Get Opcode1 at index
		Opcode1 = Memory[index];
		#ifdef __BIG_ENDIAN__
		SwapBytes(Opcode1);
		#endif
		
		if (isJump(Opcode1))
		{
			// Get Opcode2 at index + 1 (for the delay slot)
			Opcode2 = Memory[index + 1];
			#ifdef __BIG_ENDIAN__
			SwapBytes(Opcode2);
			#endif
			
			// Get printstring2 for Opcode2
			Opcode2String(Opcode2, printstring2);
			
			// Write decomp for Opcode2
			WriteLine(Opcode2, (((index * 4) + BiosStart + 4) - 8), printstring2);
			
			// Get printstring1 for Opcode1
			Opcode2String(Opcode1, printstring1);
			
			// Write decomp for Opcode1
			WriteLine(Opcode1, (((index * 4) + BiosStart) - 8), printstring1);
			
			index += 1;
		}
		else
		{
			// Get printstring1 for Opcode1
			Opcode2String(Opcode1, printstring1);
			
			// Write decomp for Opcode1
			WriteLine(Opcode1, (((index * 4) + BiosStart) - 8), printstring1);
		}
	}
			

	// Release memory from heap & close files
	delete [] buffer;
	delete [] Memory;
	SFile.close();
	Decfile.close();
	
	cout << "Decompilation completed" << endl;
	
	return;
}
