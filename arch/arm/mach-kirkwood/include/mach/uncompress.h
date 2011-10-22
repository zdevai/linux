/*
 * arch/arm/mach-kirkwood/include/mach/uncompress.h
 *
 * This file is licensed under the terms of the GNU General Public
 * License version 2.  This program is licensed "as is" without any
 * warranty of any kind, whether express or implied.
 */
#include <mach/kirkwood.h>

#define ARCH_HAVE_UCUART_GENERIC

static inline void arch_decomp_setup(void)
{
	ucuart_init_8250(UART0_PHYS_BASE, 2, UCUART_IO_MEM8);
}
