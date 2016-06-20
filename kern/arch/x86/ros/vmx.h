/*
 * vmx.h: VMX Architecture related definitions
 * Copyright (c) 2004, Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place - Suite 330, Boston, MA 02111-1307 USA.
 *
 * A few random additions are:
 * Copyright (C) 2006 Qumranet
 *    Avi Kivity <avi@qumranet.com>
 *    Yaniv Kamay <yaniv@qumranet.com>
 *
 */
#pragma once

#include <ros/common.h>
#include <ros/arch/mmu.h>

#define CPU_BASED_VIRTUAL_INTR_PENDING  0x00000004
#define CPU_BASED_USE_TSC_OFFSETING     0x00000008
#define CPU_BASED_HLT_EXITING           0x00000080
#define CPU_BASED_INVDPG_EXITING        0x00000200
#define CPU_BASED_MWAIT_EXITING         0x00000400
#define CPU_BASED_RDPMC_EXITING         0x00000800
#define CPU_BASED_RDTSC_EXITING         0x00001000
#define CPU_BASED_CR8_LOAD_EXITING      0x00080000
#define CPU_BASED_CR8_STORE_EXITING     0x00100000
#define CPU_BASED_TPR_SHADOW            0x00200000
#define CPU_BASED_MOV_DR_EXITING        0x00800000
#define CPU_BASED_UNCOND_IO_EXITING     0x01000000
#define CPU_BASED_ACTIVATE_IO_BITMAP    0x02000000
#define CPU_BASED_MSR_BITMAPS           0x10000000
#define CPU_BASED_MONITOR_EXITING       0x20000000
#define CPU_BASED_PAUSE_EXITING         0x40000000

/*
 * Definitions of Primary Processor-Based VM-Execution Controls.
 */
#define CPU_BASED_VIRTUAL_INTR_PENDING          0x00000004
#define CPU_BASED_USE_TSC_OFFSETING             0x00000008
#define CPU_BASED_HLT_EXITING                   0x00000080
#define CPU_BASED_INVLPG_EXITING                0x00000200
#define CPU_BASED_MWAIT_EXITING                 0x00000400
#define CPU_BASED_RDPMC_EXITING                 0x00000800
#define CPU_BASED_RDTSC_EXITING                 0x00001000
#define CPU_BASED_CR3_LOAD_EXITING		0x00008000
#define CPU_BASED_CR3_STORE_EXITING		0x00010000
#define CPU_BASED_CR8_LOAD_EXITING              0x00080000
#define CPU_BASED_CR8_STORE_EXITING             0x00100000
#define CPU_BASED_TPR_SHADOW                    0x00200000
#define CPU_BASED_VIRTUAL_NMI_PENDING		0x00400000
#define CPU_BASED_MOV_DR_EXITING                0x00800000
#define CPU_BASED_UNCOND_IO_EXITING             0x01000000
#define CPU_BASED_USE_IO_BITMAPS                0x02000000
#define CPU_BASED_MONITOR_TRAP                  0x08000000
#define CPU_BASED_USE_MSR_BITMAPS               0x10000000
#define CPU_BASED_MONITOR_EXITING               0x20000000
#define CPU_BASED_PAUSE_EXITING                 0x40000000
#define CPU_BASED_ACTIVATE_SECONDARY_CONTROLS   0x80000000
/*
 * Definitions of Secondary Processor-Based VM-Execution Controls.
 */
#define SECONDARY_EXEC_VIRTUALIZE_APIC_ACCESSES 0x00000001
#define SECONDARY_EXEC_ENABLE_EPT               0x00000002
#define SECONDARY_EXEC_DESCRIPTOR_EXITING       0x00000004
#define SECONDARY_EXEC_RDTSCP			0x00000008
#define SECONDARY_EXEC_VIRTUALIZE_X2APIC_MODE   0x00000010
#define SECONDARY_EXEC_ENABLE_VPID              0x00000020
#define SECONDARY_EXEC_WBINVD_EXITING		0x00000040
#define SECONDARY_EXEC_UNRESTRICTED_GUEST	0x00000080
#define SECONDARY_EXEC_APIC_REGISTER_VIRT       0x00000100
#define SECONDARY_EXEC_VIRTUAL_INTR_DELIVERY    0x00000200
#define SECONDARY_EXEC_PAUSE_LOOP_EXITING	0x00000400
#define SECONDARY_EXEC_RDRAND_EXITING	        0x00000800
#define SECONDARY_EXEC_ENABLE_INVPCID		0x00001000
#define SECONDARY_EXEC_ENABLE_VMFUNC		0x00002000
#define SECONDARY_EXEC_SHADOW_VMCS              0x00004000
#define SECONDARY_EXEC_RDSEED_EXITING           0x00010000
#define SECONDARY_EPT_VE                        0x00040000
#define SECONDARY_ENABLE_XSAV_RESTORE           0x00100000

#define PIN_BASED_EXT_INTR_MASK                 0x00000001
#define PIN_BASED_NMI_EXITING                   0x00000008
#define PIN_BASED_VIRTUAL_NMIS                  0x00000020
#define PIN_BASED_VMX_PREEMPTION_TIMER          0x00000040
#define PIN_BASED_POSTED_INTR                   0x00000080

