#ifndef KERNEL_GDT_H_
# define KERNEL_GDT_H_

# include <common.h>

# define NULL_SEGMENT_ACCESS 0
# define CODE_SEGMENT_ACCESS 0x9A
# define DATA_SEGMENT_ACCESS 0x92
# define USERM_CODE_SEGMENT_ACCESS 0xFA
# define USERM_DATA_SEGMENT_ACCESS 0xF2

/*
** This structure contains the value of one GDT entry.
** We use the attribute 'packed' to tell GCC not to change
** any of the alignment in the structure.
**
** @param limit_low
** 			The lower 16 bits of the limit.
** @param base_low
** 			The lower 16 bits of the base.
** @param base_middle
** 			The next 8 bits of the base.
** @param access
** 			Access flags, determine what ring this segment can be used in.
** @param granularity
**			Format:
**			+--------------------------------+
**			| 7 | 6 | 5 | 4 | 3            0 |
**			| G | D | 0 | A | Segment length |
**			+--------------------------------+
**			 G: Granularity (0 = 1 byte, 1 = 1kbyte).
**			 D: Operand size (0 = 16bit, 1 = 32bit).
**			 0: Should always be zero.
**			 A: Available for system use (always zero).
** @param base_high
** 			The last 8 bits of the base.
** @note ORDER IS IMPORTANT !!
*/

typedef struct __attribute__((packed)) {
	uint16	limit_low;
	uint16	base_low;
	uint8	base_middle;
	uint8	access;
	uint8	granularity;
	uint8	base_high;
} gdt_entry_t;

/*
** @param limit
** 			The upper 16 bits of all selector limits.
** @param base
** 			The address of the first gdt_entry_t struct.
** @note ORDER IS IMPORTANT !!
*/

typedef struct __attribute__((packed))
{
   uint16	limit;
   uint32	base;
} gdt_ptr_t;

gdt_entry_t	gdt_entries[5];
gdt_ptr_t	gdt_ptr;

void		gdt_initialize();
void		gdt_set(int32 id, uint32 base, uint32 limit, uint8 access, uint8 gran);

extern void	gdt_flush(uint32 address);

#endif
