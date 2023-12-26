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


void DoPSMemAction(PSMem &psxMem, string command, string param1, string param2, string param3)
{
	UINT32 Address;
	UINT32 Value;
	UINT32 StartPC;
	UINT32 EndPC;
	UINT32 DestPC;
	
	//cout << "Executing PSMem." << command << "(" << param1 << ", " << param2 << ", " << param3 << ")" << endl;
	if (command == "LoadByte")
	{
		// LoadByte,Address
		if (param1 != "null")
		{
			try {
				Address = Str2Num(param1);
				Value = psxMem.LoadByte(Address);
			}
			catch (PSXException e)
			{
				e.Report();
				return;
			}
			cout << PTAGS8 << Value << endl;
		}
	}
	else if (command == "LoadByteUnsigned")
	{
		// LoadByteUnsigned,Address
		if (param1 != "null")
		{
			try {
				Address = Str2Num(param1);
				Value = psxMem.LoadByteUnsigned(Address);
			}
			catch (PSXException e)
			{
				e.Report();
				return;
			}
			cout << PTAGS8 << Value << endl;
		}
	}
	else if (command == "LoadHalfword")
	{
		// LoadHalfword,Address
		if (param1 != "null")
		{
			try {
				Address = Str2Num(param1);
				Value = psxMem.LoadHalfword(Address);
			}
			catch (PSXException e)
			{
				e.Report();
				return;
			}
			cout << PTAGS8 << Value << endl;
		}
	}
	else if (command == "LoadHalfwordUnsigned")
	{
		// LoadHalfwordUnsigned,Address
		if (param1 != "null")
		{
			try {
				Address = Str2Num(param1);
				Value = psxMem.LoadHalfwordUnsigned(Address);
			}
			catch (PSXException e)
			{
				e.Report();
				return;
			}
			cout << PTAGS8 << Value << endl;
		}
	}
	else if (command == "LoadWord")
	{
		// LoadWord,Address
		if (param1 != "null")
		{
			try {
				Address = Str2Num(param1);
				Value = psxMem.LoadWord(Address);
			}
			catch (PSXException e)
			{
				e.Report();
				return;
			}
			cout << PTAGS8 << Value << endl;
		}
	}
	else if (command == "LoadWordLeft")
	{
		// LoadWordLeft,Address,Value
		if ((param1 != "null") && (param2 != "null"))
		{
			try {
				Address = Str2Num(param1);
				Value = Str2Num(param2);
				psxMem.LoadWordLeft(Address, Value);
			}
			catch (PSXException e)
			{
				e.Report();
				return;
			}
			cout << PTAGS8 << Value << endl;
		}
	}
	else if (command == "LoadWordRight")
	{
		// LoadWordRight,Address,Value
		if ((param1 != "null") && (param2 != "null"))
		{
			try {
				Address = Str2Num(param1);
				Value = Str2Num(param2);
				psxMem.LoadWordRight(Address, Value);
			}
			catch (PSXException e)
			{
				e.Report();
				return;
			}
			cout << PTAGS8 << Value << endl;
		}
	}
	else if (command == "LoadWordToCOP0")
	{
		// LoadWordToCOP0,Address
		if (param1 != "null")
		{
			try {
				Address = Str2Num(param1);
				Value = psxMem.LoadWordToCOP0(Address);
			}
			catch (PSXException e)
			{
				e.Report();
				return;
			}
			cout << PTAGS8 << Value << endl;
		}
	}
	else if (command == "LoadWordToCOP2")
	{
		// LoadWordToCOP2,Address
		if (param1 != "null")
		{
			try {
				Address = Str2Num(param1);
				Value = psxMem.LoadWordToCOP2(Address);
			}
			catch (PSXException e)
			{
				e.Report();
				return;
			}
			cout << PTAGS8 << Value << endl;
		}
	}
	else if (command == "StoreByte")
	{
		// StoreByte,Address,Value
		if ((param1 != "null") && (param2 != "null"))
		{
			try {
				Address = Str2Num(param1);
				Value = Str2Num(param2);
				psxMem.StoreByte(Address, Value);
			}
			catch (PSXException e)
			{
				e.Report();
				return;
			}
		}
	}
	else if (command == "StoreHalfword")
	{
		// StoreHalfword,Address,Value
		if ((param1 != "null") && (param2 != "null"))
		{
			try {
				Address = Str2Num(param1);
				Value = Str2Num(param2);
				psxMem.StoreHalfword(Address, Value);
			}
			catch (PSXException e)
			{
				e.Report();
				return;
			}
		}
	}
	else if (command == "StoreWord")
	{
		// StoreWord,Address,Value
		if ((param1 != "null") && (param2 != "null"))
		{
			try {
				Address = Str2Num(param1);
				Value = Str2Num(param2);
				psxMem.StoreWord(Address, Value);
			}
			catch (PSXException e)
			{
				e.Report();
				return;
			}
		}
	}
	else if (command == "StoreWordLeft")
	{
		// StoreWordLeft,Address,Value
		if ((param1 != "null") && (param2 != "null"))
		{
			try {
				Address = Str2Num(param1);
				Value = Str2Num(param2);
				psxMem.StoreWordLeft(Address, Value);
			}
			catch (PSXException e)
			{
				e.Report();
				return;
			}
		}
	}
	else if (command == "StoreWordRight")
	{
		// StoreWordRight,Address,Value
		if ((param1 != "null") && (param2 != "null"))
		{
			try {
				Address = Str2Num(param1);
				Value = Str2Num(param2);
				psxMem.StoreWordRight(Address, Value);
			}
			catch (PSXException e)
			{
				e.Report();
				return;
			}
		}
	}
	else if (command == "StoreWordFromCOP0")
	{
		// StoreWordFromCOP0,Address,Value
		if ((param1 != "null") && (param2 != "null"))
		{
			try {
				Address = Str2Num(param1);
				Value = Str2Num(param2);
				psxMem.StoreWordFromCOP0(Address, Value);
			}
			catch (PSXException e)
			{
				e.Report();
				return;
			}
		}
	}
	else if (command == "StoreWordFromCOP2")
	{
		// StoreWordFromCOP2,Address,Value
		if ((param1 != "null") && (param2 != "null"))
		{
			try {
				Address = Str2Num(param1);
				Value = Str2Num(param2);
				psxMem.StoreWordFromCOP2(Address, Value);
			}
			catch (PSXException e)
			{
				e.Report();
				return;
			}
		}
	}
	else if (command == "Copy")
	{
		// Copy,StartPC,EndPC,DestPC
		if ((param1 != "null") && (param2 != "null") && (param3 != "null"))
		{
			try {
				StartPC = Str2Num(param1);
				EndPC = Str2Num(param2);
				DestPC = Str2Num(param3);
				psxMem.Copy(StartPC, EndPC, DestPC);
			}
			catch (PSXException e)
			{
				e.Report();
				return;
			}
		}
	}
	else if (command == "ImportBIOS")
	{
		// ImportBIOS,BIOS
		if (param1 != "null")
		{
			try {
				psxMem.ImportBIOS(param1.c_str());
			}
			catch (PSXException e)
			{
				e.Report();
				return;
			}
		}
	}
	else if (command == "ImportEXE")
	{
		// ImportEXE,EXE
		if (param1 != "null")
		{
			return;
		}
	}
	else if (command == "Export")
	{
		// Export,SFile,StartPC,EndPC
		if ((param1 != "null") && (param2 != "null") && (param3 != "null"))
		{
			try {
				StartPC = Str2Num(param2);
				EndPC = Str2Num(param3);
				psxMem.Export(param1.c_str(), StartPC, EndPC);
			}
			catch (PSXException e)
			{
				e.Report();
				return;
			}
		}
	}
	else if (command == "Backup")
	{
		// Backup,SFile
		if (param1 != "null")
		{
			try {
				psxMem.Backup(param1.c_str());
			}
			catch (PSXException e)
			{
				e.Report();
				return;
			}
		}
	}
	else if (command == "Restore")
	{
		// Restore,SFile
		if (param1 != "null")
		{
			try {
				psxMem.Restore(param1.c_str());
			}
			catch (PSXException e)
			{
				e.Report();
				return;
			}
		}
	}
	else if (command == "ResetMem")
	{
		// ResetMem
		psxMem.ResetMem();
	}
	else
	{
		// Unknown
		cerr << ERROR_UNKNOWN_PSMEM_CMD << endl;
	}
}
