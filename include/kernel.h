#ifndef _KERNEL_H
# define _KERNEL_H

# define sti() asm("sti");
# define cli() asm("cli");

void	kmain(void);

#endif