#define VM_EXIT_SAVE_DEBUG_CONTROLS             0x00000004
#define VM_EXIT_HOST_ADDR_SPACE_SIZE            0x00000200
#define VM_EXIT_LOAD_IA32_PERF_GLOBAL_CTRL      0x00001000
#define VM_EXIT_ACK_INTR_ON_EXIT                0x00008000
#define VM_EXIT_SAVE_IA32_PAT			0x00040000
#define VM_EXIT_LOAD_IA32_PAT			0x00080000
#define VM_EXIT_SAVE_IA32_EFER                  0x00100000
#define VM_EXIT_LOAD_IA32_EFER                  0x00200000
#define VM_EXIT_SAVE_VMX_PREEMPTION_TIMER       0x00400000

#define VM_ENTRY_LOAD_DEBUG_CONTROLS            0x00000004
#define VM_ENTRY_IA32E_MODE                     0x00000200
#define VM_ENTRY_SMM                            0x00000400
#define VM_ENTRY_DEACT_DUAL_MONITOR             0x00000800
#define VM_ENTRY_LOAD_IA32_PERF_GLOBAL_CTRL     0x00002000
#define VM_ENTRY_LOAD_IA32_PAT			0x00004000
#define VM_ENTRY_LOAD_IA32_EFER                 0x00008000

