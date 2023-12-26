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
// The constructor tries to set up a simulated memory space but throws an
// exception if it cannot allocate enough memory.  It also clears that memory
// to zero.
// ==============================================================================
PSMem::PSMem(char* DB)
{
	canWrite = true;
	ofstream tempFile;
	DBFile = DB;
	
	// Set up memory space
	try {
		Memory = new UINT8 [MemSize];
	}
	catch (bad_alloc e) {
		delete [] Memory;
		throw PSXException(ERROR_CANT_ALLOCATE_SIM_MEM);
	}
	
	try {
		Restore(DBFile.c_str());
	}
	catch (PSXException e) {
		// Create/overwrite the file, set tagline, and reset memory
		tempFile.open(DBFile.c_str());
		tempFile << "PSMem SF";
		ResetMem();
	}
}

// ==============================================================================
// The destructor releases the simulated memory that was allocated in the
// constructor.
// ==============================================================================
PSMem::~PSMem()
{
	try {
		Backup(DBFile.c_str());
	}
	catch (PSXException e) {
		// Not enough memory, or could not write to filesystem
	}
	// Release memory from heap
	delete [] Memory;
}

