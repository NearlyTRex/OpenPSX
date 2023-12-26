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
#ifndef DEFS_H
#define DEFS_H

// Typedefs
typedef std::vector<std::string> vectorType;
typedef vectorType::const_iterator const_iterator;
typedef vectorType::size_type size_type;

typedef std::map<std::string, UINT32, std::less<std::string> > regType;

// Error messages
#define ERROR_GENERAL                "Error00: General exception"
#define ERROR_OUT_OF_RANGE           "Error01: Index out of range"
#define ERROR_COULD_NOT_FIND_BIOS    "Error02: Could not locate BIOS image"
#define ERROR_COULD_NOT_FIND_EXE     "Error03: Could not locate EXE image"
#define ERROR_COULD_NOT_FIND_SF      "Error04: Could not locate SFile"
#define ERROR_COULD_NOT_FIND_IFILE   "Error05: Could not locate Infile"
#define ERROR_IMAGE_NOT_A_BIOS       "Error06: Given image is not a BIOS"
#define ERROR_IMAGE_NOT_AN_EXE       "Error07: Given image is not an EXE"
#define ERROR_IMAGE_NOT_AN_SFILE     "Error08: Given image is not an SFile"
#define ERROR_IMAGE_NOT_AN_IFILE     "Error09: Given image is not an Infile"
#define ERROR_COULD_NOT_WRITE_SFILE  "Error10: Could not write given SFile"
#define ERROR_COULD_NOT_WRITE_OFILE  "Error11: Could not write given Outfile"
#define ERROR_GIVEN_ADDR_UNALIGNED   "Error12: Given address is unaligned"
#define ERROR_GIVEN_ADDRS_UNALIGNED  "Error13: Given addresses are unaligned"
#define ERROR_GIVEN_ADDR_INVALID     "Error14: Given address or value is invalid"
#define ERROR_GIVEN_ADDRS_INVALID    "Error15: Given addresses or values are invalid"
#define ERROR_START_BEFORE_END       "Error16: Start address must come before End address"
#define ERROR_NOT_SAME_SEGMENT       "Error17: Start and End addresses must be in the same memory segment"
#define ERROR_NEEDS_GOOD_HEX_NUM     "Error18: Address or value must be a hexadecimal address of 8 digits"
#define ERROR_CANT_ALLOCATE_SIM_MEM  "Error19: Simulated memory could not be allocated"
#define ERROR_NOT_ENOUGH_MEMORY      "Error20: Host system does not have enough memory"
#define ERROR_UNKNOWN_PSMEM_CMD      "Error21: Unknown command in module PSMem"
#define ERROR_UNKNOWN_PSFUNC_CMD     "Error22: Unknown command in module PSFunc"
#define ERROR_UNKNOWN_DIMAGE_CMD     "Error23: Unknown command in module DImage"
#define ERROR_UNKNOWN_CMD_OR_MOD     "Error24: Unknown command or module"
#define ERROR_KEY_NOT_FOUND          "Error25: Given key was not found in database"
#define ERROR_ELEMENT_NOT_FOUND      "Error26: There was no element at given key"

#endif
