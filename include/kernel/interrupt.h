#ifndef _KERNEL_INTERRUPT_H
# define _KERNEL_INTERRUPT_H

# include <sys/types.h>

typedef struct	s_idt_entry {
	t_ushortint	offset_lowerbits;
	t_ushortint	selector;
	t_uchar		zero;
	t_uchar		type_attr;
	t_ushortint	offset_higherbits;
}				t_idt_entry;

t_idt_entry g_idt[256];

void		irq0_handler(void);
void		irq1_handler(void);
void		irq2_handler(void);
void		irq3_handler(void);
void		irq4_handler(void);
void		irq5_handler(void);
void		irq6_handler(void);
void		irq7_handler(void);
void		irq8_handler(void);
void		irq9_handler(void);
void		irq10_handler(void);
void		irq11_handler(void);
void		irq12_handler(void);
void		irq13_handler(void);
void		irq14_handler(void);
void		irq15_handler(void);

extern int	load_idt();

extern int	irq0();
extern int	irq1();
extern int	irq2();
extern int	irq3();
extern int	irq4();
extern int	irq5();
extern int	irq6();
extern int	irq7();
extern int	irq8();
extern int	irq9();
extern int	irq10();
extern int	irq11();
extern int	irq12();
extern int	irq13();
extern int	irq14();
extern int	irq15();


void		idt_init();
void		idt_set(int id, int selector, int type_attr, void *ptr);

#endif
