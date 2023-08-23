#include <stdarg.h>
#include <stdio.h>
#include "main.h"


/**
 * handle_octal - handles the  %o specifier
 * @args: contains the unsigned in to be processed
 * @flags: contains the flags passed with %o
 */

void handle_octal(va_list args, Flags flags)
{
        int num = length_flag_checker(args, flags);
        int num_width = calculate_field_width(num);

        handle_width_flag(num_width, flags, num, print_octal);
}

/**
 * print_octal -converts and prints the into octal base
 * @num: number to printed
 * @flags: the flasgs passed with %o
 */

void print_octal(unsigned int num, Flags flags)
{
        char buffer[32];
        int i = 0, j;

        handle_space_or_plus_flag(flags);
        while (num != 0)
        {
                buffer[i++] = '0' + (num % 8);
                num /= 8;
        }


        for (j = i - 1; j >= 0; j--)
        {
                _putchar(buffer[j]);
        }
}
