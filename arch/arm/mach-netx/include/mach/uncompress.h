/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#define UART1_BASE 0x100a00
#define UART2_BASE 0x100a80

static inline void arch_decomp_setup(void)
{
	ucuart_init_amba01x(UART1_BASE);
	ucuart_init_amba01x(UART2_BASE);
}
