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
// Copies memory from one segment of code to another
// Start and End must be in the same segment.
// ==============================================================================
void PSMem::Copy(const UINT32 Start, const UINT32 End, const UINT32 Dest)
{
	UINT32 start;
	UINT32 end;
	UINT32 dest;
	
	// Check for alignment of addresses (multiples of four)
	if ((Start & 0x3) || (End & 0x3) || (Dest & 0x3))
	{
		throw PSXException(ERROR_GIVEN_ADDRS_UNALIGNED);
	}
	else
	{
		// Check to make sure that Start does not come after End
		if (Start > End)
		{
			throw PSXException(ERROR_START_BEFORE_END);
		}
		
		// Check to make sure Start and End are in the same memory segment
		try {
			SameSegment(Start, End);
		}
		catch (PSXException e) {
			throw PSXException(ERROR_NOT_SAME_SEGMENT);
		}
		
		// Translate addresses
		try {
			start = TranslateAddress(Start);
			end = TranslateAddress(End);
			dest = TranslateAddress(Dest);
		}
		catch (PSXException e) {
			throw PSXException(ERROR_GIVEN_ADDRS_INVALID);
		}

		for (UINT32 x = start; x < end; x ++)
		{
			Memory[dest] = Memory[x];
			dest++;
		}
	}
}

// ==============================================================================
// Imports a BIOS image into the simulated memory.
// ==============================================================================
void PSMem::ImportBIOS(const char* BIOS)
{
	char ct1, ct2, ct3, ct4;
	char *buffer;
	int length;
	UINT8 *ptr;
	UINT8 *BiosMemPtr;
	
	// Open BIOS file
	Infile.open(BIOS, ios::binary);
	
	// Check that file opened correctly
	if (Infile.is_open() == false)
	{
		throw PSXException(ERROR_COULD_NOT_FIND_BIOS);
	}
		
	// Check to see if it's a valid BIOS file
	Infile.seekg(0x108);
	Infile >> noskipws >> hex >> ct1 >> ct2 >> ct3 >> ct4;

	if ((ct1 == 'S') && (ct2 == 'o') && (ct3 == 'n') && (ct4 == 'y'))
	{
		// File size of BIOS
		Infile.seekg (0, ios::end);
		length = Infile.tellg();
		Infile.seekg (0, ios::beg);
		
		// Allocate temporary memory for BIOS
		try {
			buffer = new char [length];
		}
		catch (std::bad_alloc e) {
			delete [] buffer;
			throw PSXException(ERROR_NOT_ENOUGH_MEMORY);
		}
		
		// Read over BIOS contents into temporary memory
		Infile.read(buffer, length);
		
		// Copy over temporary memory to main memory
		ptr = (UINT8*)buffer;
		BiosMemPtr = (UINT8*)Memory + RealBStart;
		for (int x = 0; x < length; x++)
		{
			BiosMemPtr[x] = ptr[x];
		}
		
		// Delete temporary memory
		delete [] buffer;
		
		// Close BIOS
		Infile.close();
	}
	else
	{
		// File wasn't a BIOS
		Infile.close();
		throw PSXException(ERROR_IMAGE_NOT_A_BIOS);
	}
}


void PSMem::ImportEXE(const char* EXE)
{
	// To be written
	// I need to figure out where exactly the EXE goes.  I have some vague ideas
	// but nothing concrete.  When I get through the whole BIOS resourcing, and
	// the creation of the OpenPSX library, I should have a much better idea and
	// will come back and finish this import method.
}

// ==============================================================================
// Exports data from simulated memory in a certain segment to a standard file.
// ==============================================================================
void PSMem::Export(const char* SFile, const UINT32 Start, const UINT32 End)
{
	char *TempStorage;
	int TempSize;
	int position = 8;
	UINT32 start;
	UINT32 end;
	
	// Check for alignment of addresses (multiples of four)
	if ((Start & 0x3) || (End & 0x3))
	{
		throw PSXException(ERROR_GIVEN_ADDRS_UNALIGNED);
	}
	else
	{	
		// Check to make sure that Start does not come after End
		if (Start > End)
		{
			throw PSXException(ERROR_START_BEFORE_END);
		}
	
		// Check to make sure Start and End are in the same memory segment
		try {
			SameSegment(Start, End);
		}
		catch (PSXException e) {
			throw PSXException(ERROR_NOT_SAME_SEGMENT);
		}
	
		// Open SFile for writing
		Outfile.open(SFile, ios::binary);
	
		// Check that file opened correctly
		if (Outfile.is_open() == false)
		{
			throw PSXException(ERROR_COULD_NOT_WRITE_SFILE);
		}
		
		// Translate addresses
		try {
			start = TranslateAddress(Start);
			end = TranslateAddress(End);
		}
		catch (PSXException e) {
			throw PSXException(ERROR_GIVEN_ADDRS_INVALID);
		}
	
		// Establish size of temporary array
		TempSize = ((end - start) + 4);
	
		// Set up temporary memory
		try {
			TempStorage = new char [TempSize + 8];
		}
		catch (bad_alloc e) {
			delete [] TempStorage;
			throw PSXException(ERROR_NOT_ENOUGH_MEMORY);
		}
	
		// Enter tagline that can be identifiable later on
		TempStorage[0] = 'P';
		TempStorage[1] = 'S';
		TempStorage[2] = 'M';
		TempStorage[3] = 'e';
		TempStorage[4] = 'm';
		TempStorage[5] = ' ';
		TempStorage[6] = 'S';
		TempStorage[7] = 'F';
		
		// Copy over simulated memory to temporary memory
		for (UINT32 x = start; x < (end + 4); x++)
		{
			TempStorage[position] = Memory[x];
			position++;
		}
	
		// Write temporary memory to SFile
		Outfile.write(TempStorage, TempSize + 8);
	
		// Close SFile and delete temporary memory
		Outfile.close();
		delete [] TempStorage;
	}
}

