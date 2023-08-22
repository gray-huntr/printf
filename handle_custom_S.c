#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * handle_custom_S - custome %S converter
 * @args: contains string to be processed
 * @flags: contains flags passsed with %s
 */

void handle_custom_S(va_list args, Flags flags  __attribute__((unused)))
{
        const char *str = va_arg(args, const char *);
        char hex_digits[] = "0123456789ABCDEF";

        while (*str != '\0')
        {
                unsigned char c = *str;

                if (c < 32 || c >= 127)
                {
                        _putchar('\\');
                        _putchar('x');

                        _putchar(hex_digits[c >> 4]);
                        _putchar(hex_digits[c & 0xF]);
                }
                else
                        _putchar(c);
                str++;
        }
}
