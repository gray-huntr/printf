#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_unsigned_integer - handles %u from _printf
 * @args: contains the unsigned int be processed
 * @flags: contains the directive flags for the ui
 */
void handle_unsigned_integer(va_list args, Flags flags)
{
        int num = length_flag_checker(args, flags);
        int num_width = calculate_field_width(num);

        handle_width_flag(num_width, flags, num, print_unsigned_integer);
}
/**
 * print_unsigned_integer - handles the printing of an ui
 * @num: number to be printed
 * @flags: the directive flags to be used
 */
void print_unsigned_integer(unsigned int num, Flags flags)
{
        int digits = 0, i;
        unsigned int temp = num, divisor;

        handle_space_or_plus_flag(flags);

        while (temp > 0)
        {
                temp /= 10;
                digits++;
        }

        divisor = 1;

        for (i = 1; i < digits; i++)
        {
                divisor *= 10;
        }
        while (divisor > 0)
        {
                unsigned int digit = num / divisor;

                putchar(digit + '0');
                num %= divisor;
                divisor /= 10;
        }
}
