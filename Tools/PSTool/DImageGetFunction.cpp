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

string DImage::GetFunction(const char* DB, const UINT32 Address)
{
	ifstream dbFile;
	string retStr  = "null";
	char temp[256];
	UINT32 Addr = 0x00000000;
	
	// Clear character array out
	for (int x = 0; x < 256; x++)
	{
		temp[x] = ' ';
	}
			
	// Open file
	dbFile.open(DB);
	
	// Get lines from file
	while (!dbFile.eof())
	{
		// Get line into a character array
		dbFile.getline(temp, 256);
		
		// Break up string into tokens based on spaces
		StringTokenizer tok(temp, ' ');
		
		// Check first token (address) as long as its not empty
		if (!tok.empty())
		{
			try {
				Addr = Str2Num(tok[0]);
			}
			catch (PSXException e) {
				// Wasn't a valid address
			}
			
			// Check against given address
			if (Address == Addr)
			{
				// It's the same address
				return tok[1];
			}
		}
	}
	
	// Close file
	dbFile.close();
	
	return retStr;
}
