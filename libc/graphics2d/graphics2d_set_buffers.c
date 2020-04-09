#include <common.h>
#include <graphics2d.h>

bool
	g2d_set_buffers(t_g2d *g2d, uint8 *chars, uint8 *colors)
{
	if (g2d == NULL)
		return (false);
	g2d->chars = chars;
	g2d->colors = colors;
	return (true);
}
