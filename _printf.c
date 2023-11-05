#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - prints formatted data to standard output
 *
 * @format: format string
 * @...: variable arguments based on format specifiers
 *
 * Return: value of char_count (numbers of characters
 * printed)
 */

int _printf(const char *format, ...)
{
	int char_count = 0;
	va_list args;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			char_count++;
		}
		else if (*(format + 1) == '\0')
		{
			format++;
			handle_format(&char_count, &format, args);

		}

		format++;
	}

	va_end(args);
	return (char_count);
}