/* VMCS Encodings */
enum vmcs_field {
	VIRTUAL_PROCESSOR_ID            = 0x00000000,
	POSTED_NOTIFICATION_VEC		= 0x00000002,
	GUEST_ES_SELECTOR               = 0x00000800,
	GUEST_CS_SELECTOR               = 0x00000802,
	GUEST_SS_SELECTOR               = 0x00000804,
	GUEST_DS_SELECTOR               = 0x00000806,
	GUEST_FS_SELECTOR               = 0x00000808,
	GUEST_GS_SELECTOR               = 0x0000080a,
	GUEST_LDTR_SELECTOR             = 0x0000080c,
	GUEST_TR_SELECTOR               = 0x0000080e,
	GUEST_INTR_STATUS               = 0x00000810,
	GUEST_PML_INDEX			= 0x00000812,
	HOST_ES_SELECTOR                = 0x00000c00,
	HOST_CS_SELECTOR                = 0x00000c02,
	HOST_SS_SELECTOR                = 0x00000c04,
	HOST_DS_SELECTOR                = 0x00000c06,
	HOST_FS_SELECTOR                = 0x00000c08,
	HOST_GS_SELECTOR                = 0x00000c0a,
	HOST_TR_SELECTOR                = 0x00000c0c,
	IO_BITMAP_A                     = 0x00002000,
	IO_BITMAP_A_HIGH                = 0x00002001,
	IO_BITMAP_B                     = 0x00002002,
	IO_BITMAP_B_HIGH                = 0x00002003,
	MSR_BITMAP                      = 0x00002004,
	MSR_BITMAP_HIGH                 = 0x00002005,
	VM_EXIT_MSR_STORE_ADDR          = 0x00002006,
	VM_EXIT_MSR_STORE_ADDR_HIGH     = 0x00002007,
	VM_EXIT_MSR_LOAD_ADDR           = 0x00002008,
	VM_EXIT_MSR_LOAD_ADDR_HIGH      = 0x00002009,
	VM_ENTRY_MSR_LOAD_ADDR          = 0x0000200a,
	VM_ENTRY_MSR_LOAD_ADDR_HIGH     = 0x0000200b,
	TSC_OFFSET                      = 0x00002010,
	TSC_OFFSET_HIGH                 = 0x00002011,
	VIRTUAL_APIC_PAGE_ADDR          = 0x00002012,
	VIRTUAL_APIC_PAGE_ADDR_HIGH     = 0x00002013,
	APIC_ACCESS_ADDR		= 0x00002014,
	APIC_ACCESS_ADDR_HIGH		= 0x00002015,
	POSTED_INTR_DESC_ADDR           = 0x00002016,
	POSTED_INTR_DESC_ADDR_HIGH      = 0x00002017,
	EPT_POINTER                     = 0x0000201a,
	EPT_POINTER_HIGH                = 0x0000201b,
	EOI_EXIT_BITMAP0                = 0x0000201c,
	EOI_EXIT_BITMAP0_HIGH           = 0x0000201d,
	EOI_EXIT_BITMAP1                = 0x0000201e,
	EOI_EXIT_BITMAP1_HIGH           = 0x0000201f,
	EOI_EXIT_BITMAP2                = 0x00002020,
	EOI_EXIT_BITMAP2_HIGH           = 0x00002021,
	EOI_EXIT_BITMAP3                = 0x00002022,
	EOI_EXIT_BITMAP3_HIGH           = 0x00002023,
	VMREAD_BITMAP                   = 0x00002026,
	VMWRITE_BITMAP                  = 0x00002028,
	XSS_EXIT_BITMAP                 = 0x0000202C,
	XSS_EXIT_BITMAP_HIGH            = 0x0000202D,
	GUEST_PHYSICAL_ADDRESS          = 0x00002400,
	GUEST_PHYSICAL_ADDRESS_HIGH     = 0x00002401,
	VMCS_LINK_POINTER               = 0x00002800,
	VMCS_LINK_POINTER_HIGH          = 0x00002801,
	GUEST_IA32_DEBUGCTL             = 0x00002802,
	GUEST_IA32_DEBUGCTL_HIGH        = 0x00002803,
	GUEST_IA32_PAT			= 0x00002804,
	GUEST_IA32_PAT_HIGH		= 0x00002805,
	GUEST_IA32_EFER			= 0x00002806,
	GUEST_IA32_EFER_HIGH		= 0x00002807,
	GUEST_IA32_PERF_GLOBAL_CTRL	= 0x00002808,
	GUEST_IA32_PERF_GLOBAL_CTRL_HIGH= 0x00002809,
	GUEST_PDPTR0                    = 0x0000280a,
	GUEST_PDPTR0_HIGH               = 0x0000280b,
	GUEST_PDPTR1                    = 0x0000280c,
	GUEST_PDPTR1_HIGH               = 0x0000280d,
	GUEST_PDPTR2                    = 0x0000280e,
	GUEST_PDPTR2_HIGH               = 0x0000280f,
	GUEST_PDPTR3                    = 0x00002810,
	GUEST_PDPTR3_HIGH               = 0x00002811,
	HOST_IA32_PAT			= 0x00002c00,
	HOST_IA32_PAT_HIGH		= 0x00002c01,
	HOST_IA32_EFER			= 0x00002c02,
	HOST_IA32_EFER_HIGH		= 0x00002c03,
	HOST_IA32_PERF_GLOBAL_CTRL	= 0x00002c04,
	HOST_IA32_PERF_GLOBAL_CTRL_HIGH	= 0x00002c05,
	PIN_BASED_VM_EXEC_CONTROL       = 0x00004000,
	CPU_BASED_VM_EXEC_CONTROL       = 0x00004002,
	EXCEPTION_BITMAP                = 0x00004004,
	PAGE_FAULT_ERROR_CODE_MASK      = 0x00004006,
	PAGE_FAULT_ERROR_CODE_MATCH     = 0x00004008,
	CR3_TARGET_COUNT                = 0x0000400a,
	VM_EXIT_CONTROLS                = 0x0000400c,
	VM_EXIT_MSR_STORE_COUNT         = 0x0000400e,
	VM_EXIT_MSR_LOAD_COUNT          = 0x00004010,
	VM_ENTRY_CONTROLS               = 0x00004012,
	VM_ENTRY_MSR_LOAD_COUNT         = 0x00004014,
	VM_ENTRY_INTR_INFO_FIELD        = 0x00004016,
	VM_ENTRY_EXCEPTION_ERROR_CODE   = 0x00004018,
	VM_ENTRY_INSTRUCTION_LEN        = 0x0000401a,
	TPR_THRESHOLD                   = 0x0000401c,
	SECONDARY_VM_EXEC_CONTROL       = 0x0000401e,
	PLE_GAP                         = 0x00004020,
	PLE_WINDOW                      = 0x00004022,
	VM_INSTRUCTION_ERROR            = 0x00004400,
	VM_EXIT_REASON                  = 0x00004402,
	VM_EXIT_INTR_INFO               = 0x00004404,
	VM_EXIT_INTR_ERROR_CODE         = 0x00004406,
	IDT_VECTORING_INFO_FIELD        = 0x00004408,
	IDT_VECTORING_ERROR_CODE        = 0x0000440a,
	VM_EXIT_INSTRUCTION_LEN         = 0x0000440c,
	VMX_INSTRUCTION_INFO            = 0x0000440e,
	GUEST_ES_LIMIT                  = 0x00004800,
	GUEST_CS_LIMIT                  = 0x00004802,
	GUEST_SS_LIMIT                  = 0x00004804,
	GUEST_DS_LIMIT                  = 0x00004806,
	GUEST_FS_LIMIT                  = 0x00004808,
	GUEST_GS_LIMIT                  = 0x0000480a,
	GUEST_LDTR_LIMIT                = 0x0000480c,
	GUEST_TR_LIMIT                  = 0x0000480e,
	GUEST_GDTR_LIMIT                = 0x00004810,
	GUEST_IDTR_LIMIT                = 0x00004812,
	GUEST_ES_AR_BYTES               = 0x00004814,
	GUEST_CS_AR_BYTES               = 0x00004816,
	GUEST_SS_AR_BYTES               = 0x00004818,
	GUEST_DS_AR_BYTES               = 0x0000481a,
	GUEST_FS_AR_BYTES               = 0x0000481c,
	GUEST_GS_AR_BYTES               = 0x0000481e,
	GUEST_LDTR_AR_BYTES             = 0x00004820,
	GUEST_TR_AR_BYTES               = 0x00004822,
	GUEST_INTERRUPTIBILITY_INFO     = 0x00004824,
	GUEST_ACTIVITY_STATE            = 0X00004826,
	GUEST_SYSENTER_CS               = 0x0000482A,
	HOST_IA32_SYSENTER_CS           = 0x00004c00,
	CR0_GUEST_HOST_MASK             = 0x00006000,
	CR4_GUEST_HOST_MASK             = 0x00006002,
	CR0_READ_SHADOW                 = 0x00006004,
	CR4_READ_SHADOW                 = 0x00006006,
	CR3_TARGET_VALUE0               = 0x00006008,
	CR3_TARGET_VALUE1               = 0x0000600a,
	CR3_TARGET_VALUE2               = 0x0000600c,
	CR3_TARGET_VALUE3               = 0x0000600e,
	EXIT_QUALIFICATION              = 0x00006400,
	GUEST_LINEAR_ADDRESS            = 0x0000640a,
	GUEST_CR0                       = 0x00006800,
	GUEST_CR3                       = 0x00006802,
	GUEST_CR4                       = 0x00006804,
	GUEST_ES_BASE                   = 0x00006806,
	GUEST_CS_BASE                   = 0x00006808,
	GUEST_SS_BASE                   = 0x0000680a,
	GUEST_DS_BASE                   = 0x0000680c,
	GUEST_FS_BASE                   = 0x0000680e,
	GUEST_GS_BASE                   = 0x00006810,
	GUEST_LDTR_BASE                 = 0x00006812,
	GUEST_TR_BASE                   = 0x00006814,
	GUEST_GDTR_BASE                 = 0x00006816,
	GUEST_IDTR_BASE                 = 0x00006818,
	GUEST_DR7                       = 0x0000681a,
	GUEST_RSP                       = 0x0000681c,
	GUEST_RIP                       = 0x0000681e,
	GUEST_RFLAGS                    = 0x00006820,
	GUEST_PENDING_DBG_EXCEPTIONS    = 0x00006822,
	GUEST_SYSENTER_ESP              = 0x00006824,
	GUEST_SYSENTER_EIP              = 0x00006826,
	HOST_CR0                        = 0x00006c00,
	HOST_CR3                        = 0x00006c02,
	HOST_CR4                        = 0x00006c04,
	HOST_FS_BASE                    = 0x00006c06,
	HOST_GS_BASE                    = 0x00006c08,
	HOST_TR_BASE                    = 0x00006c0a,
	HOST_GDTR_BASE                  = 0x00006c0c,
	HOST_IDTR_BASE                  = 0x00006c0e,
	HOST_IA32_SYSENTER_ESP          = 0x00006c10,
	HOST_IA32_SYSENTER_EIP          = 0x00006c12,
	HOST_RSP                        = 0x00006c14,
	HOST_RIP                        = 0x00006c16,
};

