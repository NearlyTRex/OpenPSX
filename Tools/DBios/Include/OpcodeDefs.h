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
#ifndef OPCODEDEFS_H
#define OPCODEDEFS_H

// Opcode numeric defines

// OPCODE
#define NOP			0
#define SPECIAL		0
#define BCOND		1
#define J			2
#define JAL			3
#define BEQ			4
#define BNE			5
#define BLEZ		6
#define BGTZ		7
#define ADDI		8
#define ADDIU		9
#define SLTI			10
#define SLTIU		11
#define ANDI		12
#define ORI			13
#define XORI		14
#define LUI			15
#define COP0		16
#define COP2		18
#define LB			32
#define LH			33
#define LWL			34
#define LW			35
#define LBU			36
#define LHU			37
#define LWR			38
#define SB			40
#define SH			41
#define SWL			42
#define SW			43
#define SWR		46
#define LWC0		48
#define LWC2		50
#define SWC0		56
#define SWC2		58

// SPECIAL
#define SLL			0
#define SRL			2
#define SRA			3
#define SLLV		4
#define SRLV		6
#define SRAV		7
#define JR			8
#define JALR		9
#define SYSCALL	12
#define BREAK		13
#define MFHI		16
#define MTHI		17
#define MFLO		18
#define MTLO		19
#define MULT		24
#define MULTU		25
#define DIV			26
#define DIVU		27
#define ADD			32
#define ADDU		33
#define SUB			34
#define SUBU		35
#define AND			36
#define OR			37
#define XOR			38
#define NOR			39
#define SLT			42
#define SLTU		43

// BCOND
#define BLTZ		0
#define BGEZ		1
#define BLTZAL		16
#define BGEZAL		17

// COPz
#define MF			0
#define CF			2
#define MT			4
#define CT			6
#define BC			8

// COP0
#define TLBR		1
#define TLBWI		2
#define TLBWR		6
#define TLBP		8
#define RFE			16


#endif
