#include <driver/keyboard.h>

bool	(*g_keyboard_callback)(uint8) = NULL;

bool
	keyboard_callback_set(bool (*callback)(uint8))
{
	if (callback == NULL)
		return (false);
	g_keyboard_callback = callback;
	return (true);
}

bool
	keyboard_callback_fire(uint8 code)
{
	if (g_keyboard_callback == NULL)
		return (false);
	return (g_keyboard_callback(code));
}
