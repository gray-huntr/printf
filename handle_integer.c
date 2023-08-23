#include <stdio.h>
#include <stdarg.h>
#include "main.h"


/**
 * handle_integer - handles %d or %i directives
 * @args: contains int to be processed
 * @flags: contains flags passed with %d or %i
 */
void handle_integer(va_list args, Flags flags)
{

        int num = length_flag_checker(args, flags);
        int num_width = calculate_field_width(num);

        handle_width_flag(num_width, flags, num, print_integer);
}

/**
 * print_integer - processes and prints the int
 * @num: the integer to be printed
 * @flags: flags passed with %d
 */

void print_integer(unsigned int num, Flags flags)
{
        handle_space_or_plus_flag(flags);

        if (num == 0)
        {
                _putchar('0');
                return;
        }
        print_num_recursive(num);
}

/**
 * print_num_recursive - print the int recursively
 * @num: the int to be printed
 */
void print_num_recursive(int num)
{
        if (num < 0)
        {
                _putchar('-');
                num = -num;
        }
        if (num == 0)
                return;

        print_num_recursive(num / 10);
        _putchar((num % 10) + '0');
}
