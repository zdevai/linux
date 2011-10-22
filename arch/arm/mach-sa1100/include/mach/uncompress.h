/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include "hardware.h"

static inline int uart_enabled(int base)
{
	if (__raw_readl((void __iomem *)(base + UTCR3)) & UTCR3_TXE)
		return 1;

	return 0;
}

static inline void arch_decomp_setup(void)
{
	int uart_base;

	if (uart_enabled(_Ser3UTCR0))
		uart_base = _Ser3UTCR0;
	else if (uart_enabled(_Ser1UTCR0))
		uart_base = _Ser1UTCR0;
	else if (uart_enabled(_Ser2UTCR0))
		uart_base = _Ser2UTCR0;
	else
		return;

	ucuart_init(uart_base, 0, UCUART_IO_MEM32, UTDR,
			UTSR1, UTSR1_TNF, UTSR1_TNF,
			0, 0, 0);
}
