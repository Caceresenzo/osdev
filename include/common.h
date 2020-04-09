#ifndef _COMMON_H
# define _COMMON_H

# ifndef NULL
#  define NULL ((void *)0)
# endif

typedef unsigned long uint64;
typedef long int64;
typedef unsigned int uint32;
typedef int int32;
typedef unsigned short uint16;
typedef short int16;
typedef unsigned char uint8;
typedef char int8;

typedef uint64 size_t;
typedef int64 ssize_t;

typedef enum {
	false = 0,
	true = 1
} bool;

uint8	inb(uint16 port);
uint16	inw(uint16 port);

void	outb(uint16 port, uint8 value);
void	outw(uint16 port, uint16 value);

#endif
