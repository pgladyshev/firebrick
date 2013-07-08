/**
 * @file
 *
 * AMD CPU Execution Cache Allocation functions.
 *
 * Contains code for doing Execution Cache Allocation for ROM space
 *
 * @xrefitem bom "File Content Label" "Release Content"
 * @e project:      AGESA
 * @e sub-project:  CPU
 * @e \$Revision: 44323 $   @e \$Date: 2010-12-22 01:24:58 -0700 (Wed, 22 Dec 2010) $
 *
 */
/*
 ******************************************************************************
 *
 * Copyright (c) 2011, Advanced Micro Devices, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Advanced Micro Devices, Inc. nor the names of
 *       its contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ADVANCED MICRO DEVICES, INC. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */

#ifndef _CPU_CACHE_INIT_H_
#define _CPU_CACHE_INIT_H_

/*----------------------------------------------------------------------------
 *   Mixed (DEFINITIONS AND MACROS / TYPEDEFS, STRUCTURES, ENUMS)
 *
 *----------------------------------------------------------------------------
 */

/*-----------------------------------------------------------------------------
 *                         DEFINITIONS AND MACROS
 *
 *-----------------------------------------------------------------------------
 */
#define AMD_MTRR_FIX4K_BASE     0x268
#define AMD_MTRR_VARIABLE_BASE6 0x20C
#define AMD_MTRR_VARIABLE_BASE7 0x20E

#define WP_IO 0x0505050505050505ull

#define AGESA_CACHE_SIZE_REDUCED              1
#define AGESA_CACHE_REGIONS_ACROSS_1MB        2
#define AGESA_CACHE_REGIONS_ACROSS_4GB        3
#define AGESA_REGION_NOT_ALIGNED_ON_BOUNDARY  4
#define AGESA_CACHE_START_ADDRESS_LESS_D0000  5
#define AGESA_THREE_CACHE_REGIONS_ABOVE_1MB   6
#define AGESA_DEALLOCATE_CACHE_REGIONS        7

/*----------------------------------------------------------------------------
 *                         TYPEDEFS, STRUCTURES, ENUMS
 *
 *----------------------------------------------------------------------------
 */
/// Cache Information
typedef struct {
  IN       UINT32  BspStackSize;              ///< Stack size of BSP
  IN       UINT32  Core0StackSize;            ///< Stack size of primary cores
  IN       UINT32  Core1StackSize;            ///< Stack size of all non primary cores
  IN       UINT32  MemTrainingBufferSize;     ///< Memory training buffer size
  IN       UINT32  SharedMemSize;             ///< Shared memory size
  IN       UINT64  VariableMtrrMask;          ///< Mask to apply before variable MTRR writes
} CACHE_INFO;

/*----------------------------------------------------------------------------
 *                           FUNCTIONS PROTOTYPE
 *
 *----------------------------------------------------------------------------
 */
AGESA_STATUS
AllocateExecutionCache (
  IN AMD_CONFIG_PARAMS *StdHeader,
  IN EXECUTION_CACHE_REGION *AmdExeAddrMapPtr
  );

#endif  // _CPU_CACHE_INIT_H_

