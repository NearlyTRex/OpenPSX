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
#ifndef DECOUTPUT_H
#define DECOUTPUT_H

// ----------------------------------------------Getting the addresses---------------------------------------------------------------------------------

// Get BCOND address
#define GETBCONDADDR   vAddr = (PC + (SImm * 4))

// Get JAL/J address
#define GETJJALADDR    vAddr = ((PC & 0xF0000000) | (target << 2))

// ----------------------------------------------Shift operations--------------------------------------------------------------------------------------

// rd = rt << shamt;
#define WRITESLL    WRITEOUT << rd << EQUALS << rt << LSHIFT << SHAMT << END

// rd = rt >> shamt;
#define WRITESRL    WRITEOUT << rd << EQUALS << rt << RSHIFT << SHAMT << END

// rd = (INT32)rt >> shamt;
#define WRITESRA    WRITEOUT << rd << EQUALS << PAROPEN << "INT32" << PARCLOS << rt << RSHIFT << SHAMT << END

// rd = rt << (rs & 31);
#define WRITESLLV   WRITEOUT << rd << EQUALS << rt << LSHIFT << PAROPEN << rs << BAND << "31" << PARCLOS << END

// rd = rt >> (rs & 31);
#define WRITESRLV   WRITEOUT << rd << EQUALS << rt << RSHIFT << PAROPEN << rs << BAND << "31" << PARCLOS << END

// rd = (INT32)rt >> (rs & 31);
#define WRITESRAV   WRITEOUT << rd << EQUALS << PAROPEN << "INT32" << PARCLOS << rt << RSHIFT << PAROPEN << rs << BAND << "31" << PARCLOS << END

// ----------------------------------------------HI/LO operations--------------------------------------------------------------------------------------

// rd = HI;
#define WRITEMFHI   WRITEOUT << rd << EQUALS << HI << END

// HI = rd;
#define WRITEMTHI   WRITEOUT << HI << EQUALS << rd << END

// rd = LO;
#define WRITEMFLO   WRITEOUT << rd << EQUALS << LO << END

// LO = rd;
#define WRITEMTLO   WRITEOUT << LO << EQUALS << rd << END

// ----------------------------------------------Mult/Div operations----------------------------------------------------------------------------------

// Mult(rs, rt);
#define WRITEMULT   WRITEOUT << "Mult" << PAROPEN << rs << COMMA << rt << PARCLOS << END

// MultU(rs, rt);
#define WRITEMULTU  WRITEOUT << "MultU" << PAROPEN << rs << COMMA << rt << PARCLOS << END

// Div(rs, rt);
#define WRITEDIV    WRITEOUT << "Div" << PAROPEN << rs << COMMA << rt << PARCLOS << END

// DivU(rs, rt);
#define WRITEDIVU   WRITEOUT << "DivU" << PAROPEN << rs << COMMA << rt << PARCLOS << END

// ----------------------------------------------Math & Binary operations-----------------------------------------------------------------------------

// rd = rs + rt;
#define WRITEADD    WRITEOUT << rd << EQUALS << rs << PLUS << rt << CLOSE << TRAPOVFLOW << ENDL

// rd = rs - rt;
#define WRITESUB    WRITEOUT << rd << EQUALS << rs << MINUS << rt << CLOSE << TRAPOVFLOW << ENDL

// rd = rs + rt;
#define WRITEADDU   WRITEOUT << rd << EQUALS << rs << PLUS << rt << END

// rd = rs - rt;
#define WRITESUBU   WRITEOUT << rd << EQUALS << rs << MINUS << rt << END

// rd = rs & rt;
#define WRITEAND    WRITEOUT << rd << EQUALS << rs << BAND << rt << END

// rd = rs | rt;
#define WRITEOR     WRITEOUT << rd << EQUALS << rs << BOR << rt << END

// rd = rs ^ rt;
#define WRITEXOR    WRITEOUT << rd << EQUALS << rs << BXOR << rt << END

// rd = ~(rs | rt);
#define WRITENOR    WRITEOUT << rd << EQUALS << BNOT << PAROPEN << rs << BOR << rt << PARCLOS << END

