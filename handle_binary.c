#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * handle_binary - Handles custom converter %b
 * @args: contains int to be processed to binary
 * @flags: contains flags passed to %b
 */

void handle_binary(va_list args, Flags flags  __attribute__((unused)))
{
        unsigned int num = va_arg(args, unsigned int);
        char buffer[32];
        int i = 0, j;

        if (num == 0)
        {
                _putchar('0');
                return;
        }
        while (num != 0)
        {
                buffer[i++] = '0' + (num & 1);
                num >>= 1;
        }

        for (j = i - 1; j >= 0; j--)
                _putchar(buffer[j]);
}
