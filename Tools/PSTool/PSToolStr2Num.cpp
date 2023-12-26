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

UINT32 Str2Num(string numberString)
{
	// Things to make sure are always in the string:
	// 1) The prefix "0x"
	// 2) There are 8 numerical digits after the prefix
	// 3) Each successive number is a valid hex number
	UINT32 result = 0x00000000;
		
	int getascii = 0;
	int temp[8] = {0,0,0,0,0,0,0,0};
	int part[8] = {0,0,0,0,0,0,0,0};
	
	if (numberString.length() != 10)
	{
		throw PSXException(ERROR_NEEDS_GOOD_HEX_NUM);
		return 0;
	}
	if ((numberString[0] == '0') && (numberString[1] == 'x'))
	{
		// It's a hex number
		for (int index = 2; index < numberString.size(); index++)
		{
			// Get ascii value
			getascii = (int)(numberString[index]);
			
			// Get real value
			if ((getascii >= '0') && (getascii <= '9'))
			{
				// Number
				temp[index - 2] = getascii - 48;
			}
			else if ((getascii >= 'A') && (getascii <= 'F'))
			{
				// Upper case hex
				temp[index - 2] = getascii - 55;
			}
			else if ((getascii >= 'a') && (getascii <= 'f'))
			{
				// Lower case hex
				temp[index - 2] = getascii - 87;
			}
			else
			{
				// It is not a valid hex digit
				throw PSXException(ERROR_NEEDS_GOOD_HEX_NUM);
				return 0;
			}
		}
	}
	else
	{
		throw PSXException(ERROR_NEEDS_GOOD_HEX_NUM);
		return 0;
	}
	// Compile into a number
	part[0] = temp[0] * 16 * 16 * 16 * 16 * 16 * 16 * 16;
	part[1] = temp[1] * 16 * 16 * 16 * 16 * 16 * 16;
	part[2] = temp[2] * 16 * 16 * 16 * 16 * 16;
	part[3] = temp[3] * 16 * 16 * 16 * 16;
	part[4] = temp[4] * 16 * 16 * 16;
	part[5] = temp[5] * 16 * 16;
	part[6] = temp[6] * 16;
	part[7] = temp[7];
	for (int y = 0; y < 8; y++)
	{
		result = result + part[y];
	}
	return result;
}
