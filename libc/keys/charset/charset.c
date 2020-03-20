#include <keys.h>
#include <stddef.h>

t_charset g_charsets[] = {
	{
		.name = "US-ASCII",
		.characters = {
			0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
			'\b', '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[',
			']', '\n', 0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'',
			'`', 0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,
			'*', 0, ' ', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '-', 0,
			0, 0, '+', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, '!', '@', '#',
			'$', '%', '^', '&', '*', '(', ')', '_', '+', '\b', '\t', 'Q', 'W',
			'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n', 0, 'A', 'S',
			'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '\"', '~', 0, '|', 'Z', 'X',
			'C', 'V', 'B', 'N', 'M', '<', '>', '?', 0, '*', 0, ' ', 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '-', 0, 0, 0, '+', 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0
		}
	}
};

t_charset *g_selected_charset = NULL;
