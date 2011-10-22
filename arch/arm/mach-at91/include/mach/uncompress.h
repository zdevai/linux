/*
 * arch/arm/mach-at91/include/mach/uncompress.h
 *
 *  Copyright (C) 2003 SAN People
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __ASM_ARCH_UNCOMPRESS_H
#define __ASM_ARCH_UNCOMPRESS_H

#include <linux/atmel_serial.h>

#if defined(CONFIG_AT91_EARLY_DBGU)
#define UART_OFFSET (AT91_DBGU + AT91_BASE_SYS)
#elif defined(CONFIG_AT91_EARLY_USART0)
#define UART_OFFSET AT91_USART0
#elif defined(CONFIG_AT91_EARLY_USART1)
#define UART_OFFSET AT91_USART1
#elif defined(CONFIG_AT91_EARLY_USART2)
#define UART_OFFSET AT91_USART2
#elif defined(CONFIG_AT91_EARLY_USART3)
#define UART_OFFSET AT91_USART3
#elif defined(CONFIG_AT91_EARLY_USART4)
#define UART_OFFSET AT91_USART4
#elif defined(CONFIG_AT91_EARLY_USART5)
#define UART_OFFSET AT91_USART5
#elif
#define UART_OFFSET 0

/*
 * The following code assumes the serial port has already been
 * initialized by the bootloader.  If you didn't setup a port in
 * your bootloader then nothing will appear (which might be desired).
 *
 * This does not append a newline
 */
static inline void arch_decomp_setup(void)
{
	ucuart_init(UART_OFFSET, 0, UCUART_IO_MEM32, ATMEL_US_THR,
			ATMEL_US_CSR, ATMEL_US_TXRDY, ATMEL_US_TXRDY,
			ATMEL_US_CSR, ATMEL_US_TXEMPTY, ATMEL_US_TXEMPTY);
}

#endif