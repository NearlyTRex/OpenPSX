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

// Base StringTokenizer class by:
// Author: Daniel Karrels dan@karrels.com
// Copyright (C) 2002 Daniel Karrels <dan@karrels.com>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,
// USA.
//
// $Id: StringTokenizerTokenize.cpp,v 1.2 2002/12/19 06:09:44 alaterale Exp $

#include "Include/Main.h"
using namespace std;

void StringTokenizer::Tokenize(const string& buf)
{
	// Make sure that there is something worth tokenizing
	if (buf.empty())
	{
		return;
	}

	// addMe is the string which will be added to the vector
	// Initialize it to buf.size() empty characters to speed
	// up addition of characters onto the string
	// This method is only called once for the life of this object,
	// so no need for memory of any kind here.
	char* addMe = new (std::nothrow) char[buf.size() + 1] ;
	assert(addMe != 0);
	addMe[0] = 0;

	// (addMePtr) is used to walk down the addMe buffer, adding new
	// characters to the end.
	// (addMePtr) always points to the next location in the addMe ptr
	// in which a character may be placed.
	char* addMePtr = addMe;

	// Iterate through the entire string
	for(string::const_iterator currentPtr = buf.begin(); currentPtr != buf.end(); ++currentPtr)
	{

		// Is this the delimiter for which we are searching?
		if (delimiter == *currentPtr)
		{
			// We have reached a delimiter
			// Null terminate the token
			*addMePtr = 0;

			// Is this an empty token?
			if (addMe[0] != 0)
			{
				// Nope, go ahead and add it to the vector
				array.push_back(addMe);

				addMePtr = addMe;
				*addMePtr = 0;
			}
		}

		// Otherwise, no delimiter was found...just add this
		// character to addMe
		else
		{
			*addMePtr = *currentPtr;
			++addMePtr;
		}
	}

	// Null terminate, if necessary
	*addMePtr = 0;

	// currentPtr == endPtr
	// Make sure to check for last token
	if (addMe[ 0 ] != 0)
	{
		array.push_back( addMe );
	}

	// This point is always reached, excluding a crash
	delete[] addMe;
}
