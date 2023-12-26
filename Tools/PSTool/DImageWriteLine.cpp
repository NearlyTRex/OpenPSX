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

void DImage::WriteLine(UINT32 Opcode, UINT32 PC, const char charArray[5])
{
	UINT32 vAddr;
	string printstring(charArray);
	string function;

	const string Regs[] =
	{
		"ZR", "AT", "V0", "V1", "A0", "A1", "A2", "A3",
		"T0", "T1", "T2", "T3", "T4", "T5", "T6", "T7",
		"S0", "S1", "S2", "S3", "S4", "S5", "S6", "S7",
		"T8", "T9", "K0", "K1", "GP", "SP", "FP", "RA"
	};

	const string COP0Regs[] =
	{
		"INDX" , "RAND", "TLBL", "BPC" , "CTXT", "BDA"  , "PIDMASK", "DCIC",
		"BADV" , "BDAM", "TLBH", "BPCM", "SR"  , "CAUSE", "EPC"    , "PRID",
		"ERREG", "null", "null", "null", "null", "null" , "null"   , "null",
		"null" , "null", "null", "null", "null", "null" , "null"   , "null"
	};
	
	const string COP2Regs[] =
	{
		"VXY0", "VZ0" , "VXY1", "VZ1" , "VXY2", "VZ2" , "RGB" , "OTZ" ,
		"IR0" , "IR1" , "IR2" , "IR3" , "SXY0", "SXY1", "SXY2", "SXYP",
		"SZ0" , "SZ1" , "SZ2" , "SZ3" , "RGB0", "RGB1", "RGB2", "RES1",
		"MAC0", "MAC1", "MAC2", "MAC3", "IRGB", "ORGB", "LZCS", "LZCR"
	};
	
	const string COP2Control[] =
	{
		"R11R12", "R13R21", "R22R23", "R31R32", "R33", "TRX" , "TRY" , "TRZ",
		"L11L12", "L13L21", "L22L23", "L31L32", "L33", "RBK" , "BBK" , "GBK",
		"LR1LR2", "LR3LG1", "LG2LG3", "LB1LB2", "LB3", "RFC" , "GFC" , "BFC",
		"OFX"   , "OFY"   , "H"     , "DQA"   , "DQB", "ZSF3", "ZSF4", "FLAG"
	};
	
	switch(op)
	{
	case SPECIAL:
		switch(funct)
		{
		case SLL:
			if ((rdnum == 0) && (rtnum == 0) && (shamt == 0))
			{
				WRITENOT;
			}
			else
			{
				WRITESLL;
			}
			break;
		case SRL:
			WRITESRL;
			break;
		case SRA:
			WRITESRA;
			break;
		case SLLV:
			WRITESLLV;
			break;
		case SRLV:
			WRITESRAV;
			break;
		case SRAV:
			WRITESRAV;
			break;
		case JR:
			if (rsnum == 31)
			{
				WRITERET;
			}
			else
			{
				WRITEJR;
			}
			break;
		case JALR:
			WRITEJALR;
			break;
		case SYSCALL:
			WRITESYSCALL;
			break;
		case BREAK:
			WRITEBREAK;
			break;
		case MFHI:
			WRITEMFHI;
			break;
		case MTHI:
			WRITEMTHI;
			break;
		case MFLO:
			WRITEMFLO;
			break;
		case MTLO:
			WRITEMTLO;
			break;
		case MULT:
			WRITEMULT;
			break;
		case MULTU:
			WRITEMULTU;
			break;
		case DIV:
			WRITEDIV;
			break;
		case DIVU:
			WRITEDIVU;
			break;
		case ADD:
			WRITEADD;
			break;
		case ADDU:
			WRITEADDU;
			break;
		case SUB:
			WRITESUB;
			break;
		case SUBU:
			WRITESUBU;
			break;
		case AND:
			WRITEAND;
			break;
		case OR:
			WRITEOR;
			break;
		case XOR:
			WRITEXOR;
			break;
		case NOR:
			WRITENOR;
			break;
		case SLT:
			WRITESLT;
			break;
		case SLTU:
			WRITESLTU;
			break;
		default:
			WRITENOT;
			break;
		}
		break;
	case BCOND:
		GETBCONDADDR;
		switch(rtnum)
		{
		case BLTZ:
			WRITEBLTZ;
			break;
		case BGEZ:
			WRITEBGEZ;
			break;
		case BLTZAL:
			WRITEBLTZAL;
			break;
		case BGEZAL:
			WRITEBGEZAL;
			break;
		default:
			WRITENOT;
			break;
		}
		break;
	case J:
		GETJJALADDR;
		if ((vAddr & 0xFFC00000) != 0xBFC00000)
		{
			vAddr = (vAddr & 0x003FFFFF);
		}
		WRITEJ;
		break;
	case JAL:
		GETJJALADDR;
		if ((vAddr & 0xFFC00000) != 0xBFC00000)
		{
			vAddr = (vAddr & 0x003FFFFF);
		}
		function = GetFunction("FuncDB.txt", vAddr);
		if (function == "null")
		{
			WRITEJAL;
		}
		else
		{
			WRITEFUNCT;
		}
		break;
	case BEQ:
		GETBCONDADDR;
		WRITEBEQ;
		break;
	case BNE:
		GETBCONDADDR;
		WRITEBNE;
		break;
	case BLEZ:
		GETBCONDADDR;
		WRITEBLEZ;
		break;
	case BGTZ:
		GETBCONDADDR;
		WRITEBGTZ;
		break;
	case ADDI:
		WRITEADDI;
		break;
	case ADDIU:
		WRITEADDIU;
		break;
	case SLTI:
		WRITESLTI;
		break;
	case SLTIU:
		WRITESLTIU;
		break;
	case ANDI:
		WRITEANDI;
		break;
	case ORI:
		WRITEORI;
		break;
	case XORI:
		WRITEXORI;
		break;
	case LUI:
		WRITELUI;
		break;
	case COP0:
		switch(rsnum)
		{
		case MF:
			WRITEMF0;
			break;
		case CF:
			WRITECF0;
			break;
		case MT:
			WRITEMT0;
			break;
		case CT:
			WRITECT0;
			break;
		case BC:
			WRITEBCC0
			break;
		default:
			WRITENOT;
			break;
		}
		break;
	case COP2:
		if (rsnum & 0x10)
		{
			WRITECOP2;
		}
		else
		{
			switch(rsnum)
			{
			case MF:
				WRITEMF2;
				break;
			case CF:
				WRITECF2;
				break;
			case MT:
				WRITEMT2;
				break;
			case CT:
				WRITECT2;
				break;
			case BC:
				WRITEBC2;
				break;
			default:
				WRITENOT;
				break;
			}
			break;
		}
		break;
	case LB:
		WRITELB;
		break;
	case LH:
		WRITELH;
		break;
	case LWL:
		WRITELWL;
		break;
	case LW:
		WRITELW;
		break;
	case LBU:
		WRITELBU;
		break;
	case LHU:
		WRITELHU;
		break;
	case LWR:
		WRITELWR;
		break;
	case SB:
		WRITESB;
		break;
	case SH:
		WRITESH;
		break;
	case SWL:
		WRITESWL;
		break;
	case SW:
		WRITESW;
		break;
	case SWR:
		WRITESWR;
		break;
	case LWC0:
		WRITELWC0;
		break;
	case LWC2:
		WRITELWC2;
		break;
	case SWC0:
		WRITESWC0;
		break;
	case SWC2:
		WRITESWC2;
		break;
	default:
		WRITENOT;
		break;
	}

	return;
}
