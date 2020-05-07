#ifndef KERNEL_H
# define KERNEL_H

# define PANIC(msg) panic(__FILE__, __LINE__, msg);
# define ASSERT(b) ((b) ? (void)0 : panic_assert(__FILE__, __LINE__, #b, NULL))

# define sti() asm("sti");
# define cli() asm("cli");
# define int(x) asm volatile("int %0":: "N"(x));

void	kmain(void);

void	panic(char *file, uint32 line, char *reason);
bool	panic_assert(char *file, uint32 line, char *condition, char *message);

#endif
