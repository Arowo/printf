#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && *(format + 1) == 'b')
        {
            count += convert_binary(va_arg(args, unsigned int));
            format += 2; /* Skip %b */
        }
        else
        {
            count += write(1, format, 1);
            format++;
        }
    }

    va_end(args);
    return count;
}

/**
 * convert_binary - Convert unsigned int to binary and print
 * @num: Unsigned int to convert
 *
 * Return: Number of characters printed
 */
int convert_binary(unsigned int num)
{
    int count = 0;
    unsigned int mask = 1u << (sizeof(unsigned int) * 8 - 1);

    while (mask)
    {
        if (num & mask)
            count += write(1, "1", 1);
        else
            count += write(1, "0", 1);

        mask >>= 1;
    }

    return count;
}
