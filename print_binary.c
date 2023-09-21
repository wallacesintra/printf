#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _printf2(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) == 'b')
		{
			unsigned int value = va_arg(args, unsigned int);
			int num_bits = sizeof(value) * 8;

		int i = num_bits - 1;

		while (i >= 0)
	{
		char bit = (value & (1u << i)) ? '1' : '0';

		write(1, &bit, 1);
		i--;
	}
	    format += 2;
		}
		else
		{
			write(1, format, 1);
			format++;
		}
	}

	va_end(args);
	return (0);
}

