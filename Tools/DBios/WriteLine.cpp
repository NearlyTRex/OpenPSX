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

// ===========================================================
// Function - DBios::WriteLine
// Use - Given a PC and Opcode, disassembles/decompiles and writes a line to file
// ===========================================================
int DBios::WriteLine(UINT32 Opcode, UINT32 PC, char* string)
{
	UINT32 vAddr;

	char* Regs[] =
	{
		"ZR", "AT", "V0", "V1", "A0", "A1", "A2", "A3",
		"T0", "T1", "T2", "T3", "T4", "T5", "T6", "T7",
		"S0", "S1", "S2", "S3", "S4", "S5", "S6", "S7",
		"T8", "T9", "K0", "K1", "GP", "SP", "FP", "RA"
	};

	char* COP0Regs[] =
	{
		"INDX", "RAND", "TLBL", "BPC", "CTXT", "BDA", "PIDMASK", "DCIC",
		"BADV", "BDAM", "TLBH", "BPCM", "SR", "CAUSE", "EPC", "PRID", "ERREG"
	};

	switch(op)
	{
	case SPECIAL:
		switch(funct)
		{
		case SLL:
			// rd = rt << shamt;
			if ((rdnum == 0) && (rtnum == 0) && (shamt == 0))
			{
				Decfile << PRELIM << endl;
			}
			else
			{
				Decfile << PRELIM << rd << EQUALS << rt << LSHIFT << shamt << END;
			}
			break;
		case SRL:
			// rd = rt >> shamt;
			Decfile << PRELIM << rd << EQUALS << rt << RSHIFT << shamt << END;
			break;
		case SRA:
			// rd = (INT32)rt >> shamt;
			Decfile << PRELIM << rd << EQUALS << "(INT32)" << rt << RSHIFT << shamt << END;
			break;
		case SLLV:
			// rd = rt << (rs & 31);
			Decfile << PRELIM << rd << EQUALS << rt << LSHIFT << "(" << rs << BAND << "31)" << END;
			break;
		case SRLV:
			// rd = rt >> (rs & 31);
			Decfile << PRELIM << rd << EQUALS << rt << RSHIFT << "(" << rs << BAND << "31)" << END;
			break;
		case SRAV:
			// rd = (INT32)rt >> (rs & 31);
			Decfile << PRELIM << rd << EQUALS << "(INT32)" << rt << RSHIFT << "(" << rs << BAND << "31)" << END;
			break;
		case JR:
			// return;
			if (rsnum == 31)
			{
				Decfile << PRELIM << "return" << END;
			}
			else
			{
				Decfile << PRELIM << "JumpRegister(" << rs << ")" << END;
			}
			break;
		case JALR:
			// JumpandLinkRegister(rs, rd);
			Decfile << PRELIM << "JumpandLinkRegister(" << rs << COMMA << rd << ")" << END;
			break;
		case SYSCALL:
			// SystemCall(code);
			Decfile << PRELIM << "SystemCall(" << CODE << ")" << END;
			break;
		case BREAK:
			// SignalException(Breakpoint);
			Decfile << PRELIM << "SignalException(Breakpoint)" << END;
			break;
		case MFHI:
			// rd = HI;
			Decfile << PRELIM << rd << EQUALS << HI << END;
			break;
		case MTHI:
			// HI = rd;
			Decfile << PRELIM << HI << EQUALS << rd << END;
			break;
		case MFLO:
			// rd = LO;
			Decfile << PRELIM << rd << EQUALS << LO << END;
			break;
		case MTLO:
			// LO = rd;
			Decfile << PRELIM << LO << EQUALS << rd << END;
			break;
		case MULT:
			// Mult(rs, rt);
			Decfile << PRELIM << "Mult(" << rs << COMMA << rt << ")" << END;
			break;
		case MULTU:
			// MultU(rs, rt);
			Decfile << PRELIM << "MultU(" << rs << COMMA << rt << ")" << END;
			break;
		case DIV:
			// Div(rs, rt);
			Decfile << PRELIM << "Div(" << rs << COMMA << rt << ")" << END;
			break;
		case DIVU:
			// DivU(rs, rt);
			Decfile << PRELIM << "DivU(" << rs << COMMA << rt << ")" << END;
			break;
		case ADD:
			// rd = rs + rt;
			Decfile << PRELIM << rd << EQUALS << rs << PLUS << rt << END;
			break;
		case ADDU:
			// rd = rs + rt;
			Decfile << PRELIM << rd << EQUALS << rs << PLUS << rt << END;
			break;
		case SUB:
			// rd = rs - rt;
			Decfile << PRELIM << rd << EQUALS << rs << MINUS << rt << END;
			break;
		case SUBU:
			// rd = rs - rt;
			Decfile << PRELIM << rd << EQUALS << rs << MINUS << rt << END;
			break;
		case AND:
			// rd = rs & rt;
			Decfile << PRELIM << rd << EQUALS << rs << BAND << rt << END;
			break;
		case OR:
			// rd = rs | rt;
			Decfile << PRELIM << rd << EQUALS << rs << BOR << rt << END;
			break;
		case XOR:
			// rd = rs ^ rt;
			Decfile << PRELIM << rd << EQUALS << rs << BXOR << rt << END;
			break;
		case NOR:
			// rd = ~(rs | rt);
			Decfile << PRELIM << rd << EQUALS << BNOT << "(" << rs << BOR << rt << ")" << END;
			break;
		case SLT:
			// rd = ((INT32)rs < (INT32)rt);
			Decfile << PRELIM << rd << EQUALS << "(" << "(INT32)" << rs << LT << "(INT32)" << rt << ")" << END;
			break;
		case SLTU:
			// rd = rs < rt;
			Decfile << PRELIM << rd << EQUALS << rs << LT << rt << END;
			break;
		default:
			// By default, write nothing
			Decfile << PRELIM << endl;
			break;
		}
		break;
	case BCOND:
		vAddr = ((INT32)(UImm << 2)) + (PC + 4);
		switch(rtnum)
		{
		case BLTZ:
			// if (rs < 0) { goto vAddr; }
			Decfile << PRELIM << "if (" << rs << LT << "0) { goto " << VADDR << "; }" << END;
			break;
		case BGEZ:
			// if (rs >= 0) { goto vAddr; }
			Decfile << PRELIM << "if (" << rs << GE << "0) { goto " << VADDR << "; }" << END;
			break;
		case BLTZAL:
			// if (rs < 0) { Function_vAddr_(); }
			Decfile << PRELIM << "if (" << rs << LT << "0) { Function_" << VADDR << "_(); }" << END;
			break;
		case BGEZAL:
			// if (rs >= 0) { Function_vAddr_(); }
			Decfile << PRELIM << "if (" << rs << GE << "0) { Function_" << VADDR << "_(); }" << END;
			break;
		default:
			// By default, write nothing
			Decfile << PRELIM << endl;
			break;
		}
		break;
	case J:
		// goto vAddr;
		vAddr = ((PC & 0xF0000000) | (target << 2));
		Decfile << PRELIM << "goto " << VADDR << END;
		break;
	case JAL:
		// Function_vAddr_();
		vAddr = ((PC & 0xF0000000) | (target << 2));
		Decfile << PRELIM << "Function_" << VADDR << "_()" << END;
		break;
	case BEQ:
		// if (rs == rt) { goto vAddr; }
		vAddr = ((INT32)(UImm << 2)) + (PC + 4);
		Decfile << PRELIM << "if (" << rs << ISEQ << rt << ") { goto " << VADDR << "; }" << END;
		break;
	case BNE:
		// if (rs != rt) { goto vAddr; }
		vAddr = (PC + 4) + ((INT16)(UImm << 2));
		Decfile << PRELIM << "if (" << rs << NOTEQ << rt << ") { goto " << VADDR << "; }" << END;
		break;
	case BLEZ:
		// if (rs <= 0) { goto vAddr; }
		vAddr = ((INT32)(UImm << 2)) + (PC + 4);
		Decfile << PRELIM << "if (" << rs << LTE << "0) { goto " << VADDR << "; }" << END;
		break;
	case BGTZ:
		// if (rs > 0) { goto vAddr; }
		vAddr = ((INT32)(UImm << 2)) + (PC + 4);
		Decfile << PRELIM << "if (" << rs << GT << "0) { goto " << VADDR << "; }" << END;
		break;
	case ADDI:
		// rt = rs + SImm;
		Decfile << PRELIM << rt << EQUALS << rs << PLUS << SIMM << END;
		break;
	case ADDIU:
		// rt = rs + SImm;
		Decfile << PRELIM << rt << EQUALS << rs << PLUS << SIMM << END;
		break;
	case SLTI:
		// rt = ((INT32)rs < SImm);
		Decfile << PRELIM << rt << EQUALS << "((INT32)" << rs << LT << SIMM << END;
		break;
	case SLTIU:
		// rt = rs < SImm;
		Decfile << PRELIM << rt << EQUALS << rs << LT << SIMM << END;
		break;
	case ANDI:
		// rt = rs & UImm;
		Decfile << PRELIM << rt << EQUALS << rs << BAND << UIMM << END;
		break;
	case ORI:
		// rt = rs | UImm;
		Decfile << PRELIM << rt << EQUALS << rs << BOR << UIMM << END;
		break;
	case XORI:
		// rt = rs ^ UImm;
		Decfile << PRELIM << rt << EQUALS << rs << BXOR << UIMM << END;
		break;
	case LUI:
		// rt = (UImm << 16);
		Decfile << PRELIM << rt << EQUALS << UIMM << "0000" << END;
		break;
	case COP0:
		// COPz(0)
		switch(rsnum)
		{
		case MF:
			// rt = COP0Regs[rdnum];
			Decfile << PRELIM << rt << EQUALS << COP0Regs[rdnum] << END;
			break;
		case CF:
			// rt = COP0Control[rdnum];
			Decfile << PRELIM << rt << EQUALS << "COP0Control[" << rdnum << "]" << END;
			break;
		case MT:
			// COP0Regs[rdnum] = rt;
			Decfile << PRELIM << COP0Regs[rdnum] << EQUALS << rt << END;
			break;
		case CT:
			// COP0Control[rdnum] = rt;
			Decfile << PRELIM << "COP0Control[" << rdnum << "]" << EQUALS << rt << END;
			break;
		case BC:
			// BCC0();
			Decfile << PRELIM << "BCC0()" << END;
			break;
		default:
			// By default, write nothing
			Decfile << PRELIM << endl;
			break;
		}
		break;
	case COP2:
		if (rsnum & 0x10)
		{
			// Cop2(Opcode & 0x01FFFFFF);
			Decfile << PRELIM << "Cop2(" << PTAGS8 << (Opcode & 0x01FFFFFF) << ")" << END;
		}
		else
		{
			switch(rsnum)
			{
			case MF:
				// rt = COP2[rdnum];
				Decfile << PRELIM << rt << EQUALS << "COP2[" << rdnum << "]" << END;
				break;
			case CF:
				// rt = COP2Control[rdnum];
				Decfile << PRELIM << rt << EQUALS << "COP2Control[" << rdnum << "]" << END;
				break;
			case MT:
				// COP2[rdnum] = rt;
				Decfile << PRELIM << "COP2[" << rdnum << "]" << EQUALS << rt << END;
				break;
			case CT:
				// COP2Control[rdnum] = rt;
				Decfile << PRELIM << "COP2Control[" << rdnum << "]" << EQUALS << rt << END;
				break;
			case BC:
				// BCC2();
				Decfile << PRELIM << "BCC2()" << END;
				break;
			default:
				Decfile << PRELIM << endl;
				break;
			}
			break;
		}
		break;
	case LB:
		// rt = (INT8)MemRead8(rs + SImm);
		Decfile << PRELIM << rt << EQUALS << "(INT8)MemRead8(" << rs << PLUS << SIMM << ")" << END;
		break;
	case LH:
		// rt = (INT16)MemRead16(rs + SImm);
		Decfile << PRELIM << rt << EQUALS << "(INT16)MemRead16(" << rs << PLUS << SIMM << ")" << END;
		break;
	case LWL:
		// LWL(rt, rs, SImm);
		Decfile << PRELIM << "LWL(" << rt << COMMA << rs << COMMA << SIMM << ")" << END;
		break;
	case LW:
		// rt = MemRead32(rs + SImm);
		Decfile << PRELIM << rt << EQUALS << "MemRead32(" << rs << PLUS << SIMM << ")" << END;
		break;
	case LBU:
		// rt = MemRead8(rs + SImm);
		Decfile << PRELIM << rt << EQUALS << "MemRead8(" << rs << PLUS << SIMM << ")" << END;
		break;
	case LHU:
		// rt = MemRead16(rs + SImm);
		Decfile << PRELIM << rt << EQUALS << "MemRead16(" << rs << PLUS << SIMM << ")" << END;
		break;
	case LWR:
		// LWR(rt, rs, SImm);
		Decfile << PRELIM << "LWR(" << rt << COMMA << rs << COMMA << SIMM << ")" << END;
		break;
	case SB:
		// MemWrite8((rs + SImm), rt);
		Decfile << PRELIM << "MemWrite8((" << rs << PLUS << SIMM << "), " << rt << ")" << END;
		break;
	case SH:
		// MemWrite16((rs + SImm), rt);
		Decfile << PRELIM << "MemWrite16((" << rs << PLUS << SIMM << "), " << rt << ")" << END;
		break;
	case SWL:
		// SWL(rt, rs, SImm);
		Decfile << PRELIM << "SWL(" << rt << COMMA << rs << COMMA << SIMM << ")" << END;
		break;
	case SW:
		// MemWrite32((rs + SImm), rt);
		Decfile << PRELIM << "MemWrite32((" << rs << PLUS << SIMM << "), " << rt << ")" << END;
		break;
	case SWR:
		// SWR(rt, rs, SImm);
		Decfile << PRELIM << "SWR(" << rt << COMMA << rs << COMMA << SIMM << ")" << END;
		break;
	case LWC0:
		// COP0Regs[rtnum] = MemRead32(rs + SImm);
		Decfile << PRELIM << COP0Regs[rtnum] << EQUALS << "MemRead32(" << rs << PLUS << SIMM << ")" << END;
		break;
	case LWC2:
		// COP2[rtnum] = MemRead32(rs + SImm);
		Decfile << PRELIM << "COP2[" << rtnum << "]" << EQUALS << "MemRead32(" << rs << PLUS << SIMM << ")" << END;
		break;
	case SWC0:
		// MemWrite32((rs + SImm), COP0Regs[rtnum]);
		Decfile << PRELIM << "MemWrite32((" << rs << PLUS << SIMM << "), " << COP0Regs[rtnum] << ")" << END;
		break;
	case SWC2:
		// MemWrite32((rs + SImm), COP2[rtnum]);
		Decfile << PRELIM << "MemWrite32((" << rs << PLUS << SIMM << "), COP2[" << rtnum << "])" << END;
		break;
	default:
		// By default, write nothing
		Decfile << PRELIM << endl;
		break;
	}

	return 0;
}