// ----------------------------------------------Inequality operations------------------------------------------------------------------------------

// rd = ((INT32)rs < (INT32)rt);
#define WRITESLT    WRITEOUT << rd << EQUALS << PAROPEN << PAROPEN << "INT32" << PARCLOS << rs << LT << PAROPEN << "INT32" << PARCLOS << rt << PARCLOS << END

// rd = rs < rt;
#define WRITESLTU   WRITEOUT << rd << EQUALS << rs << LT << rt << END

// ----------------------------------------------Immediate math & binary operations-----------------------------------------------------------------

// rt = rs + SImm;
#define WRITEADDI   WRITEOUT << rt << EQUALS << rs << PLUS << SIMM << CLOSE << TRAPOVFLOW << ENDL

// rt = rs + SImm;
#define WRITEADDIU  WRITEOUT << rt << EQUALS << rs << PLUS << SIMM << END

// rt = ((INT32)rs < SImm);
#define WRITESLTI   WRITEOUT << rt << EQUALS << PAROPEN << PAROPEN << "INT32" << PARCLOS << rs << LT << SIMM << PARCLOS << END

// rt = rs < SImm;
#define WRITESLTIU  WRITEOUT << rt << EQUALS << rs << LT << SIMM << END

// rt = rs & UImm;
#define WRITEANDI   WRITEOUT << rt << EQUALS << rs << BAND << UIMM << END

// rt = rs | UImm;
#define WRITEORI    WRITEOUT << rt << EQUALS << rs << BOR << UIMM << END

// rt = rs ^ UImm;
#define WRITEXORI   WRITEOUT << rt << EQUALS << rs << BXOR << UIMM << END

// rt = (UImm << 16);
#define WRITELUI    WRITEOUT << rt << EQUALS << PTAGS8 << (UImm << 16) << END

// ----------------------------------------------Function call operations-----------------------------------------------------------------------------

// goto vAddr;
#define WRITEJ      WRITEOUT << "goto" << SPACE << PNONOX << vAddr << END

// Function_vAddr_();
#define WRITEJAL    WRITEOUT << "Function_" << VADDR << "_()" << END

// Function_vAddr_(); // function()
#define WRITEFUNCT  WRITEOUT << "Function_" << VADDR << "_()" << CLOSE << " // " << function << "()" << ENDL

// return;
#define WRITERET    WRITEOUT << "return" << END

// JumpRegister(rs);
#define WRITEJR     WRITEOUT << "JumpRegister" << PAROPEN << rs << PARCLOS << END

// JumpandLinkRegister(rs, rd);
#define WRITEJALR   WRITEOUT << "JumpandLinkRegister" << PAROPEN << rs << COMMA << rd << PARCLOS << END

// ----------------------------------------------BCOND operations--------------------------------------------------------------------------------------

// if (rs == rt) { goto vAddr; }
#define WRITEBEQ    WRITEOUT << "if" << SPACE << PAROPEN << rs << ISEQ << rt << PARCLOS << SPACE << BR2OPEN << SPACE << "goto" << SPACE << PNONOX << vAddr << CLOSE << SPACE << BR2CLOS << END

// if (rs != rt) { goto vAddr; }
#define WRITEBNE    WRITEOUT << "if" << SPACE << PAROPEN << rs << NOTEQ << rt << PARCLOS << SPACE << BR2OPEN << SPACE << "goto" << SPACE << PNONOX << vAddr << CLOSE << SPACE << BR2CLOS << END

// if (rs <= 0) { goto vAddr; }
#define WRITEBLEZ   WRITEOUT << "if" << SPACE << PAROPEN << rs << LTE << "0" << PARCLOS << SPACE << BR2OPEN << SPACE << "goto" << SPACE << PNONOX << vAddr << CLOSE << SPACE << BR2CLOS << END

// if (rs > 0) { goto vAddr; }
#define WRITEBGTZ   WRITEOUT << "if" << SPACE << PAROPEN << rs << GT << "0" << PARCLOS << SPACE << BR2OPEN << SPACE << "goto" << SPACE << PNONOX << vAddr << CLOSE << SPACE << BR2CLOS << END

