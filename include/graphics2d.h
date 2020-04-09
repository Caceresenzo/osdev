#ifndef _GRAPHICS2D_H
# define _GRAPHICS2D_H

# include <arch/i386/vga.h>
# include <common.h>

typedef struct	s_graphics2d
{
	uint8		pen_char;
	uint8		pen_color;
	size_t		width;
	size_t		height;
	uint8		*chars;
	uint8		*colors;
}				t_g2d;

bool	g2d_set_pen_color(t_g2d *g2d, vga_color_t fg_color, vga_color_t bg_color);
bool	g2d_set_pen_char(t_g2d *g2d, uint8 chr);

bool	g2d_draw_line_vert(t_g2d *g2d, size_t x_start, size_t x_end, size_t y);
bool	g2d_draw_line_hor(t_g2d *g2d, size_t x, size_t y_start, size_t y_end);

bool	g2d_set_at(t_g2d *g2d, size_t x, size_t y);

bool	g2d_clear(t_g2d *g2d);

bool	g2d_set_dim(t_g2d *g2d, size_t width, size_t height);
bool	g2d_set_buffers(t_g2d *g2d, uint8 *chars, uint8 *colors);

bool	g2d_draw_str(t_g2d *g2d, size_t x, size_t y, char *str);
bool	g2d_draw_char(t_g2d *g2d, size_t x, size_t y, char chr);

bool	g2d_fill(t_g2d *g2d);

#endif
