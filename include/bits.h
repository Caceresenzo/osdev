#ifndef LIBC_BITS_H_
# define LIBC_BITS_H_

# include <common.h>

void	bitset_set8(uint8 *set, uint8 index);
void	bitset_clear8(uint8 *set, uint8 index);
bool	bitset_test8(uint8 set, uint8 index);

void	bitset_set16(uint16 *set, uint8 index);
void	bitset_clear16(uint16 *set, uint8 index);
bool	bitset_test16(uint16 set, uint8 index);

void	bitset_set32(uint32 *set, uint8 index);
void	bitset_clear32(uint32 *set, uint8 index);
bool	bitset_test32(uint32 set, uint8 index);

void	bitset_set64(uint64 *set, uint8 index);
void	bitset_clear64(uint64 *set, uint8 index);
bool	bitset_test64(uint64 set, uint8 index);

#endif
