/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <mach/csp/mm_addr.h>

#define BCMRING_UART_0_DR	MM_ADDR_IO_UARTA
#define BCMRING_UART_0_FR	0x18

static inline void arch_decomp_setup(void)
{
	ucuart_init(MM_ADDR_IO_UARTA, 0, UCUART_IO_MEM32, BCMRING_UART_0_DR,
			BCMRING_UART_0_FR, (1 << 5), 0,
			BCMRING_UART_0_FR, (1 << 7) | (1 << 3), (1 << 7));
}
