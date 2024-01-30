#include "main.h"
#include <stddef.h>

/**
 * _strlen - Calculate the length of a string.
 * @s: The input string.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
    {
        len++;
    }
    return len;
}
