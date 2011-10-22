/*
 *  arch/arm/mach-ebsa110/include/mach/uncompress.h
 *
 *  Copyright (C) 1996,1997,1998 Russell King
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

static inline void arch_decomp_setup(void)
{
	ucuart_init_8250(0xf0000be0, 2, UCUART_IO_MEM8);
}
