/*
 * arch/arm/mach-ixp2000/include/mach/uncompress.h
 *
 *
 * Original Author: Naeem Afzal <naeem.m.afzal@intel.com>
 * Maintainer: Deepak Saxena <dsaxena@plexity.net>
 *
 * Copyright 2002 Intel Corp.
 *
 *  This program is free software; you can redistribute  it and/or modify it
 *  under  the terms of  the GNU General  Public License as published by the
 *  Free Software Foundation;  either version 2 of the  License, or (at your
 *  option) any later version.
 *
 */

#define ARCH_HAVE_UCUART_GENERIC

static inline void arch_decomp_setup(void)
{
	ucuart_init_8250(0xc0030000, 2, UCUART_IO_MEM32);
}
