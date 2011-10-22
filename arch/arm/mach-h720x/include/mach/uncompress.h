/*
 * arch/arm/mach-h720x/include/mach/uncompress.h
 *
 * Copyright (C) 2001-2002 Jungjun Kim
 */

#ifndef __ASM_ARCH_UNCOMPRESS_H
#define __ASM_ARCH_UNCOMPRESS_H

#include <mach/hardware.h>

/* debug-macro.S treats this port as an AMBA01x, but according to the
 * datasheet, this should be a 8250
 */
static inline void arch_decomp_setup(void)
{
	ucuart_init_8250(SERIAL0_BASE, 2, UCUART_IO_MEM8);
}

#endif
