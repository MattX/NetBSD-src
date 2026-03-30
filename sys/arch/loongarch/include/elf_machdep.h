/*	$NetBSD$	*/

/*-
 * Copyright (c) 2024 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _LOONGARCH_ELF_MACHDEP_H_
#define _LOONGARCH_ELF_MACHDEP_H_

#if !defined(_SYS_ELFDEFINITIONS_H_)

/*
 * EM_LOONGARCH (258) and all constants below are defined in the
 * LoongArch ELF psABI specification:
 *   https://github.com/loongson/la-abi-specs
 */

/* Processor specific flags for the ELF header e_flags field. */
#define EF_LARCH_ABI_SOFT_FLOAT		0x1
#define EF_LARCH_ABI_SINGLE_FLOAT	0x2
#define EF_LARCH_ABI_DOUBLE_FLOAT	0x3
#define EF_LARCH_OBJABI_V1		0x40

/*
 * Processor specific relocation types (psABI Table 3).
 * Types 0-12 are dynamic relocations used by the runtime linker.
 * Types 20+ are static relocations used by the assembler/linker.
 */
#define R_LARCH_NONE			0
#define R_LARCH_32			1
#define R_LARCH_64			2
#define R_LARCH_RELATIVE		3
#define R_LARCH_COPY			4
#define R_LARCH_JUMP_SLOT		5
#define R_LARCH_TLS_DTPMOD32		6
#define R_LARCH_TLS_DTPMOD64		7
#define R_LARCH_TLS_DTPREL32		8
#define R_LARCH_TLS_DTPREL64		9
#define R_LARCH_TLS_TPREL32		10
#define R_LARCH_TLS_TPREL64		11
#define R_LARCH_IRELATIVE		12
			/* 13-19 - Reserved */

/* Static relocations */
#define R_LARCH_MARK_LA			20
#define R_LARCH_MARK_PCREL		21
#define R_LARCH_SOP_PUSH_PCREL		22
#define R_LARCH_SOP_PUSH_ABSOLUTE	23
#define R_LARCH_SOP_PUSH_DUP		24
#define R_LARCH_SOP_PUSH_GPREL		25
#define R_LARCH_SOP_PUSH_TLS_TPREL	26
#define R_LARCH_SOP_PUSH_TLS_GOT	27
#define R_LARCH_SOP_PUSH_TLS_GD		28
#define R_LARCH_SOP_PUSH_PLT_PCREL	29
#define R_LARCH_SOP_ASSERT		30
#define R_LARCH_SOP_NOT			31
#define R_LARCH_SOP_SUB			32
#define R_LARCH_SOP_SL			33
#define R_LARCH_SOP_SR			34
#define R_LARCH_SOP_ADD			35
#define R_LARCH_SOP_AND			36
#define R_LARCH_SOP_IF_ELSE		37
#define R_LARCH_SOP_POP_32_S_10_5	38
#define R_LARCH_SOP_POP_32_U_10_12	39
#define R_LARCH_SOP_POP_32_S_10_12	40
#define R_LARCH_SOP_POP_32_S_10_16	41
#define R_LARCH_SOP_POP_32_S_10_16_S2	42
#define R_LARCH_SOP_POP_32_S_5_20	43
#define R_LARCH_SOP_POP_32_S_0_5_10_16_S2 44
#define R_LARCH_SOP_POP_32_S_0_10_10_16_S2 45
#define R_LARCH_SOP_POP_32_U		46
#define R_LARCH_ADD8			47
#define R_LARCH_ADD16			48
#define R_LARCH_ADD24			49
#define R_LARCH_ADD32			50
#define R_LARCH_ADD64			51
#define R_LARCH_SUB8			52
#define R_LARCH_SUB16			53
#define R_LARCH_SUB24			54
#define R_LARCH_SUB32			55
#define R_LARCH_SUB64			56
#define R_LARCH_GNU_VTINHERIT		57
#define R_LARCH_GNU_VTENTRY		58
#define R_LARCH_B16			64
#define R_LARCH_B21			65
#define R_LARCH_B26			66
#define R_LARCH_ABS_HI20		67
#define R_LARCH_ABS_LO12		68
#define R_LARCH_ABS64_LO20		69
#define R_LARCH_ABS64_HI12		70
#define R_LARCH_PCALA_HI20		71
#define R_LARCH_PCALA_LO12		72
#define R_LARCH_PCALA64_LO20		73
#define R_LARCH_PCALA64_HI12		74
#define R_LARCH_GOT_PC_HI20		75
#define R_LARCH_GOT_PC_LO12		76
#define R_LARCH_GOT64_PC_LO20		77
#define R_LARCH_GOT64_PC_HI12		78
#define R_LARCH_GOT_HI20		79
#define R_LARCH_GOT_LO12		80
#define R_LARCH_GOT64_LO20		81
#define R_LARCH_GOT64_HI12		82
#define R_LARCH_TLS_LE_HI20		83
#define R_LARCH_TLS_LE_LO12		84
#define R_LARCH_TLS_LE64_LO20		85
#define R_LARCH_TLS_LE64_HI12		86
#define R_LARCH_TLS_IE_PC_HI20		87
#define R_LARCH_TLS_IE_PC_LO12		88
#define R_LARCH_TLS_IE64_PC_LO20	89
#define R_LARCH_TLS_IE64_PC_HI12	90
#define R_LARCH_TLS_IE_HI20		91
#define R_LARCH_TLS_IE_LO12		92
#define R_LARCH_TLS_IE64_LO20		93
#define R_LARCH_TLS_IE64_HI12		94
#define R_LARCH_TLS_LD_PC_HI20		95
#define R_LARCH_TLS_LD_HI20		96
#define R_LARCH_TLS_GD_PC_HI20		97
#define R_LARCH_TLS_GD_HI20		98
#define R_LARCH_32_PCREL		99
#define R_LARCH_RELAX			100
#define R_LARCH_DELETE			101
#define R_LARCH_ALIGN			102
#define R_LARCH_PCREL20_S2		103
#define R_LARCH_CFA			104
#define R_LARCH_ADD6			105
#define R_LARCH_SUB6			106
#define R_LARCH_ADD_ULEB128		107
#define R_LARCH_SUB_ULEB128		108
#define R_LARCH_64_PCREL		109

#endif /* !defined(_SYS_ELFDEFINITIONS_H_) */

/*
 * Local symbols.
 */

#define	ELF64_MACHDEP_ID		EM_LOONGARCH
#define	ELF32_MACHDEP_ID		EM_LOONGARCH

/* LoongArch is always little-endian */
#define ELF64_MACHDEP_ENDIANNESS	ELFDATA2LSB
#define ELF32_MACHDEP_ENDIANNESS	ELFDATA2LSB

#define ELF64_MACHDEP_ID_CASES		\
		case EM_LOONGARCH:	\
			break;

#define ELF32_MACHDEP_ID_CASES		\
		case EM_LOONGARCH:	\
			break;

#define	KERN_ELFSIZE		64
#define ARCH_ELFSIZE		64	/* MD native binary size */

#define R_TYPE(name)		R_LARCH_ ## name
#define R_TYPESZ(name)		R_LARCH_ ## name ## 64

#ifdef _KERNEL
#ifdef ELFSIZE
#define ELF_MD_PROBE_FUNC	ELFNAME2(loongarch_netbsd,probe)
#endif

struct exec_package;

int loongarch_netbsd_elf64_probe(struct lwp *, struct exec_package *, void *,
    char *, vaddr_t *);

#endif /* _KERNEL */

#endif /* _LOONGARCH_ELF_MACHDEP_H_ */
