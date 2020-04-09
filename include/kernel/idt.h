#ifndef KERNEL_IDT_H
# define KERNEL_IDT_H

# include <common.h>

/*
** A struct describing an interrupt gate.
**
** @param base_low
** 			The lower 16 bits of the address to jump to when this interrupt fires.
** @param selector
** 			Kernel segment selector.
** @param zero
** 			Litterally.
** @param flags
**			Format:
**			+-------------------------------+
**			| 7 | 6 5 | 4			  0 |
**			| P | DPL | Always b00110 or 14 |
**			+-------------------------------+
**			 P: Is segment present? (1 = Yes).
**			 DPL: Descriptor privilege level - Ring 0 - 3.
** @param base_high
** 			The upper 16 bits of the address to jump to.
** @note ORDER IS IMPORTANT !!
*/
typedef struct __attribute__((packed))
{
	uint16	base_low;
	uint16	selector;
	uint8	zero;
	uint8	flags;
	uint16	base_high;
} idt_entry_t;

/*
** A struct describing a pointer to an array of interrupt handlers.
** This is in a format suitable for giving to 'lidt'.
**
** @param limit
** 			The upper 16 bits of all selector limits.
** @param base
** 			The address of the first idt_entry_t struct.
** @note ORDER IS IMPORTANT !!
*/
typedef struct __attribute__((packed))
{
	uint16	limit;
	uint32	base;
} idt_ptr_t;

idt_entry_t idt_entries[256];
idt_ptr_t   idt_ptr;

void		idt_initialize();
void		idt_set(int id, uint16 selector, uint8 flags, void *ptr);

extern void	idt_flush(uint32 address);

extern void	isr0(void);
extern void	isr1(void);
extern void	isr2(void);
extern void	isr3(void);
extern void	isr4(void);
extern void	isr5(void);
extern void	isr6(void);
extern void	isr7(void);
extern void	isr8(void);
extern void	isr9(void);
extern void	isr10(void);
extern void	isr11(void);
extern void	isr12(void);
extern void	isr13(void);
extern void	isr14(void);
extern void	isr15(void);
extern void	isr16(void);
extern void	isr17(void);
extern void	isr18(void);
extern void	isr19(void);
extern void	isr20(void);
extern void	isr21(void);
extern void	isr22(void);
extern void	isr23(void);
extern void	isr24(void);
extern void	isr25(void);
extern void	isr26(void);
extern void	isr27(void);
extern void	isr28(void);
extern void	isr29(void);
extern void	isr30(void);
extern void	isr31(void);

extern void	irq0();
extern void	irq1();
extern void	irq2();
extern void	irq3();
extern void	irq4();
extern void	irq5();
extern void	irq6();
extern void	irq7();
extern void	irq8();
extern void	irq9();
extern void	irq10();
extern void	irq11();
extern void	irq12();
extern void	irq13();
extern void	irq14();
extern void	irq15();

#endif
