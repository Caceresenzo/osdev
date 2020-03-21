#include <arch/i386/vga.h>
#include <driver/keyboard.h>
#include <graphics2d.h>
#include <keys.h>
#include <program/desktop.h>
#include <program/edit.h>
#include <program/jumper.h>
#include <stddef.h>
#include <stdint.h>

t_program	g_programs[2] = {
	{
		.name = "Edit",
		.description = "A small text box",
		.start = NULL,
		.loop = NULL,
		.kb_callback = &edit_keyboard_callback
	},
	{
		.name = "Jumper",
		.description = "A very small jumper!",
		.start = NULL,
		.loop = &jumper_loop,
		.kb_callback = NULL
	},
};

static size_t	current = 0;
static t_screen	*main_screen = NULL;
static t_screen	*program_screen = NULL;

static bool		has_changed = false;

static void
	loop()
{
	current = 0;
	while (1)
	{
		has_changed = false;
		if (g_programs[current].loop)
			(*(g_programs[current].loop))(program_screen);
		screen_apply(main_screen);
		screen_apply(program_screen);
		if (has_changed)
			g2d_clear(program_screen->graphics);
	}
}

static void
	change_program()
{
	current++;
	if (current >= sizeof(g_programs) / sizeof(t_program))
		current = 0;
	g2d_set_pen_color(main_screen->graphics, VGA_COLOR_WHITE, VGA_COLOR_RED);
	g2d_set_pen_char(main_screen->graphics, ' ');
	g2d_fill(main_screen->graphics);
	g2d_draw_str(main_screen->graphics, 3, 1, g_programs[current].name);
	g2d_set_pen_color(main_screen->graphics, VGA_COLOR_LIGHT_GREY, VGA_COLOR_RED);
	g2d_draw_str(main_screen->graphics, 3, 2, g_programs[current].description);
	g2d_set_pen_color(program_screen->graphics, VGA_COLOR_BLACK, VGA_COLOR_BLACK);
	g2d_fill(program_screen->graphics);
	g2d_set_pen_color(main_screen->graphics, VGA_COLOR_WHITE, VGA_COLOR_RED);
	g2d_draw_str(main_screen->graphics, 80 - 10, 1, "last:");
	for (int x = 0; x < 15; ++x) {
		g2d_set_pen_color(main_screen->graphics, x, x);
		g2d_set_at(main_screen->graphics, 80 - 4 - x, 2);
	}
	has_changed = true;
}

static t_uchar	g_chars_main[4 * 80] = { 0 };
static uint8_t	g_colors_main[4 * 80] = { 0 };
static t_uchar	g_chars_program[20 * 80] = { 0 };
static uint8_t	g_colors_program[20 * 80] = { 0 };

void
	desktop_start(void)
{
	t_screen	screen[2];
	t_g2d		g2d[2];

	screen_init(&screen[0], 0, 0, &g2d[0]);
	g2d_set_dim(&g2d[0], 80, 4);
	g2d_set_buffers(&g2d[0], g_chars_main, g_colors_main);
	screen_init(&screen[1], 0, 4, &g2d[1]);
	g2d_set_dim(&g2d[1], 80, 20);
	g2d_set_buffers(&g2d[1], g_chars_program, g_colors_program);
	main_screen = &screen[0];
	program_screen = &screen[1];
	keyboard_callback_set(&desktop_keyboard_callback);
	while (current < sizeof(g_programs) / sizeof(t_program))
	{
		if (g_programs[current].start)
			(*(g_programs[current].start))();
		current++;
	}
	change_program();
	loop();
}

bool
	desktop_keyboard_callback(t_uchar code)
{
	size_t	index;

	g2d_set_pen_color(main_screen->graphics, VGA_COLOR_WHITE, VGA_COLOR_RED);
	g2d_draw_char(main_screen->graphics, 80 - 4, 1, charset_get(code));
	if (code == KEY_LEFT_CONTROL)
		change_program();
	else
	{
		index = 0;
		while (index < sizeof(g_programs) / sizeof(t_program))
		{
			if (g_programs[index].kb_callback)
				(*(g_programs[index].kb_callback))(program_screen, code);
			index++;
		}
	}
	return (true);
}
