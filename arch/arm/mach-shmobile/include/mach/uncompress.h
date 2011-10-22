/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#define ARCH_UCUART_NONGENERIC

static void putc(int c)
{
}

static inline void flush(void)
{
}

#define arch_decomp_setup()
