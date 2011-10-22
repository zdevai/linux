#ifndef __ASM_MACH_UNCOMPRESS_H
#define __ASM_MACH_UNCOMPRESS_H

#define ARCH_UCUART_NONGENERIC

/*
 * This does not append a newline
 */
static void putc(int c)
{
}

static inline void flush(void)
{
}

#define arch_decomp_setup()

#endif /* __ASM_MACH_UNCOMPRESS_H */