#define VMX_EXIT_REASONS_FAILED_VMENTRY         0x80000000

#define EXIT_REASON_EXCEPTION_NMI       0
#define EXIT_REASON_EXTERNAL_INTERRUPT  1
#define EXIT_REASON_TRIPLE_FAULT        2
#define EXIT_REASON_INIT_SIGNAL         3
#define EXIT_REASON_START_UP_IPI        4
#define EXIT_REASON_IO_SM_INTERRUPT     5
#define EXIT_REASON_OTHER_SMI           6
#define EXIT_REASON_PENDING_INTERRUPT   7
#define EXIT_REASON_INTERRUPT_WINDOW    7
#define EXIT_REASON_NMI_WINDOW          8
#define EXIT_REASON_TASK_SWITCH         9
#define EXIT_REASON_CPUID               10
#define EXIT_REASON_GETSEC              11
#define EXIT_REASON_HLT                 12
#define EXIT_REASON_INVD                13
#define EXIT_REASON_INVLPG              14
#define EXIT_REASON_RDPMC               15
#define EXIT_REASON_RDTSC               16
#define EXIT_REASON_RSM                 17
#define EXIT_REASON_VMCALL              18
#define EXIT_REASON_VMCLEAR             19
#define EXIT_REASON_VMLAUNCH            20
#define EXIT_REASON_VMPTRLD             21
#define EXIT_REASON_VMPTRST             22
#define EXIT_REASON_VMREAD              23
#define EXIT_REASON_VMRESUME            24
#define EXIT_REASON_VMWRITE             25
#define EXIT_REASON_VMOFF               26
#define EXIT_REASON_VMON                27
#define EXIT_REASON_CR_ACCESS           28
#define EXIT_REASON_DR_ACCESS           29
#define EXIT_REASON_IO_INSTRUCTION      30
#define EXIT_REASON_MSR_READ            31
#define EXIT_REASON_MSR_WRITE           32
#define EXIT_REASON_INVALID_STATE       33
#define EXIT_REASON_ENTRY_MSR_LOADING   34
#define EXIT_REASON_MWAIT_INSTRUCTION   36
#define EXIT_REASON_MONITOR_TRAP_FLAG   37
#define EXIT_REASON_MONITOR_INSTRUCTION 39
#define EXIT_REASON_PAUSE_INSTRUCTION   40
#define EXIT_REASON_MCE_DURING_VMENTRY  41
#define EXIT_REASON_TPR_BELOW_THRESHOLD 43
#define EXIT_REASON_APIC_ACCESS         44
#define EXIT_REASON_VIRTUALIZED_EOI     45
#define EXIT_REASON_GDTR_IDTR_ACCESS    46
#define EXIT_REASON_LDTR_TR_ACCESS      47
#define EXIT_REASON_EPT_VIOLATION       48
#define EXIT_REASON_EPT_MISCONFIG       49
#define EXIT_REASON_INVEPT              50
#define EXIT_REASON_RDTSCP              51
#define EXIT_REASON_VMX_TIMER_EXPIRED   52
#define EXIT_REASON_INVVPID             53
#define EXIT_REASON_WBINVD              54
#define EXIT_REASON_XSETBV              55
#define EXIT_REASON_APIC_WRITE          56
#define EXIT_REASON_RDRAND              57
#define EXIT_REASON_INVPCID             58
#define EXIT_REASON_VMFUNC              59
#define EXIT_REASON_RDSEED              61
#define EXIT_REASON_XSAVES              63
#define EXIT_REASON_XRSTORS             64
/* Non-standard exit reasons */
#define EXIT_REASON_GUEST_IN_USE        257
#define EXIT_REASON_VMENTER_FAILED      258

