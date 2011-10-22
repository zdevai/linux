/*
 *  arch/arm/mach-clps711x/include/mach/uncompress.h
 *
 *  Copyright (C) 2000 Deep Blue Solutions Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#include <mach/hardware.h>
#include <asm/hardware/clps7111.h>

#ifdef CONFIG_DEBUG_CLPS711X_UART2
#define SYSFLGx	SYSFLG2
#define UARTDRx	UARTDR2
#else
#define SYSFLGx	SYSFLG1
#define UARTDRx	UARTDR1
#endif

#define ARCH_HAVE_UCUART_GENERIC

static inline void arch_decomp_setup(void)
{
	ucuart_init(CLPS7111_PHYS_BASE, 0, UCUART_IO_MEM32, UARTDRx,
			SYSFLGx, SYSFLG_UTXOFF, 0,
			SYSFLGx, SYSFLG_UBUSY, 0);
}
