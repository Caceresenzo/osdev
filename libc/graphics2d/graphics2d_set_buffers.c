#include <graphics2d.h>
#include <stddef.h>

bool
	g2d_set_buffers(t_g2d *g2d, t_uchar *chars, uint8_t *colors)
{
	if (g2d == NULL)
		return (false);
	g2d->chars = chars;
	g2d->colors = colors;
	return (true);
}