#define VMX_EXIT_REASONS \
	[EXIT_REASON_EXCEPTION_NMI]         "EXCEPTION_NMI", \
	[EXIT_REASON_EXTERNAL_INTERRUPT]    "EXTERNAL_INTERRUPT", \
	[EXIT_REASON_TRIPLE_FAULT]          "TRIPLE_FAULT", \
	[EXIT_REASON_PENDING_INTERRUPT]     "PENDING_INTERRUPT", \
	[EXIT_REASON_NMI_WINDOW]            "NMI_WINDOW", \
	[EXIT_REASON_TASK_SWITCH]           "TASK_SWITCH", \
	[EXIT_REASON_CPUID]                 "CPUID", \
	[EXIT_REASON_HLT]                   "HLT", \
	[EXIT_REASON_INVLPG]                "INVLPG", \
	[EXIT_REASON_RDPMC]                 "RDPMC", \
	[EXIT_REASON_RDTSC]                 "RDTSC", \
	[EXIT_REASON_VMCALL]                "VMCALL", \
	[EXIT_REASON_VMCLEAR]               "VMCLEAR", \
	[EXIT_REASON_VMLAUNCH]              "VMLAUNCH", \
	[EXIT_REASON_VMPTRLD]               "VMPTRLD", \
	[EXIT_REASON_VMPTRST]               "VMPTRST", \
	[EXIT_REASON_VMREAD]                "VMREAD", \
	[EXIT_REASON_VMRESUME]              "VMRESUME", \
	[EXIT_REASON_VMWRITE]               "VMWRITE", \
	[EXIT_REASON_VMOFF]                 "VMOFF", \
	[EXIT_REASON_VMON]                  "VMON", \
	[EXIT_REASON_CR_ACCESS]             "CR_ACCESS", \
	[EXIT_REASON_DR_ACCESS]             "DR_ACCESS", \
	[EXIT_REASON_IO_INSTRUCTION]        "IO_INSTRUCTION", \
	[EXIT_REASON_MSR_READ]              "MSR_READ", \
	[EXIT_REASON_MSR_WRITE]             "MSR_WRITE", \
	[EXIT_REASON_MWAIT_INSTRUCTION]     "MWAIT_INSTRUCTION", \
	[EXIT_REASON_MONITOR_INSTRUCTION]   "MONITOR_INSTRUCTION", \
	[EXIT_REASON_PAUSE_INSTRUCTION]     "PAUSE_INSTRUCTION", \
	[EXIT_REASON_MCE_DURING_VMENTRY]    "MCE_DURING_VMENTRY", \
	[EXIT_REASON_TPR_BELOW_THRESHOLD]   "TPR_BELOW_THRESHOLD", \
	[EXIT_REASON_APIC_ACCESS]           "APIC_ACCESS", \
	[EXIT_REASON_EPT_VIOLATION]         "EPT_VIOLATION", \
	[EXIT_REASON_EPT_MISCONFIG]         "EPT_MISCONFIG", \
	[EXIT_REASON_WBINVD]                "WBINVD", \
	[EXIT_REASON_GUEST_IN_USE]          "GUEST_IN_USE", \
	[EXIT_REASON_VMENTER_FAILED]        "VMENTER_FAILED"

/*
 * Interruption-information format
 */
#define INTR_INFO_VECTOR_MASK           0xff            /* 7:0 */
#define INTR_INFO_INTR_TYPE_MASK        0x700           /* 10:8 */
#define INTR_INFO_DELIVER_CODE_MASK     0x800           /* 11 */
#define INTR_INFO_UNBLOCK_NMI		0x1000		/* 12 */
#define INTR_INFO_VALID_MASK            0x80000000      /* 31 */
#define INTR_INFO_RESVD_BITS_MASK       0x7ffff000

#define VECTORING_INFO_VECTOR_MASK           	INTR_INFO_VECTOR_MASK
#define VECTORING_INFO_TYPE_MASK        	INTR_INFO_INTR_TYPE_MASK
#define VECTORING_INFO_DELIEVER_CODE_MASK    	INTR_INFO_DELIEVER_CODE_MASK
#define VECTORING_INFO_VALID_MASK       	INTR_INFO_VALID_MASK

