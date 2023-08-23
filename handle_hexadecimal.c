#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * handle_hexadecimal - handles %x or %X
 * @args: contains num to be processed
 * @flags: contains flags passed with %x
 */

void handle_hexadecimal(va_list args, Flags flags)
{
        unsigned int num = length_flag_checker(args, flags);
        int num_width = calculate_field_width(num);

        handle_width_flag(num_width, flags, num, print_hexadecimal);
}

/**
 * print_hexadecimal - prints %x output
 * @num: the number to be printed
 * @flags: the flags passed with %x
 */
void print_hexadecimal(unsigned int num, Flags flags)
{
        char buffer[32];
        int i = 0, j;

        handle_space_or_plus_flag(flags);
        if (num == 0)
        {
                _putchar('0');
                return;
        }
        while (num != 0)
        {
                int rem = num % 16;

                if (rem < 10)
                {
                        buffer[i++] = '0' + rem;
                }
                else
                {
                        buffer[i++] = 'a' + (rem - 10);
                }
                num /= 16;
        }

        for (j = i - 1; j >= 0; j--)
        {
                _putchar(buffer[j]);
        }
}
