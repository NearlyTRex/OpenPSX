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

// Error messages
#define ERROR_OUT_OF_RANGE           std::cerr << "Error: Index out of range" << std::endl
#define ERROR_COULD_NOT_FIND_BIOS    std::cerr << "Error: Could not locate BIOS image" << std::endl
#define ERROR_COULD_NOT_FIND_EXE     std::cerr << "Error: Could not locate EXE image" << std::endl
#define ERROR_COULD_NOT_FIND_SF      std::cerr << "Error: Could not locate SFile" << std::endl
#define ERROR_IMAGE_NOT_A_BIOS       std::cerr << "Error: Given image is not a BIOS" << std::endl
#define ERROR_IMAGE_NOT_AN_EXE       std::cerr << "Error: Given image is not an EXE" << std::endl
#define ERROR_IMAGE_NOT_AN_SFILE     std::cerr << "Error: Given image is not an SFile" << std::endl
#define ERROR_GIVEN_ADDR_UNALIGNED   std::cerr << "Error: Given address is unaligned" << std::endl
#define ERROR_GIVEN_ADDRS_UNALIGNED  std::cerr << "Error: Given addresses are unaligned" << std::endl
#define ERROR_GIVEN_ADDR_INVALID     std::cerr << "Error: Given address is invalid" << std::endl
#define ERROR_GIVEN_ADDRS_INVALID    std::cerr << "Error: Given addresses are invalid" << std::endl
#define ERROR_CANT_ALLOCATE_SIM_MEM  std::cerr << "Error: Simulated memory was not able to be allocated" << std::endl
#define ERROR_NOT_ENOUGH_MEMORY      std::cerr << "Error: Host system does not have enough memory" << std::endl
#define ERROR_START_BEFORE_END       std::cerr << "Error: Start address must come before End address" << std::endl
#define ERROR_NOT_SAME_SEGMENT       std::cerr << "Error: Start and End addresses must be in the same memory segment" << std::endl
#define ERROR_COULD_NOT_WRITE_SFILE  std::cerr << "Error: Could not write given SFile" << std::endl

#endif
