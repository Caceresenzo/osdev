#include <common.h>

void
	bitset_set8(uint8 *set, uint8 index)
{
	if (index >= 8)
		return ;
	*set |= (((uint8) 1) << index);
}

void
	bitset_clear8(uint8 *set, uint8 index)
{
	if (index >= 8)
		return ;
	*set &= ~(((uint8) 1) << index);
}

bool
	bitset_test8(uint8 set, uint8 index)
{
	if (index >= 8)
		return (false);
	return ((set & (((uint8) 1) << index)) >> index);
}
