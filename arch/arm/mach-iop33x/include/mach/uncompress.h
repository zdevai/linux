/*
 * arch/arm/mach-iop33x/include/mach/uncompress.h
 */

#include <asm/mach-types.h>
#include <mach/hardware.h>

static inline void arch_decomp_setup(void)
{
	if (machine_is_iq80331() || machine_is_iq80332())
		ucuart_init_8250(IOP33X_UART0_PHYS, 2, UCUART_IO_MEM32);
	else
		ucuart_init_8250(0xfe800000, 2, UCUART_IO_MEM32);
}
