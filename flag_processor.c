#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/**
* get_precision - retuns the precision flags
*@format: argument
*@i: current index
*Return: precision flag
*/
int get_precision(const char *format, int *i)
{
        int precision = -1;

        if (format[*i] == '.')
        {
                (*i)++;
                precision = 0;
                while (isdigit(format[*i]))
                {
                        precision = (precision * 10) + (format[*i] - '0');
                        (*i)++;
                }
        }
        return (precision);
}
/**
* get_zero_flag - retuns the zero flags
*@format: argument
*@i: current index
*Return: zero flag
*/
int get_zero_flag(const char *format, int *i)
{
        int zero_flag = 0;

        if (format[*i] == '0')
        {
                zero_flag = 1;
                (*i)++;
        }
        return (zero_flag);
}

/**
* get_field_width - retuns field width
*@format: argument
*@i: current index
*Return: width flag
*/
int get_field_width(const char *format, int *i)
{
        int field_width = 0;

        while (isdigit(format[*i]))
        {
                field_width = (field_width * 10) + (format[*i] - '0');
                (*i)++;
        }
        return (field_width);
}

/**
* process_flags - retuns a flag struct
*@format: argument
*@i: current index
*Return: flag struct
*/
Flags process_flags(const char *format, int *i)
{
        Flags flags = {0};
        unsigned long int j;

        FlagMap flag_map[] = {
                {'+', set_plus_flag},
                {' ', set_space_flag},
                {'#', set_hash_flag},
                {'-', set_minus_flag},
        };
        while (format[*i] == '+' || format[*i] == ' ' || format[*i] == '#' ||
                        format[*i] == 'h' || format[*i] == 'l' || format[*i] == '-')
        {
                for (j = 0; j < sizeof(flag_map) / sizeof(flag_map[0]); j++)
                {
                        if (format[*i] == flag_map[j].flag_char)
                        {
                                flag_map[j].flag_pointer(&flags);
                                break;
                        }
                }
                (*i)++;
        }
        flags.precision = get_precision(format, i);
        flags.zero_flag = get_zero_flag(format, i);
        flags.field_width = get_field_width(format, i);
        return (flags);
}
