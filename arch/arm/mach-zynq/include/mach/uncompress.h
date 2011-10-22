/* arch/arm/mach-zynq/include/mach/uncompress.h
 *
 *  Copyright (C) 2011 Xilinx
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __MACH_UNCOMPRESS_H__
#define __MACH_UNCOMPRESS_H__

#include <mach/zynq_soc.h>
#include <mach/uart.h>

#define ARCH_HAVE_UCUART_GENERIC

static inline void arch_decomp_setup(void)
{
	ucuart_init(LL_UART_PADDR, 0, UCUART_IO_MEM32, UART_FIFO_OFFSET,
			UART_SR_OFFSET, UART_SR_TXFULL, 0,
			UART_SR_OFFSET, UART_SR_TXEMPTY, UART_SR_TXEMPTY);
}

#endif
