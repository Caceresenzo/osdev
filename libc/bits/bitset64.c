#include <common.h>

void
	bitset_set64(uint64 *set, uint8 index)
{
	if (index >= 64)
		return ;
	*set |= (((uint64) 1) << index);
}

void
	bitset_clear64(uint64 *set, uint8 index)
{
	if (index >= 64)
		return ;
	*set &= ~(((uint64) 1) << index);
}

bool
	bitset_test64(uint64 set, uint8 index)
{
	if (index >= 64)
		return (false);
	return ((set & (((uint64) 1) << index)) >> index);
}
