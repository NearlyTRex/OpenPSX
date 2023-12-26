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
#ifndef PSMEM_H
#define PSMEM_H

// NB1: I can't seem to get custom exception specifications to work under GCC3
// e.g. void foo() throw (bar);
// I will document these specifications though

// NB2: In Copy and Export, End is specified by the user as an exclusive address (i.e. an address above that
// which is last being used.
// e.g. If Start == End, no copying/writing will take place.
//      If Start == End + 4, one opcode is copied/written.
//      and so on.
class PSMem
{
public:
	// Constructor
	PSMem(char* DB);

	// Destructor
	~PSMem();
	
	// Public methods
	UINT32 LoadByte(const UINT32 Address);
	UINT32 LoadByteUnsigned(const UINT32 Address);
	UINT32 LoadHalfword(const UINT32 Address);
	UINT32 LoadHalfwordUnsigned(const UINT32 Address);
	UINT32 LoadWord(const UINT32 Address);
	void LoadWordLeft(const UINT32 Address, UINT32 Register);
	void LoadWordRight(const UINT32 Address, UINT32 Register);
	UINT32 LoadWordToCOP0(const UINT32 Address);
	UINT32 LoadWordToCOP2(const UINT32 Address);
	void StoreByte(const UINT32 Address, const UINT32 Register);
	void StoreHalfword(const UINT32 Address, const UINT32 Register);
	void StoreWord(const UINT32 Address, const UINT32 Register);
	void StoreWordLeft(const UINT32 Address, const UINT32 Register);
	void StoreWordRight(const UINT32 Address, const UINT32 Register);
	void StoreWordFromCOP0(const UINT32 Address, const UINT32 Register);
	void StoreWordFromCOP2(const UINT32 Address, const UINT32 Register);
	void Copy(const UINT32 Start, const UINT32 End, const UINT32 Dest);
	void ImportBIOS(const char* BIOS);
	void ImportEXE(const char* EXE);
	void Export(const char* SFile, const UINT32 Start, const UINT32 End);
	void Backup(const char* SFile);
	void Restore(const char* SFile);
	void ResetMem(void);
	
private:
	// Private methods
	UINT32 TranslateAddress(const UINT32 Address);
	void SameSegment(const UINT32 Start, const UINT32 End);
	void ControlMem(const UINT32 Register);
	
	// Private data
	bool canWrite;
	std::string DBFile;
	UINT8 *Memory;
	std::ifstream Infile;
	std::ofstream Outfile;
};

#endif
