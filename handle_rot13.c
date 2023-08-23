#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * handle_rot13 - handles %R from _printf
 * Description: custom conversion for rot13
 * @args: contains string to be processed
 * @flags: flags passed with %R conversion
 */
void handle_rot13(va_list args, Flags flags  __attribute__((unused)))
{
        const char *str = va_arg(args, const char *);

        while (*str != '\0')
        {
                char c = *str;

                if ('a' <= c && c <= 'z')
                {
                        c = 'a' + (c - 'a' + 13) % 26;
                }
                else if ('A' <= c && c <= 'Z')
                {
                        c = 'A' + (c - 'A' + 13) % 26;
                }
                _putchar(c);
                str++;
        }
}
