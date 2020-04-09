#include <common.h>
#include <graphics2d.h>

bool
	g2d_set_pen_char(t_g2d *g2d, uint8 chr)
{
	if (g2d == NULL)
		return (false);
	g2d->pen_char = chr;
	return (true);
}