#define INTR_TYPE_EXT_INTR              (0 << 8) /* external interrupt */
#define INTR_TYPE_NMI_INTR		(2 << 8) /* NMI */
#define INTR_TYPE_HARD_EXCEPTION	(3 << 8) /* processor exception */
#define INTR_TYPE_EXCEPTION             (3 << 8)       /* processor exception */
#define INTR_TYPE_SOFT_INTR             (4 << 8) /* software interrupt */
#define INTR_TYPE_SOFT_EXCEPTION	(6 << 8) /* software exception */

#define VMX_POSTED_OUTSTANDING_NOTIF		256

/* GUEST_INTERRUPTIBILITY_INFO flags. */
#define GUEST_INTR_STATE_STI		0x00000001
#define GUEST_INTR_STATE_MOV_SS		0x00000002
#define GUEST_INTR_STATE_SMI		0x00000004
#define GUEST_INTR_STATE_NMI		0x00000008

/* GUEST_ACTIVITY_STATE flags */
#define GUEST_ACTIVITY_ACTIVE		0
#define GUEST_ACTIVITY_HLT		1
#define GUEST_ACTIVITY_SHUTDOWN		2
#define GUEST_ACTIVITY_WAIT_SIPI	3

/*
 * Exit Qualifications for MOV for Control Register Access
 */
#define CONTROL_REG_ACCESS_NUM          0x7	/* 2:0, number of control register */
#define CONTROL_REG_ACCESS_TYPE         0x30	/* 5:4, access type */
#define CONTROL_REG_ACCESS_REG          0xf00	/* 10:8, general purpose register */
#define LMSW_SOURCE_DATA_SHIFT 16
#define LMSW_SOURCE_DATA  (0xFFFF << LMSW_SOURCE_DATA_SHIFT)	/* 16:31 lmsw source */
#define REG_EAX                         (0 << 8)
#define REG_ECX                         (1 << 8)
#define REG_EDX                         (2 << 8)
#define REG_EBX                         (3 << 8)
#define REG_ESP                         (4 << 8)
#define REG_EBP                         (5 << 8)
#define REG_ESI                         (6 << 8)
#define REG_EDI                         (7 << 8)
#define REG_R8                         (8 << 8)
#define REG_R9                         (9 << 8)
#define REG_R10                        (10 << 8)
#define REG_R11                        (11 << 8)
#define REG_R12                        (12 << 8)
#define REG_R13                        (13 << 8)
#define REG_R14                        (14 << 8)
#define REG_R15                        (15 << 8)

/*
 * Exit Qualifications for MOV for Debug Register Access
 */
#define DEBUG_REG_ACCESS_NUM            0x7	/* 2:0, number of debug register */
#define DEBUG_REG_ACCESS_TYPE           0x10	/* 4, direction of access */
#define TYPE_MOV_TO_DR                  (0 << 4)
#define TYPE_MOV_FROM_DR                (1 << 4)
#define DEBUG_REG_ACCESS_REG(eq)        (((eq) >> 8) & 0xf) /* 11:8, general purpose reg. */


/*
 * Exit Qualifications for APIC-Access
 */
#define APIC_ACCESS_OFFSET              0xfff   /* 11:0, offset within the APIC page */
#define APIC_ACCESS_TYPE                0xf000  /* 15:12, access type */
#define TYPE_LINEAR_APIC_INST_READ      (0 << 12)
#define TYPE_LINEAR_APIC_INST_WRITE     (1 << 12)
#define TYPE_LINEAR_APIC_INST_FETCH     (2 << 12)
#define TYPE_LINEAR_APIC_EVENT          (3 << 12)
#define TYPE_PHYSICAL_APIC_EVENT        (10 << 12)
#define TYPE_PHYSICAL_APIC_INST         (15 << 12)

/* segment AR */
#define SEGMENT_AR_L_MASK (1 << 13)

/* entry controls */
#define VM_ENTRY_CONTROLS_IA32E_MASK (1 << 9)

#define AR_TYPE_ACCESSES_MASK 1
#define AR_TYPE_READABLE_MASK (1 << 1)
#define AR_TYPE_WRITEABLE_MASK (1 << 2)
#define AR_TYPE_CODE_MASK (1 << 3)
#define AR_TYPE_MASK 0x0f
#define AR_TYPE_BUSY_64_TSS 11
#define AR_TYPE_BUSY_32_TSS 11
#define AR_TYPE_BUSY_16_TSS 3
#define AR_TYPE_LDT 2

#define AR_UNUSABLE_MASK (1 << 16)
#define AR_S_MASK (1 << 4)
#define AR_P_MASK (1 << 7)
#define AR_L_MASK (1 << 13)
#define AR_DB_MASK (1 << 14)
#define AR_G_MASK (1 << 15)
#define AR_DPL_SHIFT 5
#define AR_DPL(ar) (((ar) >> AR_DPL_SHIFT) & 3)

#define AR_RESERVD_MASK 0xfffe0f00

#define TSS_PRIVATE_MEMSLOT			(KVM_MEMORY_SLOTS + 0)
#define APIC_ACCESS_PAGE_PRIVATE_MEMSLOT	(KVM_MEMORY_SLOTS + 1)
#define IDENTITY_PAGETABLE_PRIVATE_MEMSLOT	(KVM_MEMORY_SLOTS + 2)

