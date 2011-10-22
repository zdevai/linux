/*
 * arch/arm/mach-prima2/include/mach/uncompress.h
 *
 * Copyright (c) 2011 Cambridge Silicon Radio Limited, a CSR plc group company.
 *
 * Licensed under GPLv2 or later.
 */

#ifndef __ASM_ARCH_UNCOMPRESS_H
#define __ASM_ARCH_UNCOMPRESS_H

#include <mach/uart.h>

#define ARCH_HAVE_UCUART_GENERIC

static inline void arch_decomp_setup(void)
{
	ucuart_init(SIRFSOC_UART1_PA_BASE, 0, UCUART_IO_MEM32,
			SIRFSOC_UART_TXFIFO_DATA, SIRFSOC_UART_TXFIFO_STATUS,
			SIRFSOC_UART1_TXFIFO_FULL, 0, 0, 0, 0);
}
#endif
