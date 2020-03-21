#include <graphics2d.h>
#include <stddef.h>

bool
	g2d_set_pen_char(t_g2d *g2d, t_uchar chr)
{
	if (g2d == NULL)
		return (false);
	g2d->pen_char = chr;
	return (true);
}