#define VMX_NR_VPIDS				(1 << 16)
#define VMX_VPID_EXTENT_SINGLE_CONTEXT		1
#define VMX_VPID_EXTENT_ALL_CONTEXT		2

#define VMX_EPT_EXTENT_INDIVIDUAL_ADDR		0
#define VMX_EPT_EXTENT_CONTEXT			1
#define VMX_EPT_EXTENT_GLOBAL			2

#define VMX_EPT_EXECUTE_ONLY_BIT		(1ull)
#define VMX_EPT_PAGE_WALK_4_BIT			(1ull << 6)
#define VMX_EPTP_UC_BIT				(1ull << 8)
#define VMX_EPTP_WB_BIT				(1ull << 14)
#define VMX_EPT_2MB_PAGE_BIT			(1ull << 16)
#define VMX_EPT_1GB_PAGE_BIT			(1ull << 17)
#define VMX_EPT_INVEPT_BIT				(1ull << 20)
#define VMX_EPT_AD_BIT				    (1ull << 21)
#define VMX_EPT_EXTENT_CONTEXT_BIT		(1ull << 25)
#define VMX_EPT_EXTENT_GLOBAL_BIT		(1ull << 26)
#define VMX_EPT_EXTENT_INDIVIDUAL_BIT           (1ull << 24)

#define SHUTDOWN_REASON(r)	((r) >> 16)
#define SHUTDOWN_STATUS(r)	((r) & 0xffff)

#define VMX_VPID_EXTENT_SINGLE_CONTEXT_BIT      (1ull << 9) /* (41 - 32) */
#define VMX_VPID_EXTENT_GLOBAL_CONTEXT_BIT      (1ull << 10) /* (42 - 32) */

#define VMX_EPT_GAW_4_LVL				3 	/* LVL - 1 */
#define VMX_EPT_MAX_GAW					0x4
#define VMX_EPT_MT_EPTE_SHIFT			3
#define VMX_EPT_GAW_EPTP_SHIFT			3
#define VMX_EPT_AD_ENABLE_BIT			(1ull << 6)
#define VMX_EPT_MEM_TYPE_WB				0x6ull
#define VMX_EPT_READABLE_MASK			0x1ull
#define VMX_EPT_WRITABLE_MASK			0x2ull
#define VMX_EPT_EXECUTABLE_MASK			0x4ull
#define VMX_EPT_IPAT_BIT    			(1ull << 6)
#define VMX_EPT_ACCESS_BIT				(1ull << 8)
#define VMX_EPT_DIRTY_BIT				(1ull << 9)

#define VMX_EPT_IDENTITY_PAGETABLE_ADDR		0xfffbc000ul

#define VMX_EPT_FAULT_READ	0x01
#define VMX_EPT_FAULT_WRITE	0x02
#define VMX_EPT_FAULT_INS	0x04

#define ASM_VMX_VMCLEAR_RAX       ".byte 0x66, 0x0f, 0xc7, 0x30"
#define ASM_VMX_VMLAUNCH          ".byte 0x0f, 0x01, 0xc2"
#define ASM_VMX_VMRESUME          ".byte 0x0f, 0x01, 0xc3"
#define ASM_VMX_VMPTRLD_RAX       ".byte 0x0f, 0xc7, 0x30"
#define ASM_VMX_VMPTRST_RAX       ".byte 0x0f, 0xc7, 0x38"
#define ASM_VMX_VMREAD_RDX_RAX    ".byte 0x0f, 0x78, 0xd0"
#define ASM_VMX_VMWRITE_RAX_RDX   ".byte 0x0f, 0x79, 0xd0"
#define ASM_VMX_VMWRITE_RSP_RDX   ".byte 0x0f, 0x79, 0xd4"
#define ASM_VMX_VMXOFF            ".byte 0x0f, 0x01, 0xc4"
#define ASM_VMX_VMXON_RAX         ".byte 0xf3, 0x0f, 0xc7, 0x30"
#define ASM_VMX_INVEPT		  ".byte 0x66, 0x0f, 0x38, 0x80, 0x08"
#define ASM_VMX_INVVPID		  ".byte 0x66, 0x0f, 0x38, 0x81, 0x08"

struct vmx_msr_entry {
	uint32_t index;
	uint32_t reserved;
	uint64_t value;
} __attribute__((aligned(16))) ;

/*
 * Exit Qualifications for entry failure during or after loading guest state
 */
#define ENTRY_FAIL_DEFAULT		0
#define ENTRY_FAIL_PDPTE		2
#define ENTRY_FAIL_NMI			3
#define ENTRY_FAIL_VMCS_LINK_PTR	4

/*
 * VM-instruction error numbers
 */
