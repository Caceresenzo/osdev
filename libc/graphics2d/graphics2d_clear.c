#include <graphics2d.h>
#include <stddef.h>
#include <arch/i386/vga.h>

bool
	g2d_clear(t_g2d *g2d)
{
	size_t	len;

	if (g2d == NULL)
		return (false);
	len = g2d->width * g2d->height;
	if (g2d->chars)
		memset(g2d->chars, 0, sizeof(t_uchar) * len);
	if (g2d->colors)
		memset(g2d->colors, 0, sizeof(uint8_t) * len);
	return (true);
}
