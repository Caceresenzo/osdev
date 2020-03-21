#include <program/crate.h>
#include <sys/types.h>
#include <stdbool.h>
#include <keys.h>
#include <arch/i386/vga.h>
#include <stddef.h>
#include <stdint.h>

static int	cursor_x = 0;
static int	cursor_y = 2;

static void
	ensure_bounds(void)
{
	if (cursor_x < 0)
	{
		cursor_x = 79;
		cursor_y--;
	}
	if (cursor_x >= 80)
	{
		cursor_x = 0;
		cursor_y++;
	}
	if (cursor_y < 0)
	{
//		terminal_scroll(0);
		cursor_y = 0;
	}
	if (cursor_y >= 25)
	{
//		terminal_scroll(1);
		cursor_y = 24;
	}
}

bool
	crate_keyboard_callback(t_screen *screen, t_uchar code)
{
	g2d_set_pen_color(screen->graphics, VGA_COLOR_WHITE, VGA_COLOR_BLACK);
	if (code == KEY_ARROW_UP)
		cursor_y--;
	else if (code == KEY_ARROW_DOWN)
		cursor_y++;
	else if (code == KEY_ARROW_RIGHT)
		cursor_x++;
	else if (code == KEY_ARROW_LEFT)
		cursor_x--;
	else if (code == KEY_BACKSPACE)
	{
		cursor_x--;
		g2d_draw_str(screen->graphics, cursor_x, cursor_y, " ");
//		terminal_putcharat(' ', cursor_x, cursor_y);
	}
	else if (code == KEY_ENTER)
	{
		cursor_x = 0;
		cursor_y++;
	}
	else {
		g2d_draw_char(screen->graphics, cursor_x, cursor_y, charset_get(code));
//		terminal_putcharat(charset_get(code), cursor_x, cursor_y);
		cursor_x++;
	}
	ensure_bounds();
	return (true);
}
