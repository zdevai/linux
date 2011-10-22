/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
static inline void arch_decomp_setup(void)
{
	ucuart_init_amba01x(0x16000000);
}
