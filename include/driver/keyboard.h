#ifndef _DRIVER_KEYBOARD_H
# define _DRIVER_KEYBOARD_H

# include <sys/types.h>
# include <stdbool.h>

bool	(*g_keyboard_callback)(t_uchar);

void	keyboard_interrupt(void);

bool	keyboard_callback_set(bool (*callback)(t_uchar));
bool	keyboard_callback_fire(t_uchar code);

#endif
