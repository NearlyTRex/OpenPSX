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
#ifndef PRINTTAGS_H
#define PRINTTAGS_H

#define BAND        " & "
#define LAND        " && "
#define BOR         " | "
#define LOR         " || "
#define BXOR        " ^ "
#define BNOT        "~"
#define PLUS        " + "
#define MINUS       " - "
#define EQUALS      " = "
#define RSHIFT      " >> "
#define LSHIFT      " << "
#define LT          " < "
#define LTE         " <= "
#define GT          " > "
#define GE          " >= "
#define ISEQ        " == "
#define NOTEQ       " != "
#define SPACE       " "
#define COMMA       ", "
#define PAROPEN     "("
#define PARCLOS     ")"
#define BRAOPEN     "["
#define BRACLOS     "]"
#define BR2OPEN     "{"
#define BR2CLOS     "}"
#define HI          "HI"
#define LO          "LO"
#define CLOSE       ";"
#define END         ";" << endl;
#define ENDL        endl
#define TRAPOVFLOW  " // Trap on 2's comp overflow"

#define PTAGS4      setiosflags(ios::uppercase) << "0x" << setfill('0') << setw(4) << hex
#define PTAGS5      setiosflags(ios::uppercase) << "0x" << setfill('0') << setw(5) << hex
#define PTAGS8      setiosflags(ios::uppercase) << "0x" << setfill('0') << setw(8) << hex
#define PTAGSD      dec
#define PNONOX      setiosflags(ios::uppercase) << setfill('0') << setw(8) << hex
#define SIMM        PTAGS4 << SImm
#define UIMM        PTAGS4 << UImm
#define CODE        PTAGS5 << code
#define VADDR       PTAGS8 << vAddr
#define RTNUM       PTAGSD << rtnum
#define RDNUM       PTAGSD << rdnum
#define RSNUM       PTAGSD << rsnum
#define SHAMT       PTAGSD << shamt
#define PRELIM      PNONOX << PC << ": /* " << PTAGS8 << Opcode << " : " << printstring << " */ "
#define WRITEOUT    Decfile << setiosflags(ios::uppercase) << PRELIM
#define WRITENOT    WRITEOUT << ENDL

#endif
