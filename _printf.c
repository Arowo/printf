#include "main.h"
#include <stdarg.h>
#include <unistd.h>

size_t _strlen(const char *s);

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++; /* Move past '%'*/
            switch (*format)
            {
            case 'c':
                {
                    char temp = (char)va_arg(args, int);
                    count += write(1, &temp, 1);
                }
                break;
            case 's':
                {
                    char *str = va_arg(args, char *);
                    count += write(1, str, _strlen(str));
                }
                break;
            case '%':
                count += write(1, "%", 1);
                break;
            default:
                count += write(1, "%", 1); /* Treat unsupported format specifier as '%'*/
                break;
            }
        }
        else
        {
            count += write(1, format, 1);
        }

        format++;
    }

    va_end(args);

    return count;
}