enum vm_instruction_error_number {
	VMXERR_VMCALL_IN_VMX_ROOT_OPERATION = 1,
	VMXERR_VMCLEAR_INVALID_ADDRESS = 2,
	VMXERR_VMCLEAR_VMXON_POINTER = 3,
	VMXERR_VMLAUNCH_NONCLEAR_VMCS = 4,
	VMXERR_VMRESUME_NONLAUNCHED_VMCS = 5,
	VMXERR_VMRESUME_AFTER_VMXOFF = 6,
	VMXERR_ENTRY_INVALID_CONTROL_FIELD = 7,
	VMXERR_ENTRY_INVALID_HOST_STATE_FIELD = 8,
	VMXERR_VMPTRLD_INVALID_ADDRESS = 9,
	VMXERR_VMPTRLD_VMXON_POINTER = 10,
	VMXERR_VMPTRLD_INCORRECT_VMCS_REVISION_ID = 11,
	VMXERR_UNSUPPORTED_VMCS_COMPONENT = 12,
	VMXERR_VMWRITE_READ_ONLY_VMCS_COMPONENT = 13,
	VMXERR_VMXON_IN_VMX_ROOT_OPERATION = 15,
	VMXERR_ENTRY_INVALID_EXECUTIVE_VMCS_POINTER = 16,
	VMXERR_ENTRY_NONLAUNCHED_EXECUTIVE_VMCS = 17,
	VMXERR_ENTRY_EXECUTIVE_VMCS_POINTER_NOT_VMXON_POINTER = 18,
	VMXERR_VMCALL_NONCLEAR_VMCS = 19,
	VMXERR_VMCALL_INVALID_VM_EXIT_CONTROL_FIELDS = 20,
	VMXERR_VMCALL_INCORRECT_MSEG_REVISION_ID = 22,
	VMXERR_VMXOFF_UNDER_DUAL_MONITOR_TREATMENT_OF_SMIS_AND_SMM = 23,
	VMXERR_VMCALL_INVALID_SMM_MONITOR_FEATURES = 24,
	VMXERR_ENTRY_INVALID_VM_EXECUTION_CONTROL_FIELDS_IN_EXECUTIVE_VMCS = 25,
	VMXERR_ENTRY_EVENTS_BLOCKED_BY_MOV_SS = 26,
	VMXERR_INVALID_OPERAND_TO_INVEPT_INVVPID = 28,
};

#define MSR_IA32_VMX_BASIC_MSR   		0x480
#define MSR_IA32_VMX_PINBASED_CTLS_MSR		0x481
#define MSR_IA32_VMX_PROCBASED_CTLS_MSR		0x482
#define MSR_IA32_VMX_EXIT_CTLS_MSR		0x483
#define MSR_IA32_VMX_ENTRY_CTLS_MSR		0x484

/*
 * shutdown reasons
 */
enum shutdown_reason {
	SHUTDOWN_SYS_EXIT = 1,
	SHUTDOWN_SYS_EXIT_GROUP,
	SHUTDOWN_SYS_EXECVE,
	SHUTDOWN_FATAL_SIGNAL,
	SHUTDOWN_EPT_VIOLATION,
	SHUTDOWN_NMI_EXCEPTION,
	SHUTDOWN_UNHANDLED_EXIT_REASON,
};

/* Additional bits for VMMCPs, originally from the Dune version of kvm. */
/*
 * vmx.h - header file for USM VMX driver.
 */

/* This is per-guest per-core, and the implementation specific area
 * should be assumed to have hidden fields.
 */
struct vmcs {
	uint32_t revision_id;
	uint32_t abort_code;
	char _impl_specific[PGSIZE - sizeof(uint32_t) * 2];
};

typedef uint64_t gpa_t;
typedef uint64_t gva_t;
/* TODO: remove these nasty macros */
#define rdmsrl(msr, val) (val) = read_msr((msr))
#define rdmsr(msr, low, high)                                                  \
do {                                                                           \
	uint64_t m = read_msr(msr);                                                \
	                                                                           \
	low = m & 0xffffffff;                                                      \
	high = m >> 32;                                                            \
} while (0)

struct vmx_capability {
	uint32_t ept;
	uint32_t vpid;
};

extern struct vmx_capability vmx_capability;

struct vmcs_config {
	int size;
	int order;
	uint32_t revision_id;
	uint32_t pin_based_exec_ctrl;
	uint32_t cpu_based_exec_ctrl;
	uint32_t cpu_based_2nd_exec_ctrl;
	uint32_t vmexit_ctrl;
	uint32_t vmentry_ctrl;
};

extern struct vmcs_config vmcs_config;

#define NR_AUTOLOAD_MSRS 8

/* the horror. */
struct desc_struct {
        union {
                struct {
                        unsigned int a;
                        unsigned int b;
                };
                struct {
                        uint16_t limit0;
                        uint16_t base0;
                        unsigned base1: 8, type: 4, s: 1, dpl: 2, p: 1;
                        unsigned limit: 4, avl: 1, l: 1, d: 1, g: 1, base2: 8;
                };
        };
} __attribute__((packed));

/* LDT or TSS descriptor in the GDT. 16 bytes. */
struct ldttss_desc64 {
	uint16_t limit0;
	uint16_t base0;
	unsigned base1 : 8, type : 5, dpl : 2, p : 1;
	unsigned limit1 : 4, zero0 : 3, g : 1, base2 : 8;
	uint32_t base3;
	uint32_t zero1;
} __attribute__((packed));

static char * const VMX_EXIT_REASON_NAMES[] = {
	VMX_EXIT_REASONS
};
