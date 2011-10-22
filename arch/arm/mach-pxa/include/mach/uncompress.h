/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/serial_reg.h>
#include <asm/mach-types.h>

#define FFUART_BASE	(0x40100000)
#define BTUART_BASE	(0x40200000)
#define STUART_BASE	(0x40700000)

static inline void arch_decomp_setup(void)
{
	unsigned long uart_base;

	if (machine_is_arcom_zeus())
		ucuart_init_8250(0x10000000, 1, UCUART_IO_MEM8); /* nCS4 */
	else if (machine_is_littleton() || machine_is_intelmote2()
			|| machine_is_csb726() || machine_is_stargate2()
			|| machine_is_cm_x300() || machine_is_balloon3())
			uart_base = STUART_BASE;
	else
		uart_base = FFUART_BASE;

	/* Don't do anything if UART is not enabled */
	if (!__raw_readl(uart_base + UART_IER) & UART_IER_UUE)
		return;

	ucuart_init_8250(uart_base, 2, UCUART_IO_MEM8);
}
