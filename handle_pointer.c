#include <stdio.h>
#include <stdint.h>
#include "main.h"

/**
 * handle_pointer - conversion for %p
 * @args: contains pointer to be processed
 * @flags: directive flags passed with %s
 */
void handle_pointer(va_list args, Flags flags __attribute__((unused)))
{
        int i, hex_digit;
        void *ptr = va_arg(args, void *);
        uintptr_t address = (uintptr_t)ptr;

        for (i = sizeof(address) * 2 - 1; i >= 0; i--)
        {
                hex_digit = (address >> (i * 4)) & 0xF;
                _putchar(hex_digit < 10 ? '0' + hex_digit : 'a' + (hex_digit - 10));
        }
}
