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

void PrintHelp(void)
{
	cout << "PSTool: Part of the OpenPSX project" << endl;
	cout << "A multitoolset for the porting process of PSX games" << endl;
	cout << endl;
	cout << "To execute a command from a module, access it like" << endl;
	cout << "this: Modulel,Command,Param1,Param2,Param3,Param4" << endl;
	cout << endl;
	cout << "To see a list of commands for each module, type \"commands\"" << endl;
}

void PrintCommands(void)
{
	cout << "Current modules:" << endl;
	cout << endl;
	cout << "PSMem - PSX memory simulation system" << endl;
	cout << "PSMem commands:" << endl;
	cout << "1) LoadByte,Address" << endl;
	cout << "2) LoadByteUnsigned,Address" << endl;
	cout << "3) LoadHalfword,Address" << endl;
	cout << "4) LoadHalfwordUnsigned,Address" << endl;
	cout << "5) LoadWord,Address" << endl;
	cout << "6) LoadWordLeft,Address,Value" << endl;
	cout << "7) LoadWordRight,Address,Value" << endl;
	cout << "8) LoadWordToCOP0,Address" << endl;
	cout << "9) LoadWordToCOP2,Address" << endl;
	cout << "10) StoreByte,Address,Value" << endl;
	cout << "11) StoreHalfword,Address,Value" << endl;
	cout << "12) StoreWord,Address,Value" << endl;
	cout << "13) StoreWordLeft,Address,Value" << endl;
	cout << "14) StoreWordRight,Address,Value" << endl;
	cout << "15) StoreWordFromCOP0,Address,Value" << endl;
	cout << "16) StoreWordFromCOP2,Address,Value" << endl;
	cout << "17) Copy,StartPC,EndPC,DestPC" << endl;
	cout << "18) ImportBIOS,BIOS" << endl;
	cout << "19) ImportEXE,EXE" << endl;
	cout << "20) Export,SFile,StartPC,EndPC" << endl;
	cout << "21) Backup,SFile" << endl;
	cout << "22) Restore,SFile" << endl;
	cout << "23) ResetMem" << endl;
	cout << endl;
	cout << "DImage - PSX image decompilers" << endl;
	cout << "DImage commands:" << endl;
	cout << "1) DecompileBIOS,BIOS,Outfile" << endl;
	cout << "2) DecompileEXE,EXE,Outfile" << endl;
	cout << "3) DecompileSF,SF,Outfile" << endl;
	cout << endl;
}

void PrintCopyright(void)
{
	cout << "Copyright (c) 2001, OpenPSX team" << endl;
}

void PrintCredits(void)
{
}

void PrintLicense(void)
{
	cout << "Copyright (c) 2001, OpenPSX team" << endl;
	cout << "All rights reserved." << endl;
	cout << endl;
	cout << "Redistribution and use in source and binary forms, with or without modification," << endl;
	cout << "are permitted provided that the following conditions are met:" << endl;
	cout << endl;
    cout << "* Redistributions of source code must retain the above copyright notice," << endl;
    cout << "  this list of conditions and the following disclaimer." << endl;
    cout << "* Redistributions in binary form must reproduce the above copyright notice," << endl;
    cout << "  this list of conditions and the following disclaimer in the documentation" << endl;
    cout << "  and/or other materials provided with the distribution." << endl;
    cout << "* Neither the name of the author nor the names of contributors" << endl;
    cout << "  may be used to endorse or promote products derived from this software without" << endl;
    cout << "  specific prior written permission." << endl;
	cout << endl;
	cout << "THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"" << endl;
	cout << "AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, " << endl;
	cout << "THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR" << endl;
	cout << "PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS" << endl;
	cout << "DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE" << endl;
	cout << "GOODS OR SERVICES; LOSS OF USE, BE LIABLE FOR ANY DIRECT, INDIRECT," << endl;
	cout << "INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DATA, OR PROFITS;" << endl;
	cout << "OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY," << endl;
	cout << "WHETHERIN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR" << endl;
	cout << "OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN" << endl;
	cout << "IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." << endl;
}

