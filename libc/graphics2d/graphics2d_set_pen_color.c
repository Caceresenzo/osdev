#include <arch/i386/vga.h>
#include <common.h>
#include <graphics2d.h>

bool
	g2d_set_pen_color(t_g2d *g2d, vga_color_t fg_color, vga_color_t bg_color)
{
	if (g2d == NULL)
		return (false);
	g2d->pen_color = vga_entry_color(fg_color, bg_color);
	return (true);
}