// if (rs < 0) { goto vAddr; }
#define WRITEBLTZ   WRITEOUT << "if" << SPACE << PAROPEN << rs << LT << "0" << PARCLOS << SPACE << BR2OPEN << SPACE << "goto" << SPACE << PNONOX << vAddr << CLOSE << SPACE << BR2CLOS << ENDL

// if (rs >= 0) { goto vAddr; }
#define WRITEBGEZ   WRITEOUT << "if" << SPACE << PAROPEN << rs << GE << "0" << PARCLOS << SPACE << BR2OPEN << SPACE << "goto" << SPACE << PNONOX << vAddr << CLOSE << SPACE << BR2CLOS << ENDL

// if (rs < 0) { Function_vAddr_(); }
#define WRITEBLTZAL WRITEOUT << "if" << SPACE << PAROPEN << rs << LT << "0" << PARCLOS << SPACE << BR2OPEN << SPACE << "Function_" << VADDR << "_()" << CLOSE << SPACE << BR2CLOS << ENDL

// if (rs >= 0) { Function_vAddr_(); }
#define WRITEBGEZAL WRITEOUT << "if" << SPACE << PAROPEN << rs << GE << "0" << PARCLOS << SPACE << BR2OPEN << SPACE << "Function_" << VADDR << "_()" << CLOSE << SPACE << BR2CLOS << ENDL

// ----------------------------------------------COP0 Register operations---------------------------------------------------------------------------

// rt = COP0Regs[rdnum];
#define WRITEMF0    WRITEOUT << rt << EQUALS << COP0Regs[rdnum] << END

// rt = COP0Control[rdnum];
#define WRITECF0    WRITEOUT << rt << EQUALS << "COP0Control" << BRAOPEN << RDNUM << BRACLOS << END

// COP0Regs[rdnum] = rt;
#define WRITEMT0    WRITEOUT << COP0Regs[rdnum] << EQUALS << rt << END

// COP0Control[rdnum] = rt;
#define WRITECT0    WRITEOUT << "COP0Control" << BRAOPEN << RDNUM << BRACLOS << EQUALS << rt << END

// ---------------------------------------------COP2 Register operations-----------------------------------------------------------------------------

// rt = COP2Regs[rdnum];
#define WRITEMF2    WRITEOUT << rt << EQUALS << COP2Regs[rdnum]    << END

// rt = COP2Control[rdnum];
#define WRITECF2    WRITEOUT << rt << EQUALS << COP2Control[rdnum] << END

// COP2Regs[rdnum] = rt;
#define WRITEMT2    WRITEOUT << COP2Regs[rdnum]    << EQUALS << rt << END

// COP2Control[rdnum] = rt;
#define WRITECT2    WRITEOUT << COP2Control[rdnum] << EQUALS << rt << END

// --------------------------------------------System operations-----------------------------------------------------------------------------

// BCC0();
#define WRITEBCC0   WRITEOUT << "BCC0()" << END

// BCC2();
#define WRITEBC2    WRITEOUT << "BCC2()" << END

// SystemCall(code);
#define WRITESYSCALL WRITEOUT << "SystemCall" << PAROPEN << CODE << PARCLOS << END

// SignalException(Breakpoint);
#define WRITEBREAK  WRITEOUT  << "SignalException" << PAROPEN << "Breakpoint" << PARCLOS << END

// Cop2(Opcode & 0x01FFFFFF);
#define WRITECOP2   WRITEOUT  << "Cop2" << PAROPEN << PTAGS8 << (Opcode & 0x01FFFFFF) << PARCLOS << END

// -------------------------------------------Load operations-----------------------------------------------------------------------------------

// rt = psMem.LoadByte(rs + SImm);
#define WRITELB    WRITEOUT << rt << EQUALS << "psMem.LoadByte"             << PAROPEN << rs << PLUS << SIMM << PARCLOS << END

// rt = psMem.LoadHalfword(rs + SImm);
#define WRITELH    WRITEOUT << rt << EQUALS << "psMem.LoadHalfword"         << PAROPEN << rs << PLUS << SIMM << PARCLOS << END

