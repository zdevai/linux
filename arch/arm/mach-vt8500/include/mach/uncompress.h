/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
static inline void arch_decomp_setup(void)
{
	ucuart_init(0xd8200000, 0, UCUART_IO_MEM8, 0, 0x1C, 0x2, 0, 0, 0, 0);
}
