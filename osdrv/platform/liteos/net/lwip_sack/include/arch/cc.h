/*
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved.
 * Copyright (c) <2013-2015>, <Huawei Technologies Co., Ltd>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Adam Dunkels <adam@sics.se>
 *
 */

/**********************************************************************************
 * Notice of Export Control Law
 * ===============================================
 * Huawei LiteOS may be subject to applicable export control laws and regulations, which
 * might include those applicable to Huawei LiteOS of U.S. and the country in which you
 * are located.
 * Import, export and usage of Huawei LiteOS in any manner by you shall be in compliance
 * with such applicable export control laws and regulations.
 **********************************************************************************/

#ifndef __CC_H__
#define __CC_H__

#include "los_typedef.h"
#include <sys/time.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define LWIP_TIMEVAL_PRIVATE 0

/* Types based on stdint.h */
typedef uint8_t            u8_t;
typedef int8_t             s8_t;
typedef uint16_t           u16_t;
typedef int16_t            s16_t;
typedef uint32_t           u32_t;
typedef int32_t            s32_t;
typedef int64_t             s64_t;
typedef uint64_t            u64_t;
typedef AARCHPTR          mem_ptr_t;

/* Define (sn)printf formatters for these lwIP types */
#define U16_F "hu"
#define S16_F "hd"
#define X16_F "hx"
#define U32_F "lu"
#define S32_F "ld"
#define X32_F "lx"
#define SZT_F "uz"

/* ARM/LPC17xx is little endian only */
#ifdef BYTE_ORDER
#undef BYTE_ORDER
#endif
#define BYTE_ORDER LITTLE_ENDIAN

/* Use LWIP error codes */

#if defined(__arm__) && defined(__ARMCC_VERSION)
    /* Keil uVision4 tools */
    #define PACK_STRUCT_BEGIN __packed
    #define PACK_STRUCT_STRUCT
    #define PACK_STRUCT_END
    #define PACK_STRUCT_FIELD(fld) fld
    #define ALIGNED(n)  __align(n)
#elif defined (__IAR_SYSTEMS_ICC__)
    /* IAR Embedded Workbench tools */
    #define PACK_STRUCT_BEGIN __packed
    #define PACK_STRUCT_STRUCT
    #define PACK_STRUCT_END
    #define PACK_STRUCT_FIELD(fld) fld
    #error NEEDS ALIGNED // FIXME TBD
#else
    /* GCC tools (CodeSourcery) */
    #define PACK_STRUCT_BEGIN
    #define PACK_STRUCT_STRUCT __attribute__ ((__packed__))
    #define PACK_STRUCT_END
    #define PACK_STRUCT_FIELD(fld) fld
    #define ALIGNED(n)  __attribute__((aligned (n)))
#endif

#ifdef LWIP_DEBUG

#include "stdio.h"

void assert_printf(char *msg, int line, char *file);

/* Plaform specific diagnostic output */
#define LWIP_PLATFORM_DIAG(vars) printf vars
#define LWIP_PLATFORM_ASSERT(flag) { assert_printf((flag), __LINE__, __FILE__); }
#else
#define LWIP_PLATFORM_DIAG(msg) { ; }
#define LWIP_PLATFORM_ASSERT(flag) { ; }
#endif


#define LWIP_PLATFORM_HTONS(x)      htons(x)
#define LWIP_PLATFORM_HTONL(x)      htonl(x)

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __CC_H__ */
