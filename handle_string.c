#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_string - handles %s from _printf
 * @args: contains string to be printed
 * @flags: directive flags passed with %s
 */

void handle_string(va_list args, Flags flags  __attribute__((unused)))
{
        const char *str = va_arg(args, const char *);

        while (*str != '\0')
        {
                _putchar(*str);
                str++;
        }
}
