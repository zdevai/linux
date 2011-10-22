/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
static inline void arch_decomp_setup(void)
{
	ucuart_init_8250(0x400003f8, 0, UCUART_IO_MEM8);
}
