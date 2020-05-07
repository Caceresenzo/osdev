#include <driver/serial.h>

void
	serial_initialize(uint16 port)
{
	outb(PORT_OFFSET_INT_ENABLE_REG(port), SERIAL_BIT_INT_NONE);
	outb(PORT_OFFSET_LINE_CONTROL_REG(port), SERIAL_BIT_DLAB_ON);
	outb(PORT_OFFSET_BRATE_DIVISOR_LOW(port), DIVISOR_BAUD_RATE_38400_LOW);
	outb(PORT_OFFSET_BRATE_DIVISOR_HIGH(port), DIVISOR_BAUD_RATE_38400_HIGH);
	outb(PORT_OFFSET_LINE_CONTROL_REG(port), SERIAL_BIT_DLAB_OFF);
	outb(PORT_OFFSET_LINE_CONTROL_REG(port), SERIAL_BIT_DATA_8 | SERIAL_BIT_PARITY_NONE | SERIAL_BIT_STOP_ONE);
	outb(PORT_OFFSET_INT_CONTROL_REG(port), 0xC7);
	outb(PORT_OFFSET_MODEM_CONTROL_REG(port), 0x0B);
}

bool
	serial_available(uint16 port)
{
	return (!!(inb(PORT_OFFSET_LINE_STATUS_REG(port)) & SERIAL_DR));
}

uint8
	serial_read(uint16 port)
{
	while (!serial_available(port))
		;
	return (inb(port));
}

bool
	serial_is_transmit_empty(uint16 port)
{
	return (!!(inb(PORT_OFFSET_LINE_STATUS_REG(port)) & SERIAL_THRE));
}

void
	serial_write(uint16 port, uint8 chr)
{
	while (!serial_is_transmit_empty(port))
		;
	outb(port, chr);
}

void
	serial_write_str(uint16 port, uint8 *str)
{
	while (*str)
		serial_write(port, *str++);
}
