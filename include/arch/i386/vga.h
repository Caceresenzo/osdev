#ifndef ARCH_I386_VGA_H
# define ARCH_I386_VGA_H

# include <common.h>

# define VGA_PORT_CONTROL 0x3D4
# define VGA_PORT_DATA 0x3D5

# define VGA_DATA_CURSOR_LOCATION_HIGH 14
# define VGA_DATA_CURSOR_LOCATION_LOW 15

# define VGA_WIDTH 80
# define VGA_HEIGHT 25

# define VGA_MEMORY_START_ADDRESS ((uint16 *) 0xB8000)
# define VGA_MEMORY_SIZE_BYTE (VGA_WIDTH * sizeof(uint16) * VGA_HEIGHT)

# define VGA_DEFAULT_COLOR (vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK))
# define VGA_ENTRY_EMPTY (vga_entry(' ', VGA_DEFAULT_COLOR))

typedef enum {
	VGA_COLOR_BLACK			= 0, //
	VGA_COLOR_BLUE			= 1, //
	VGA_COLOR_GREEN			= 2, //
	VGA_COLOR_CYAN			= 3, //
	VGA_COLOR_RED			= 4, //
	VGA_COLOR_MAGENTA		= 5, //
	VGA_COLOR_BROWN			= 6, //
	VGA_COLOR_LIGHT_GREY	= 7, //
	VGA_COLOR_DARK_GREY		= 8, //
	VGA_COLOR_LIGHT_BLUE	= 9, //
	VGA_COLOR_LIGHT_GREEN	= 10, //
	VGA_COLOR_LIGHT_CYAN	= 11, //
	VGA_COLOR_LIGHT_RED		= 12, //
	VGA_COLOR_LIGHT_MAGENTA	= 13, //
	VGA_COLOR_LIGHT_BROWN	= 14, //
	VGA_COLOR_WHITE			= 15, //
} vga_color_t;

typedef enum {
	VGA_DIR_UP				= 0, //
	VGA_DIR_DOWN			= 1, //
} vga_direction_t;

static inline uint8
	vga_entry_color(vga_color_t fg, vga_color_t bg)
{
	return (fg | bg << 4);
}

static inline uint16
	vga_entry(uint8 chr, uint8 color)
{
	return ((uint16) chr | (uint16) color << 8);
}

static inline size_t
	vga_index(size_t x, size_t y)
{
	return (y * VGA_WIDTH + x);
}

void	vga_initialize(void);
void	vga_set_color(uint8 color);
void	vga_set_colors(vga_color_t fg, vga_color_t bg);
void	vga_move_cursor();
void	vga_put_char(uint8 chr);
void	vga_put_entry_at(uint8 chr, uint8 color, size_t x, size_t y);
void	vga_write(const char* data, size_t size);
void	vga_write_string(const char* data);
void	vga_backspace(void);
void	vga_clear(void);
void	vga_clear_line(size_t line);

#endif
