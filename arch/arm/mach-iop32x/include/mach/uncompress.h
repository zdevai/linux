/*
 * arch/arm/mach-iop32x/include/mach/uncompress.h
 */
#include <mach/hardware.h>

static inline void arch_decomp_setup(void)
{
	if (machine_is_iq80321())
		ucuart_init_8250(IQ80321_UART, 0, UCUART_IO_MEM8);
	else if (machine_is_iq31244() || machine_is_em7210())
		ucuart_init_8250(IQ31244_UART, 0, UCUART_IO_MEM8);
	else
		ucuart_init_8250(0xfe800000, 0, UCUART_IO_MEM8);
}
