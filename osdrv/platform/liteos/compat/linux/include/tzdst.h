/*----------------------------------------------------------------------------
 * Copyright (c) <2013-2015>, <Huawei Technologies Co., Ltd>
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 * conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 * of conditions and the following disclaimer in the documentation and/or other materials
 * provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific prior written
 * permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *---------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
 * Notice of Export Control Law
 * ===============================================
 * Huawei LiteOS may be subject to applicable export control laws and regulations, which might
 * include those applicable to Huawei LiteOS of U.S. and the country in which you are located.
 * Import, export and usage of Huawei LiteOS in any manner by you shall be in compliance with such
 * applicable export control laws and regulations.
 *---------------------------------------------------------------------------*/

#ifndef _LOCALTIME_H
#define _LOCALTIME_H

#include <time.h>

__BEGIN_DECLS

#ifdef __LITEOS__
/**
 *@ingroup localtime
 *@brief Set Time Zone.
 *
 *@par Description:
 *This API is used to set the time zone.
 *
 *@attention
 *<ul>
 *<li>When setting time zones, format is required to be "tzn[+/-]hh[:mm[:ss]][dzn]" .</li>
 *</ul>
 *
 *@param buff The string point to the time zone going to be setting.
 *
 *@retval   None
 *@since Huawei LiteOS V200R001C00
 */
void settimezone(const char *);

/**
 *@ingroup localtime
 *@brief Disable daylight saving time.
 *
 *@par Description:
 *This API is used to make daylight saving time useless.
 *
 *@param None.
 *
 *@retval   None
 *@since Huawei LiteOS V200R001C00
 */
int dst_disable(VOID);

/**
 *@ingroup localtime
 *@brief Enable daylight saving time..
 *
 *@par Description:
 *This API is used to configure daylight saving time.
 *
 *@attention
 *<ul>
 *<li>When config dst, The configuration format has strict requirements.</li>
 *<li>The first configuration format for example "Feb-03 03:00:00"</li>
 *<li>The second configuration format for example "Oct-1st-Fri 03:00:00"</li>
 *<li>The abbreviations for the months are "Jan",  "Feb", "Mar",  "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", and "Dec".</li>
 *<li>The abbreviations for the days of the week are "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", and "Sat".</li>
 *<li>The abbreviations for the weeks of the month are "1st", "2nd", "3rd", "4th", "5th"</li>
 *<li>When it's only four weekdays this month, the effect of "5th" is the same as "Last"</li>
 *</ul>
 *
 *@param strDstStartTime The string point to the DST start going to be setting.
 *@param strDstEndTime The string point to the DST end going to be setting.
 *@param swForwardSeconds Indicates the number of seconds that time is allocated when entering DST interval.
 *
 *@retval   0 Succeed.
 *@retval  -1 Failed.
 *@since Huawei LiteOS V200R001C00
 */
int dst_enable(const char *, const char *, int);
/**
 *@ingroup localtime
 *@brief Inquire daylight saving time.
 *
 *@par Description:
 *This API is used to inquire daylight saving time.
 *
 *@param year            Represents the year to query start from 1900.
 *@param pstDstStart  Used to store daylight savings time start time
 *@param pstDstEnd    Used to store daylight savings time end time
 *
 *@retval   0 Succeed.
 *@retval  -1 Failed.
 *@since Huawei LiteOS V200R001C00
 */
int dst_inquire(int, struct tm *, struct tm *);
#endif /* __LITEOS__ */
__END_DECLS


#endif /* _LOCALTIME_H */