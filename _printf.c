#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>

/**
* _printf - custom printf implementations
* @format: the specified format
* Return: number of chars printed
*/

int _printf(const char *format, ...)
{
        FormatHandler format_handlers[] = {
                {'d', handle_integer}, {'i', handle_integer},
                {'u', handle_unsigned_integer}, {'c', handle_char},
                {'s', handle_string}, {'o', handle_octal},
                {'x', handle_hexadecimal}, {'X', handle_hexadecimal},
                {'p', handle_pointer}, {'b', handle_binary},
                {'r', handle_reverse}, {'R', handle_rot13},
                {'S', handle_custom_S}
        };
        int i, len = 0, handler_index;
        Flags flags;
        va_list args;

        if (format == NULL || (format[0] == '%' && format[1] == '\0'))
                return (-1);
        va_start(args, format);
        for (i = 0; format[i] != '\0'; i++)
        {
                if (format[i] == '%')
                {
                        i++;
                        flags = process_flags(format, &i);
                        handler_index = find_format_handler(format[i],
                                        format_handlers, sizeof(format_handlers) / sizeof(format_handlers[0]));
                        if (handler_index != -1)
                                format_handlers[handler_index].handler(args, flags);
                        else
                                _putchar(format[i]);
                }
                else
                        _putchar(format[i]);
                len++;
        }
        va_end(args);
        return (len);
}
/**
 * find_format_handler - find the index of the format handler in the array
 * @specifier: the format specifier character
 * @format_handlers: the array of format handlers
 * @num_handlers: number of elements in the array
 * Return: the index of the format handler, or -1 if not found
 */
int find_format_handler(const char specifier,
                FormatHandler format_handlers[], int num_handlers)
{
        int i;

        for (i = 0; i < num_handlers; i++)
        {
                if (specifier == format_handlers[i].specifier)
                        return (i);
        }
        return (-1);
}
