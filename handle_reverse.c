#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * handle_reverse - custom conversion that reverserses a string
 * %s
 * @args: contains string to be reversed
 * @flags: contains flags passed with the directive
 */
void handle_reverse(va_list args, Flags flags __attribute__((unused)))
{
        const char *str = va_arg(args, const char *);
        int len = 0, i;

        while (str[len] != '\0')
        {
                len++;
        }
        for (i = len - 1; i >= 0; i--)
                _putchar(str[i]);
}
