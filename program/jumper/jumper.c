#include <program/jumper.h>
#include <sys/types.h>
#include <stdbool.h>
#include <keys.h>
#include <stdint.h>
#include <arch/i386/vga.h>
#include <stddef.h>
#include <stdint.h>
#include <graphics2d.h>
#include <driver/screen.h>
#include <string.h>

static float	g_player_x = 40.0f / 2;
static float	g_player_y = 18.0f;

static void
	redraw(t_g2d *g2d)
{
	g2d_set_pen_char(g2d, ' ');
	g2d_set_pen_color(g2d, 0, VGA_COLOR_LIGHT_BLUE);
	g2d_set_at(g2d, g_player_x, g_player_y);
	g2d_set_pen_color(g2d, 0, VGA_COLOR_LIGHT_GREEN);
	g2d_draw_line_vert(g2d, 0, g2d->width - 1, g2d->height - 1);
}

static void move(float to_x, float to_y)
{
	g_player_x += to_x;
	g_player_y += to_y;
}

static void logic()
{
	if (key_state_get(KEY_Z))
		move(0, -0.3);
	if (key_state_get(KEY_S))
		move(0, 0.3);
	if (key_state_get(KEY_D))
		move(0.3, 0);
	if (key_state_get(KEY_Q))
		move(-0.3, 0);
	g_player_y += 0.1;
	if (g_player_y > 18)
		g_player_y = 18;
}

void
	jumper_loop(t_screen *screen)
{
	for (int time = 0; time < 1000000; ++time) { printf(""); }
	logic();
	g2d_clear(screen->graphics);
	redraw(screen->graphics);
}
