/*
 * arch/arm/mach-ixp23xx/include/mach/uncompress.h
 *
 * Copyright (C) 2002-2004 Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __ASM_ARCH_UNCOMPRESS_H
#define __ASM_ARCH_UNCOMPRESS_H

#include <mach/ixp23xx.h>

#define ARCH_HAVE_UCUART_GENERIC

static inline void arch_decomp_setup(void)
{
	ucuart_init_8250(IXP23XX_UART1_PHYS, 2, UCUART_IO_MEM32);
}

#endif
