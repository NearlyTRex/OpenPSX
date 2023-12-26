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

//#define __BIG_ENDIAN__

int main()
{
	// Variables
	string cmd = "";
	int numCmds = 6;
	string params[numCmds];
		
	// Instantiate tool classes
	PSMem  psxMem(".PSMemDB");
	DImage psxDec;
	
	// Print out intro
	cout << endl;
	cout << "OpenPSX::PSTool - A PSX Multitool" << endl;
	cout << "Type \"help\", \"commands\", \"copyright\", \"credits\", or \"license\"," << endl;
	cout << "Or \"quit\" to quit." << endl;
	
	// Get main user command
	while (cmd != "quit")
	{
		// Clear params array
		for (int index = 0; index < numCmds; index++)
		{
			params[index] = "null";
		}
		
		// Prompt
		cout << ">>> ";
		cin >> cmd;
		
		// Tokenize
		StringTokenizer tok(cmd, ',');
		if (!tok.empty())
		{
			for (int index = 0; index < numCmds; index++)
			{
				if (tok.validIndex(index))
				{
					params[index] = tok[index];
				}
			}
		
			// Deal with basic commands
			if (params[0] == "help")
			{
				PrintHelp();
			}
			else if (params[0] == "commands")
			{
				PrintCommands();
			}
			else if (params[0] == "copyright")
			{
				PrintCopyright();
			}
			else if (params[0] == "credits")
			{
				PrintCredits();
			}
			else if (params[0] == "license")
			{
				PrintLicense();
			}
			else if (params[0] == "PSMem")
			{
				DoPSMemAction(psxMem, params[1], params[2], params[3], params[4]);
			}
			else if (params[0] == "DImage")
			{
				DoDImageAction(psxDec, params[1], params[2], params[3]);
			}
			else
			{
				if (params[0] != "quit")
				{
					ERROR_UNKNOWN_CMD_OR_MOD;
				}
				else
				{
					break;
				}
			}
		}
	}
	
	return 0;
}
