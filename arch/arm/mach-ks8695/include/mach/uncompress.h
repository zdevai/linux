/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <mach/regs-uart.h>

static inline void arch_decomp_setup(void)
{
	ucuart_init(KS8695_UART_PA, 0, UCUART_MEM32, KS8695_URTH,
			KS8695_URLS, URLS_URTHRE, URLS_URTHRE,
			KS8695_URLS, URLS_URTE, URLS_URTE);
}
