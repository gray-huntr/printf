#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * length_flag_checker - Check and process field length
 * based on 'l' and 'h'.
 *
 * @args: carries the variable to be processed.
 * @flags: carries the 'l' and 'h' flags
 *
 * Return: processed int length
 */
int length_flag_checker(va_list args, Flags flags)
{
        int num;

        if (flags.length_modifier == 2)
        {
                num = va_arg(args, long int);
        }
        else if (flags.length_modifier == 1)
        {
                num = va_arg(args, int);
        }
        else
        {
                num = va_arg(args, int);
        }
        return (num);
}
/**
 * calculate_field_width - calculate the sapces required
 * if a field width modifier is used
 *
 * @num: the number to be processed
 * Return: processed number
 */
int calculate_field_width(int num)
{
        int width = (num == 0) ? 1 : 0;

        while (num != 0)
        {
                width++;
                num /= 10;
        }
        return (width);
}

/**
 * handle_width_flag - generated padding based on field width
 * then prints the output
 * @num_width: used to calculate the padding
 * @flags: carries conversion flags to be used
 * @num: passed to the print function for printing
 * @specific_print_function: points to the print function that will be called
 */
void handle_width_flag(int num_width, Flags flags,
                unsigned int num, void (*specific_print_function)(unsigned int, Flags))
{
        int num_spaces = flags.field_width - num_width;

        if (flags.plus_flag || flags.space_flag)
                num_spaces--;

        if (flags.minus_flag)
        {
                specific_print_function(num, flags);
                while (num_spaces > 0)
                {
                        _putchar(' ');
                        num_spaces--;
                }
        }
        else
        {
                while (num_spaces > 0)
                {
                        if (flags.zero_flag)
                                _putchar('0');
                        else
                                _putchar(' ');
                        num_spaces--;
                }
                specific_print_function(num, flags);
        }
}
/**
 * handle_space_or_plus_flag - adds a + or space
 * if their flags are true
 *
 * @flags: carries the state of the + and space flags
 */

void handle_space_or_plus_flag(Flags flags)
{
        if (flags.plus_flag)
                _putchar('+');
        else if (flags.space_flag)
                _putchar(' ');
}
