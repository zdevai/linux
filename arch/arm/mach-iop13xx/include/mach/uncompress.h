#include <mach/hardware.h>

static inline void arch_decomp_setup(void)
{
	ucuart_init_8250(IOP13XX_UART1_PHYS, 2, UCUART_IO_MEM32);
}