// ==============================================================================
// Backs up simulated memory to a standard file.
// ==============================================================================
void PSMem::Backup(const char* SFile)
{
	char *TempStorage;
	int position = 8;
	
	// Open SFile for writing
	Outfile.open(SFile, ios::binary);
	
	// Check that file opened correctly
	if (Outfile.is_open() == false)
	{
		throw PSXException(ERROR_COULD_NOT_WRITE_SFILE);
	}
	
	// Set up temporary memory
	try {
		TempStorage = new char [MemSize + 8];
	}
	catch (bad_alloc e) {
		delete [] TempStorage;
		throw PSXException(ERROR_NOT_ENOUGH_MEMORY);
	}
	
	// Enter tagline that can be identifiable later on
	TempStorage[0] = 'P';
	TempStorage[1] = 'S';
	TempStorage[2] = 'M';
	TempStorage[3] = 'e';
	TempStorage[4] = 'm';
	TempStorage[5] = ' ';
	TempStorage[6] = 'S';
	TempStorage[7] = 'F';
	
	// Copy over simulated memory to temporary memory
	for (int x = 0; x < MemSize; x++)
	{
		TempStorage[position] = Memory[x];
		position++;
	}
	
	// Write temporary memory to SFile
	Outfile.write(TempStorage, MemSize + 8);
	
	// Close SFile and delete temporary memory
	Outfile.close();
	delete [] TempStorage;
}

// ==============================================================================
// Restores the memory of PSMem from a standard file.
// ==============================================================================
void PSMem::Restore(const char* SFile)
{
	char ct1, ct2, ct3, ct4, ct5, ct6, ct7, ct8;
	char *buffer;
	int length;
	
	// Open SFile
	Infile.open(SFile, std::ios::binary);
	
	// Check that file opened correctly
	if (Infile.is_open() == false)
	{
		throw PSXException(ERROR_COULD_NOT_FIND_SF);
	}
		
	// Check to see if it's a valid SFile
	Infile >> noskipws >> hex >> ct1 >> ct2 >> ct3 >> ct4 >> ct5 >> ct6 >> ct7 >> ct8;
	
	if ((ct1 == 'P') && (ct2 == 'S') && (ct3 == 'M') && (ct4 == 'e') && (ct5 == 'm') && (ct6 == ' ') && (ct7 == 'S') && (ct8 == 'F'))
	{
		// File size of SFile
		Infile.seekg (0, ios::end);
		length = Infile.tellg();
		Infile.seekg (0, ios::beg);
		
		// Allocate temporary memory for SFile
		try {
			buffer = new char [length];
		}
		catch (bad_alloc e) {
			delete [] buffer;
			throw PSXException(ERROR_NOT_ENOUGH_MEMORY);
		}
		
		// Read over SFile contents into temporary memory
		Infile.read(buffer, length);
		
		// Clear out old memory
		ResetMem();
		
		// Copy over temporary memory to main memory
		for (int x = 0; x < length; x++)
		{
			Memory[x] = ((UINT8*)buffer)[x + 8];
		}
		
		// Delete temporary memory
		delete [] buffer;
		
		// Close SFile
		Infile.close();
	}
	else
	{
		// File wasn't an SFile
		Infile.close();
		throw PSXException(ERROR_IMAGE_NOT_AN_SFILE);
	}
}

// ==============================================================================
// Resets all the simulated memory to zero.
// ==============================================================================
void PSMem::ResetMem(void)
{
	// Assign every element to zero
	for (int x = 0; x < MemSize; x++)
	{
		Memory[x] = 0;
	}
}
