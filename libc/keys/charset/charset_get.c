#include <keys.h>

char
	charset_get(int code)
{
	if (g_selected_charset == NULL || code < 0 || code >= 256)
		return ('?');
	return g_selected_charset->characters[code];
}
