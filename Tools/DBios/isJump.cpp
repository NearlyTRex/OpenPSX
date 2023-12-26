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

// ===========================================
// Function - isJump
// Use - Returns 1 if given opcode is a jump instruction
// ===========================================
int isJump(UINT32 Opcode)
{
	int Returntype = 0;

	switch(op)
	{
	case SPECIAL:
		switch(funct)
		{
		case SLL:
			break;
		case SRL:
			break;
		case SRA:
			break;
		case SLLV:
			break;
		case SRLV:
			break;
		case SRAV:
			break;
		case JR:
			Returntype = 1;
			break;
		case JALR:
			Returntype = 1;
			break;
		case SYSCALL:
			break;
		case BREAK:
			break;
		case MFHI:
			break;
		case MTHI:
			break;
		case MFLO:
			break;
		case MTLO:
			break;
		case MULT:
			break;
		case MULTU:
			break;
		case DIV:
			break;
		case DIVU:
			break;
		case ADD:
           	break;
		case ADDU:
			break;
		case SUB:
			break;
		case SUBU:
			break;
		case AND:
			break;
		case OR:
			break;
		case XOR:
			break;
		case NOR:
			break;
		case SLT:
			break;
		case SLTU:
			break;
		}
		break;
	case BCOND:
		switch(rtnum)
		{
		case BLTZ:
			Returntype = 1;
			break;
		case BGEZ:
			Returntype = 1;
			break;
		case BLTZAL:
			Returntype = 1;
			break;
		case BGEZAL:
			Returntype = 1;
			break;
		}
		break;
	case J:
		Returntype = 1;
		break;
	case JAL:
		Returntype = 1;
		break;
	case BEQ:
		Returntype = 1;
		break;
	case BNE:
		Returntype = 1;
		break;
	case BLEZ:
		Returntype = 1;
		break;
	case BGTZ:
		Returntype = 1;
		break;
	case ADDI:
		break;
	case ADDIU:
		break;
	case SLTI:
		break;
	case SLTIU:
		break;
	case ANDI:
		break;
	case ORI:
		break;
	case XORI:
		break;
	case LUI:
		break;
	case COP0:
		// COPz(0)
		switch(rsnum)
		{
		case MF:
			break;
		case CF:
			break;
		case MT:
			break;
		case CT:
			break;
		case BC:
			break;
		}



		// COP0
		switch(funct)
		{
		case TLBR:
			break;
		case TLBWI:
			break;
		case TLBWR:
			break;
		case TLBP:
			break;
		case RFE:
			break;
		}

		break;
	case COP2:
		// COP2
		switch(rsnum)
		{
		case MF:
			break;
		case CF:
			break;
		case MT:
			break;
		case CT:
			break;
		case BC:
			break;
		}
		break;
	case LB:
		break;
	case LH:
		break;
	case LWL:
		break;
	case LW:
		break;
	case LBU:
		break;
	case LHU:
		break;
	case LWR:
		break;
	case SB:
		break;
	case SH:
		break;
	case SWL:
		break;
	case SW:
		break;
	case SWR:
		break;
	case LWC0:
		break;
	case LWC2:
		break;
	case SWC0:
		break;
	case SWC2:
		break;
	default:
		break;

	}

	return Returntype;
}
