#ifndef KERNEL_INTERRUPT_H_
# define KERNEL_INTERRUPT_H_

# define IRQ0 32
# define IRQ1 33
# define IRQ2 34
# define IRQ3 35
# define IRQ4 36
# define IRQ5 37
# define IRQ6 38
# define IRQ7 39
# define IRQ8 40
# define IRQ9 41
# define IRQ10 42
# define IRQ11 43
# define IRQ12 44
# define IRQ13 45
# define IRQ14 46
# define IRQ15 47

typedef struct
{
   uint32 ds;                  // Data segment selector
   uint32 edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha.
   uint32 int_no, err_code;    // Interrupt number and error code (if applicable)
   uint32 eip, cs, eflags, useresp, ss; // Pushed by the processor automatically.
} registers_t;

char	*interrupt_errors[256];

typedef void (*isr_t)(registers_t *);
isr_t	interrupt_handlers[256];

void	isr_handler(registers_t regs);
void	irq_handler(registers_t regs);

isr_t	interrupt_handler_register(uint8 id, isr_t isr);
char	*interrupt_error_get(uint8 id);

#endif