// rt = psMem.LoadWord(rs + SImm);
#define WRITELW    WRITEOUT << rt << EQUALS << "psMem.LoadWord"             << PAROPEN << rs << PLUS << SIMM << PARCLOS << END

// rt = psMem.LoadByteUnsigned(rs + SImm);
#define WRITELBU   WRITEOUT << rt << EQUALS << "psMem.LoadByteUnsigned"     << PAROPEN << rs << PLUS << SIMM << PARCLOS << END

// rt = psMem.LoadHalfwordUnsigned(rs + SImm);
#define WRITELHU   WRITEOUT << rt << EQUALS << "psMem.LoadHalfwordUnsigned" << PAROPEN << rs << PLUS << SIMM << PARCLOS << END

// psMem.LoadWordRight((rs + SImm), rt);
#define WRITELWR   WRITEOUT << "psMem.LoadWordRight" << PAROPEN << PAROPEN << rs << PLUS << SIMM << PARCLOS << COMMA << rt << PARCLOS << END

// psMem.LoadWordLeft((rs + SImm), rt);
#define WRITELWL   WRITEOUT << "psMem.LoadWordLeft"  << PAROPEN << PAROPEN << rs << PLUS << SIMM << PARCLOS << COMMA << rt << PARCLOS << END

// --------------------------------------------Store operations------------------------------------------------------------------------------------

// psMem.StoreByte((rs + SImm), rt);
#define WRITESB     WRITEOUT << "psMem.StoreByte"      << PAROPEN << PAROPEN << rs << PLUS << SIMM << PARCLOS << COMMA << rt << PARCLOS << END

// psMem.StoreHalfword((rs + SImm), rt);
#define WRITESH     WRITEOUT << "psMem.StoreHalfword"  << PAROPEN << PAROPEN << rs << PLUS << SIMM << PARCLOS << COMMA << rt << PARCLOS << END

// psMem.StoreWordLeft((rs + SImm), rt);
#define WRITESWL    WRITEOUT << "psMem.StoreWordLeft"  << PAROPEN << PAROPEN << rs << PLUS << SIMM << PARCLOS << COMMA << rt << PARCLOS << END

// psMem.StoreWord((rs + SImm), rt);
#define WRITESW     WRITEOUT << "psMem.StoreWord"      << PAROPEN << PAROPEN << rs << PLUS << SIMM << PARCLOS << COMMA << rt << PARCLOS << END

// psMem.StoreWordRight((rs + SImm), rt);
#define WRITESWR    WRITEOUT << "psMem.StoreWordRight" << PAROPEN << PAROPEN << rs << PLUS << SIMM << PARCLOS << COMMA << rt << PARCLOS << END

// ---------------------------------------------COP0 memory operations----------------------------------------------------------------------------------

// COP0Regs[rtnum] = psMem.LoadWordToCOP0(rs + SImm);
#define WRITELWC0   WRITEOUT << COP0Regs[rtnum] << EQUALS << "psMem.LoadWordToCOP0" << PAROPEN << rs << PLUS << SIMM << PARCLOS << END

// COP2Regs[rtnum] = psMem.LoadWordToCOP2(rs + SImm);
#define WRITELWC2   WRITEOUT << COP2Regs[rtnum] << EQUALS << "psMem.LoadWordToCOP2" << PAROPEN << rs << PLUS << SIMM << PARCLOS << END

// --------------------------------------------COP2 memory operations-----------------------------------------------------------------------------------

// psMem.StoreWordFromCOP0((rs + SImm), COP0Regs[rtnum]);
#define WRITESWC0   WRITEOUT << "psMem.StoreWordFromCOP0" << PAROPEN << PAROPEN << rs << PLUS << SIMM << PARCLOS << COMMA << COP0Regs[rtnum] << PARCLOS << END

// psMem.StoreWordFromCOP2((rs + SImm), COP2Regs[rtnum]);
#define WRITESWC2   WRITEOUT << "psMem.StoreWordFromCOP2" << PAROPEN << PAROPEN << rs << PLUS << SIMM << PARCLOS << COMMA << COP2Regs[rtnum] << PARCLOS << END

#endif
