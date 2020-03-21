#include <driver/keyboard.h>
#include <stddef.h>

bool	(*g_keyboard_callback)(t_uchar) = NULL;

bool
	keyboard_callback_set(bool (*callback)(t_uchar))
{
	if (callback == NULL)
		return (false);
	g_keyboard_callback = callback;
	return (true);
}

bool
	keyboard_callback_fire(t_uchar code)
{
	if (g_keyboard_callback == NULL)
		return (false);
	return (g_keyboard_callback(code));
}
