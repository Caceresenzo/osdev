#include <arch/i386/vga.h>
#include <kernel/idt.h>
#include <kernel/interrupt.h>

idt_entry_t	idt_entries[256] = { 0 };
idt_ptr_t	idt_ptr = (idt_ptr_t) { 0 };

void
	idt_initialize()
{
	idt_ptr.limit = (sizeof(idt_entry_t) * 256) - 1;
	idt_ptr.base = (uint32) &idt_entries;
    outb(0x20, 0x11);
    outb(0xA0, 0x11);
    outb(0x21, 0x20);
    outb(0xA1, 0x28);
    outb(0x21, 0x04);
    outb(0xA1, 0x02);
    outb(0x21, 0x01);
    outb(0xA1, 0x01);
    outb(0x21, 0x0);
    outb(0xA1, 0x0);
	idt_set(0, 0x08, 0x8E, &isr0);
	idt_set(1, 0x08, 0x8E, &isr1);
	idt_set(2, 0x08, 0x8E, &isr2);
	idt_set(3, 0x08, 0x8E, &isr3);
	idt_set(4, 0x08, 0x8E, &isr4);
	idt_set(5, 0x08, 0x8E, &isr5);
	idt_set(6, 0x08, 0x8E, &isr6);
	idt_set(7, 0x08, 0x8E, &isr7);
	idt_set(8, 0x08, 0x8E, &isr8);
	idt_set(9, 0x08, 0x8E, &isr9);
	idt_set(10, 0x08, 0x8E, &isr10);
	idt_set(11, 0x08, 0x8E, &isr11);
	idt_set(12, 0x08, 0x8E, &isr12);
	idt_set(13, 0x08, 0x8E, &isr13);
	idt_set(14, 0x08, 0x8E, &isr14);
	idt_set(15, 0x08, 0x8E, &isr15);
	idt_set(16, 0x08, 0x8E, &isr16);
	idt_set(17, 0x08, 0x8E, &isr17);
	idt_set(18, 0x08, 0x8E, &isr18);
	idt_set(19, 0x08, 0x8E, &isr19);
	idt_set(20, 0x08, 0x8E, &isr20);
	idt_set(21, 0x08, 0x8E, &isr21);
	idt_set(22, 0x08, 0x8E, &isr22);
	idt_set(23, 0x08, 0x8E, &isr23);
	idt_set(24, 0x08, 0x8E, &isr24);
	idt_set(25, 0x08, 0x8E, &isr25);
	idt_set(26, 0x08, 0x8E, &isr26);
	idt_set(27, 0x08, 0x8E, &isr27);
	idt_set(28, 0x08, 0x8E, &isr28);
	idt_set(29, 0x08, 0x8E, &isr29);
	idt_set(30, 0x08, 0x8E, &isr30);
	idt_set(31, 0x08, 0x8E, &isr31);
	idt_set(32, 0x08, 0x8E, &irq0);
	idt_set(33, 0x08, 0x8E, &irq1);
	idt_set(34, 0x08, 0x8E, &irq2);
	idt_set(35, 0x08, 0x8E, &irq3);
	idt_set(36, 0x08, 0x8E, &irq4);
	idt_set(37, 0x08, 0x8E, &irq5);
	idt_set(38, 0x08, 0x8E, &irq6);
	idt_set(39, 0x08, 0x8E, &irq7);
	idt_set(40, 0x08, 0x8E, &irq8);
	idt_set(41, 0x08, 0x8E, &irq9);
	idt_set(42, 0x08, 0x8E, &irq10);
	idt_set(43, 0x08, 0x8E, &irq11);
	idt_set(44, 0x08, 0x8E, &irq12);
	idt_set(45, 0x08, 0x8E, &irq13);
	idt_set(46, 0x08, 0x8E, &irq14);
	idt_set(47, 0x08, 0x8E, &irq15);
	idt_flush((uint32) &idt_ptr);
}

/*
** Set an entry into the Interupt Descriptor Table.
**
** TODO: Uncomment the OR below when we get to using user-mode.
** 			 It sets the interrupt gate's privilege level to 3.
*/

void
	idt_set(int id, uint16 selector, uint8 flags, void *ptr)
{
	uint32		address;

	address = (uint32) ptr;
	idt_entries[id].base_low = address & 0xFFFF;
	idt_entries[id].base_high = (address >> 16) & 0xFFFF;
	idt_entries[id].selector = selector;
	idt_entries[id].zero = 0;
	idt_entries[id].flags = flags /* | 0x60 */;
}
