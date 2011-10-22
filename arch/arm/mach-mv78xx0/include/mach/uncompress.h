/*
 * arch/arm/mach-mv78xx0/include/mach/uncompress.h
 *
 * This file is licensed under the terms of the GNU General Public
 * License version 2.  This program is licensed "as is" without any
 * warranty of any kind, whether express or implied.
 */
#include <mach/mv78xx0.h>

static inline void arch_decomp_setup(void)
{
	ucuart_init_8250(UART0_PHYS_BASE, 2, UCUART_IO_MEM8);
}
