#include "common.h"

uint8
	inb(uint16 port)
{
	uint8 ret;

	asm volatile ("inb %1, %0" : "=a" (ret) : "dN" (port));
	return (ret);
}

uint16
	inw(uint16 port)
{
	uint16 ret;

	asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
	return (ret);
}

uint32
	inl(uint16 port)
{
	uint32 ret;

	asm volatile ("inl %1, %0" : "=a" (ret) : "dN" (port));
	return (ret);
}

void
	outb(uint16 port, uint8 value)
{
	asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

void
	outw(uint16 port, uint16 value)
{
	asm volatile ("outw %1, %0" : : "dN" (port), "a" (value));
}

void
	outl(uint16 port, uint32 value)
{
	asm volatile ("outl %1, %0" : : "dN" (port), "a" (value));
}
