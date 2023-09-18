#include "main.h"
/**
 *_printf- function that produces output according to a format
 *@format: character string
 *Return:  number of characters printed
 */
int _printf(const char *format, ...)
{
	int char_count = 0;
	va_list string_list;

	if (format == NULL)
		return (-1);

	va_start(string_list, format);
	while (*format)
	{
		if (*format != '%')
			write(1, &format, 1);
			char_count = char_count + 1;
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				char_count = char_count + 1;
			}
			else if (*format == 'c')
			{
				char c = va_arg(string_list, int);

				write(1, &c, 1);
				char_count = char_count + 1;
			}
			else if (*format == 's')
			{
				char str[] = va_arg(string_list, char[]);
				int length_string = 0;
			while (str[length_string])
			}
			length_string = length_string + 1;
		}
		write(1, &str, length_string);
		char_count = char_count + length_string;
		}
	}
	format++;

	va_end(string_list);
	return (char_count);
}
