#include <arch/i386/vga.h>
#include <kernel/ports.h>
#include <string.h>

static size_t	vga_row;
static size_t	vga_column;
static uint8	vga_color;
static uint16	*vga_buffer;

void
	vga_initialize(void)
{
	vga_row = 0;
	vga_column = 0;
	vga_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	vga_buffer = VGA_MEMORY_START_ADDRESS;
	vga_clear();
}

void
	vga_set_color(uint8 color)
{
	vga_color = color;
}

void
	vga_set_colors(vga_color_t fg, vga_color_t bg)
{
	vga_set_color(vga_entry_color(fg, bg));
}

void
	vga_put_entry_at(uint8 chr, uint8 color, size_t x, size_t y)
{
	vga_buffer[vga_index(x, y)] = vga_entry(chr, color);
}

void
	vga_scroll(vga_direction_t direction)
{
	if (direction == VGA_DIR_UP)
	{
		memmove(vga_buffer + VGA_WIDTH, vga_buffer, VGA_MEMORY_SIZE_BYTE);
		vga_clear_line(0);
	}
	else if (direction == VGA_DIR_DOWN)
	{
		memmove(vga_buffer, vga_buffer + VGA_WIDTH, VGA_MEMORY_SIZE_BYTE);
		vga_clear_line(VGA_HEIGHT - 1);
	}
}

void
	vga_put_char_at(uint8 chr, size_t x, size_t y)
{
	vga_put_entry_at(chr, vga_color, x, y);
}

void
	vga_clear(void)
{
	vga_column = 0;
	vga_row = 0;
	for (size_t y = 0; y < VGA_HEIGHT; y++)
		for (size_t x = 0; x < VGA_WIDTH; x++)
			vga_buffer[vga_index(x, y)] = VGA_ENTRY_EMPTY;
	vga_move_cursor();
}

void
	vga_clear_line(size_t line)
{
	for (size_t x = 0; x < VGA_WIDTH; ++x)
		vga_put_entry_at(' ', vga_color, x, line);
}

void
	vga_move_cursor(void)
{
	uint16	location;

	location = vga_index(vga_column, vga_row);
	outb(VGA_COMMAND, VGA_DATA_CURSOR_LOCATION_HIGH);
	outb(VGA_DATA, (location >> 8) & 0xFF);
	outb(VGA_COMMAND, VGA_DATA_CURSOR_LOCATION_LOW);
	outb(VGA_DATA, location & 0xFF);
}

void
	vga_put_char(uint8 chr)
{
	if (chr != '\n')
		vga_put_entry_at(chr, vga_color, vga_column, vga_row);
	if (++vga_column == VGA_WIDTH || chr == '\n')
	{
		vga_column = 0;
		if (vga_row + 1 == VGA_HEIGHT)
			vga_scroll(VGA_DIR_DOWN);
		else
			vga_row++;
	}
	vga_move_cursor();
}

void
	vga_write(const char *data, size_t size)
{
	for (size_t i = 0; i < size; i++)
		vga_put_char(data[i]);
}

void
	vga_write_string(const char *data)
{
	vga_write(data, strlen(data));
}

void
	vga_backspace(void)
{
	if (vga_column != 0) {
		--vga_column;
		vga_put_char(' ');
		--vga_column;
	}
	vga_move_cursor();
}
