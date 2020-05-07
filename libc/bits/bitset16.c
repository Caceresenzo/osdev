#include <common.h>

void
	bitset_set16(uint16 *set, uint8 index)
{
	if (index >= 16)
		return ;
	*set |= (((uint16) 1) << index);
}

void
	bitset_clear16(uint16 *set, uint8 index)
{
	if (index >= 16)
		return ;
	*set &= ~(((uint16) 1) << index);
}

bool
	bitset_test16(uint16 set, uint8 index)
{
	if (index >= 16)
		return (false);
	return ((set & (((uint16) 1) << index)) >> index);
}
