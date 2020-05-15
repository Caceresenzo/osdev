#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

static bool print(const char *data, size_t length) {
	const unsigned char *bytes = (const unsigned char*) data;
	for (size_t i = 0; i < length; i++)
		if (putchar(bytes[i]) == EOF)
			return false;
	return true;
}

static int
	print_number(long number, unsigned int base)
{
	bool	negative;
	int		ret;

	if (number == 0)
		return 0;
	if ((negative = number < 0)) {
		putchar('-');
		number = -number;
	}
	ret = 1 + negative + print_number(number / base, base);
	putchar("0123456789abcdefghjklmnopqrstuvwxyz"[number % base]);
	return (ret);
}

static int
	print_unumber(unsigned long number, unsigned int base)
{
	int		ret;

	if (number == 0)
		return 0;
	ret = 1 + print_unumber(number / base, base);
	putchar("0123456789abcdefghjklmnopqrstuvwxyz"[number % base]);
	return (ret);
}

int printk(const char *format, ...) {
	va_list parameters;
	va_start(parameters, format);

	int written = 0;

	while (*format != '\0') {
		size_t maxrem = INT_MAX - written;

		if (format[0] != '%' || format[1] == '%') {
			if (format[0] == '%')
				format++;
			size_t amount = 1;
			while (format[amount] && format[amount] != '%')
				amount++;
			if (maxrem < amount) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(format, amount))
				return -1;
			format += amount;
			written += amount;
			continue;
		}

		const char *format_begun_at = format++;

		if (*format == 'c') {
			format++;
			char c = (char) va_arg(parameters, int /* char promotes to int */);
			if (!maxrem) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(&c, sizeof(c)))
				return -1;
			written++;
		} else if (*format == 'd') {
			format++;
			long i = va_arg(parameters, long);
			if (!maxrem) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (i == 0)
			{
				print("0", 1);
				written++;
			}
			else
				written += print_number(i, 10);
		} else if (*format == 'u') {
			format++;
			unsigned long i = va_arg(parameters, unsigned long);
			if (!maxrem) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (i == 0)
			{
				print("0", 1);
				written++;
			}
			else
				written += print_unumber(i, 10);
		} else if (*format == 'b') {
			format++;
			unsigned long i = va_arg(parameters, unsigned long);
			if (!maxrem) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (i == 0)
			{
				print("0", 1);
				written++;
			}
			else
				written += print_number(i, 2);
		} else if (*format == 'x') {
			format++;
			int i = va_arg(parameters, int);
			if (!maxrem) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (i == 0)
			{
				print("0", 1);
				written++;
			}
			else
				written += print_number(i, 16);
		} else if (*format == 'p') {
			format++;
			unsigned long i = va_arg(parameters, unsigned long);
			if (!maxrem) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			print("0x", 2);
			if (i == 0)
			{
				print("0", 1);
				written++;
			}
			else
				written += print_unumber(i, 16);
		} else if (*format == 's') {
			format++;
			const char *str = va_arg(parameters, const char*);
			if (str == NULL)
				str = "(null)";
			size_t len = strlen(str);
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(str, len))
				return -1;
			written += len;
		} else {
			format = format_begun_at;
			size_t len = strlen(format);
			if (maxrem < len) {
				// TODO: Set errno to EOVERFLOW.
				return -1;
			}
			if (!print(format, len))
				return -1;
			written += len;
			format += len;
		}
	}

	va_end(parameters);
	return written;
}
