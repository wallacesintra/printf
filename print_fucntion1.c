#include <stdio.h>
#include <stdarg.h>

int _printf333(const char *format, ...)
{
    int char_count = 0;
    
    va_list args;
    va_start(args, format);
	

    while (*format != '\0')
    {
        if (*format == '%' && *(format + 1) != '\0')
        {
            format++;

            if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                char_count += printf("%d", num);
            }
            else
            {
                putchar('%');
                char_count++;
            }
        }
        else
        {
            putchar(*format);
            char_count++;
        }

        format++;
    }

    va_end(args);
    return char_count;
}


