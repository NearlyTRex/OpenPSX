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

// Current bugs:
// 1. cout mystery (below)
// 2. random throwup of array strings from WriteLine.cpp (I have no idea how this is even done,
//    because almost all uses of these strings are fine except for a small few)

int main(int argc, char *argv[])
{
	// Variables
	char* BIOS;
	char* Decomp;
	char printstring1[5];
	char printstring2[5];
	UINT32 PC;
	UINT32 Opcode1;
	UINT32 Opcode2;
	DBios BImage;

	// Get commandline arguments
	if (argc != 3)
	{
		// Print help message, and quit
		cout << "Usage: DBIOS <BIOS> <Decomp>" << endl;
		return -1;
	}
	else
	{
		BIOS   = argv[1];
		Decomp = argv[2];
	}

	// Set the BIOS image to use
	BImage.setBios(BIOS);

	// Set the DEC file to write
	BImage.setDec(Decomp);

	// Begin line by line decompilation
	for (PC = 0xBFC00000; PC <= 0xBFC7FFFC; PC += 4)
	{
		// Note: I have no idea why this line is necessary (my guess is a memory flushing problem--
		// however, flush doesn't work, only endl).  Without it, the program segfaults,
		// and doesn't finish the decompilation.  If anyone can figure out what the @!$*# is going on,
		// please tell me :)
		cout << endl;

		// Get first opcode
		Opcode1 = BImage.GetOpcode(PC);

		// Test to see if opcode is a delayslot instruction
		if (isJump(Opcode1))
		{
			// First, we work on Opcode2
			Opcode2 = BImage.GetOpcode(PC + 4);
			Opcode2String(Opcode2, printstring2);
			BImage.WriteLine(Opcode2, (PC + 4), printstring2);

			// Now, we work on Opcode1
			Opcode2String(Opcode1, printstring1);
			BImage.WriteLine(Opcode1, PC, printstring1);

			// Go to space after delay slot
			// (it has to be 4 because you are also adding 4 on each loop as well as this 4)
			PC += 4;
		}
		else
		{
			// Otherwise, we just work on Opcode1
			Opcode2String(Opcode1, printstring1);
			BImage.WriteLine(Opcode1, PC, printstring1);
		}
	}

	cout << "Program completed successfully!" << endl;

	return 0;
}
