#include <arch/i386/vga.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <kernel/tty.h>

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t *const VGA_MEMORY = (uint16_t*) 0xB8000;

static size_t terminal_row;
static size_t terminal_column;
static uint8_t terminal_color;
static uint16_t *terminal_buffer;

void terminal_initialize(void) {
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = VGA_MEMORY;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

void terminal_setcolor(uint8_t color) {
	terminal_color = color;
}

void terminal_putentryat(unsigned char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_scroll(int down) {
	if (down) {
		memmove(terminal_buffer, terminal_buffer + VGA_WIDTH, VGA_WIDTH * sizeof(uint16_t) * VGA_HEIGHT);
		for (size_t x = 0; x < VGA_WIDTH; ++x) {
			terminal_putentryat(' ', terminal_color, x, VGA_HEIGHT - 1);
		}
	} else {
		memmove(terminal_buffer + VGA_WIDTH, terminal_buffer, VGA_WIDTH * sizeof(uint16_t) * VGA_HEIGHT);
		for (size_t x = 0; x < VGA_WIDTH; ++x) {
			terminal_putentryat(' ', terminal_color, x, 0);
		}
	}
}

void terminal_putcharat(char chr, size_t x, size_t y) {
	unsigned char uchhr = chr;

	terminal_putentryat(uchhr, terminal_color, x, y);
}

void terminal_putchar(char chr) {
	unsigned char uchhr = chr;

	if (uchhr != '\n')
		terminal_putentryat(uchhr, terminal_color, terminal_column, terminal_row);
	if (++terminal_column == VGA_WIDTH || uchhr == '\n')
	{
		terminal_column = 0;
		if (terminal_row + 1 == VGA_HEIGHT)
		{
			terminal_scroll(1);
		} else {
			terminal_row++;
		}
	}
}

void terminal_write(const char *data, size_t size) {
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}

void terminal_writestring(const char *data) {
	terminal_write(data, strlen(data));
}

void terminal_backspace(void) {
	if (terminal_column != 0) {
		--terminal_column;
		terminal_putchar(' ');
		--terminal_column;
	}
}
