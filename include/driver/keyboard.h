#ifndef _DRIVER_KEYBOARD_H
# define _DRIVER_KEYBOARD_H

# include <common.h>
# include <kernel/interrupt.h>

bool	(*g_keyboard_callback)(uint8);

void	keyboard_initialize(void);

void	keyboard_interrupt(registers_t *regs);

bool	keyboard_callback_set(bool (*callback)(uint8));
bool	keyboard_callback_fire(uint8 code);

#endif
