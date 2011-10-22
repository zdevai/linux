/*
 * arch/arm/mach-ks8695/include/mach/uncompress.h
 *
 * Copyright (C) 2006 Ben Dooks <ben@simtec.co.uk>
 * Copyright (C) 2006 Simtec Electronics
 *
 * KS8695 - Kernel uncompressor
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __ASM_ARCH_UNCOMPRESS_H
#define __ASM_ARCH_UNCOMPRESS_H

#include <mach/regs-uart.h>

#define ARCH_HAVE_UCUART_GENERIC

static inline void arch_decomp_setup(void)
{
	ucuart_init(KS8695_UART_PA, 0, UCUART_MEM32, KS8695_URTH,
			KS8695_URLS, URLS_URTHRE, URLS_URTHRE,
			KS8695_URLS, URLS_URTE, URLS_URTE);
}

#endif
