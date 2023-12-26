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
// $Id: StringTokenizer.h,v 1.2 2002/12/19 06:09:44 alaterale Exp $

#ifndef STRINGTOKENIZER_H
#define STRINGTOKENIZER_H

class StringTokenizer
{
public:	
	// Constructor
	StringTokenizer(const std::string& buf, char delim);
	
	// Destructor
	~StringTokenizer();
	
	// Public methods
	const std::string& getToken(const size_type& index);
	const std::string& operator[](const size_type& index);
	
	size_type size(void);
	bool empty(void);
	bool validIndex(const size_type& index);
	const_iterator begin(void);
	const_iterator end(void);
	
private:
	// Private methods
	StringTokenizer(const StringTokenizer&);
	void Tokenize(const std::string&);
		
	// Private data
	char delimiter;
	vectorType array;
	std::string nullStr;
};

#endif
