#include <keys.h>
#include <stddef.h>

bool
	charset_use(t_charset *charset)
{
	if (charset == NULL || charset->name == NULL)
		return (false);
	g_selected_charset = charset;
	return (true);
}
