#include <kernel/interrupt.h>
#include <io.h>

t_idt_entry g_idt[256];

static void
	idt_fill_descriptor()
{
	t_ulong idt_address;
	t_ulong idt_ptr[2];

	idt_address = (t_ulong) g_idt;
	idt_ptr[0] = (sizeof(t_idt_entry) * 256) + ((idt_address & 0xffff) << 16);
	idt_ptr[1] = idt_address >> 16;
	load_idt(idt_ptr);
}

static void
	idt_pic_remap()
{
	outb(0x20, 0x11);
	outb(0xA0, 0x11);
	outb(0x21, 0x20);
	outb(0xA1, 40);
	outb(0x21, 0x04);
	outb(0xA1, 0x02);
	outb(0x21, 0x01);
	outb(0xA1, 0x01);
	outb(0x21, 0x0);
	outb(0xA1, 0x0);
}

void
	idt_init()
{
	idt_fill_descriptor();
	idt_pic_remap();
	idt_set(32, 0x08, 0x8e, &irq0);
	idt_set(33, 0x08, 0x8e, &irq1);
	idt_set(34, 0x08, 0x8e, &irq2);
	idt_set(35, 0x08, 0x8e, &irq3);
	idt_set(36, 0x08, 0x8e, &irq4);
	idt_set(37, 0x08, 0x8e, &irq5);
	idt_set(38, 0x08, 0x8e, &irq6);
	idt_set(39, 0x08, 0x8e, &irq7);
	idt_set(40, 0x08, 0x8e, &irq8);
	idt_set(41, 0x08, 0x8e, &irq9);
	idt_set(42, 0x08, 0x8e, &irq10);
	idt_set(43, 0x08, 0x8e, &irq11);
	idt_set(44, 0x08, 0x8e, &irq12);
	idt_set(45, 0x08, 0x8e, &irq13);
	idt_set(46, 0x08, 0x8e, &irq14);
	idt_set(47, 0x08, 0x8e, &irq15);
}
