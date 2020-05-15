#include <arch/i386/vga.h>
#include <driver/keyboard.h>
#include <keys.h>
#include <program/shell.h>
#include <stdio.h>
#include <string.h>

char		g_sh_buffer[32] = { 0 };
size_t		g_sh_buffer_len = 0;

t_command	g_commands[6] = {
	{
		.name = "about",
		.usage = "about",
		.description = "A little About message.",
		.handler = &cmd_about_handler
	},
	{
		.name = "clear",
		.usage = "clear",
		.description = "Clear the screen.",
		.handler = &cmd_clear_handler
	},
	{
		.name = "echo",
		.usage = "echo <msg>",
		.description = "Echo a message.",
		.handler = &cmd_echo_handler
	},
	{
		.name = "desktop",
		.usage = "desktop",
		.description = "Start the desktop.",
		.handler = &cmd_desktop_handler
	},
	{
		.name = "help",
		.usage = "help",
		.description = "Display the list of commands.",
		.handler = &cmd_help_handler
	},
	{
		.name = "sizeof",
		.usage = "sizeof",
		.description = "Display a list of types with their sizes in bytes.",
		.handler = &cmd_sizeof_handler
	},
};

static bool	g_validate = false;

static void
	prepare_buffer()
{
	size_t		index;

	g_sh_buffer[g_sh_buffer_len] = '\0';
	index = 0;
	while (g_sh_buffer[index])
	{
		if (g_sh_buffer[index] == ' ')
		{
			g_sh_buffer[index] = '\0';
			g_sh_buffer_len = index;
			break ;
		}
		index++;
	}
}

static void
	evaluate()
{
	bool		found;
	size_t		index;
	t_command	cmd;

	if (g_sh_buffer_len == 0)
		return ;
	prepare_buffer();
	index = 0;
	found = false;
	while (index < (sizeof(g_commands) / sizeof(t_command)))
	{
		cmd = g_commands[index];
		if (memcmp(g_sh_buffer, cmd.name, g_sh_buffer_len) == 0
			&& strlen(cmd.name) == g_sh_buffer_len)
		{
			found = true;
			(*(cmd.handler))(g_sh_buffer, g_sh_buffer + g_sh_buffer_len + 1);
			break ;
		}
		index++;
	}
	if (!found)
		printk("Command not found: %s\n", g_sh_buffer);
	g_sh_buffer_len = 0;
}

void
	shell_start(void)
{
	keyboard_callback_set(&shell_keyboard_callback);
	printk("$> ");
	while (1)
	{
		printk("");
		if (!g_validate)
			continue ;
		g_validate = false;
		evaluate();
		printk("$> ");
	}
}

int qsd = 0;

bool
	shell_keyboard_callback(uint8 code)
{
	if (code == KEY_ENTER)
	{
		int x = 0 / qsd;
		g_validate = !x;
		printk("\n");
	}
	else if (code == KEY_BACKSPACE)
	{
		if (g_sh_buffer_len != 0)
		{
			vga_backspace();
			g_sh_buffer_len--;
		}
	}
	else
	{
		if (g_sh_buffer_len < (sizeof(g_sh_buffer) / sizeof(char)) - 1)
		{
			g_sh_buffer[g_sh_buffer_len++] = charset_get(code);
			printk("%c", charset_get(code));
		}
	}
	return (true);
}
