/*
 * Copyright (C) 2008-2009 Paulius Zaleckas <paulius.zaleckas@teltonika.lt>
 *
 * Based on mach-pxa/include/mach/uncompress.h:
 * Copyright:	(C) 2001 MontaVista Software Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef __MACH_UNCOMPRESS_H
#define __MACH_UNCOMPRESS_H

#include <mach/hardware.h>

#define ARCH_HAVE_UCUART_GENERIC

static inline void arch_decomp_setup(void)
{
	ucuart_init_8250(GEMINI_UART_BASE, 2, UCUART_IO_MEM32);
}

#endif /* __MACH_UNCOMPRESS_H */
