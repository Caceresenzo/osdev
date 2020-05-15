#ifndef KERNEL_MEMORY_H_
# define KERNEL_MEMORY_H_

# include <common.h>

uint32		TOTAL_MEMORY;
uint64		FIRST_MEMORY_MAP;

uint32		memory_compute_available(void);
void		memory_dump_maps(void);

#endif
