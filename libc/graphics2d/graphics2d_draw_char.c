#include <graphics2d.h>
#include <stddef.h>

bool
	g2d_draw_char(t_g2d *g2d, size_t x, size_t y, char chr)
{
	char	str[2];

	str[0] = chr;
	str[1] = '\0';
	return (g2d_draw_str(g2d, x, y, str));
}
