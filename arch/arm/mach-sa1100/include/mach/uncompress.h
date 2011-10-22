/*
 * arch/arm/mach-sa1100/include/mach/uncompress.h
 *
 * (C) 1999 Nicolas Pitre <nico@fluxnic.net>
 *
 * Reorganised to be machine independent.
 */

#include "hardware.h"

/*
 * The following code assumes the serial port has already been
 * initialized by the bootloader.  We search for the first enabled
 * port in the most probable order.  If you didn't setup a port in
 * your bootloader then nothing will appear (which might be desired).
 */
#define ARCH_HAVE_UCUART_GENERIC

static inline int uart_enabled(int base)
{
	if (__raw_readl((void __iomem *)(base + UTCR3)) & UTCR3_TXE)
		return 1;

	return 0;
}

static inline void arch_decomp_setup(void)
{
	int uart_base;

	if (uart_enabled(_Ser3UTCR0))
		uart_base = _Ser3UTCR0;
	else if (uart_enabled(_Ser1UTCR0))
		uart_base = _Ser1UTCR0;
	else if (uart_enabled(_Ser2UTCR0))
		uart_base = _Ser2UTCR0;
	else
		return;

	ucuart_init(uart_base, 0, UCUART_IO_MEM32, UTDR,
			UTSR1, UTSR1_TNF, UTSR1_TNF,
			0, 0, 0);
}
