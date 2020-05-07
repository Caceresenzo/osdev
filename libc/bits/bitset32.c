#include <common.h>

void
	bitset_set32(uint32 *set, uint8 index)
{
	if (index >= 32)
		return ;
	*set |= (((uint32) 1) << index);
}

void
	bitset_clear32(uint32 *set, uint8 index)
{
	if (index >= 32)
		return ;
	*set &= ~(((uint32) 1) << index);
}

bool
	bitset_test32(uint32 set, uint8 index)
{
	if (index >= 32)
		return (false);
	return ((set & (((uint32) 1) << index)) >> index);
}
