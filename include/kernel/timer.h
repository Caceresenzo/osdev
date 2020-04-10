#ifndef KERNEL_TIMER_H_
# define KERNEL_TIMER_H_

# include <common.h>

# define BASE_CLOCK_HZ 1193180

int32	timer_ticks;

void	timer_initizalier(uint32 frequency);
void	timer_interrupt_callback(registers_t *regs);

#endif
