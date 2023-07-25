#include <stdio.h>
#include "main.h"

/**
 * printf -  function that produces output according to a format.
 * @format: is a character string
 *
 * Return: the number of characters printed
 */

#include "holberton.h"

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int num_printed_chars = 0;

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c': putchar(va_arg(args, int)); num_printed_chars++; break;
                case 's': for (char *str = va_arg(args, char *); *str; str++) { putchar(*str); num_printed_chars++; } break;
                case '%': putchar('%'); num_printed_chars++; break;
                default: putchar(*format); num_printed_chars++; break;
            }
        }
        else { putchar(*format); num_printed_chars++; }
        format++;
    }

    va_end(args);
    return (num_printed_chars);
}

