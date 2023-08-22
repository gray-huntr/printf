#ifndef PRINTF
#define PRINTF

#include <stdarg.h>
/**
 * struct Flags - Represents the flags and modifiers for the
 * format specifier in _printf.
 *
 * @plus_flag: Indicates if the '+' flag is present.
 * @space_flag: Indicates if the ' ' (space) flag is present.
 * @hash_flag: Indicates if the '#' (hash) flag is present.
 * @zero_flag: Indicates if the '0' (zero) flag is present.
 * @length_modifier: The length modifier:
 * 0 for default, 1 for 'h', 2 for 'l'.
 * @field_width: The field width specified in the format string.
 * @precision: The precision specified in the format string.
 * @minus_flag: Indicates if the '-' (minus) flag is present.
 * @X_flag: Indicates that %X has been used instead of %x
 */
typedef struct Flags
{
        int plus_flag;
        int space_flag;
        int hash_flag;
        int zero_flag;
        int length_modifier;
        int field_width;
        int precision;
        int minus_flag;
        int X_flag;
} Flags;
/**
 * struct FlagMap - Represents a mapping of format specifier flags
 * to their corresponding flags in the Flags struct.
 *
 * @flag_char: The character representing the format specifier flag.
 * @flag_pointer: A pointer to the corresponding flag in the Flags struct.
 */
typedef struct FlagMap
{
        char flag_char;
        void (*flag_pointer)(Flags *flags);
} FlagMap;
/**
 * struct ConversionPrinter - Represents a mapping of format specifiers
 * to their corresponding conversion handler functions.
 *
 * @specifier: The character representing the format specifier.
 * @conversion_type: A function pointer to the conversion handler
 * function for the specific format specifier.
 */
typedef struct ConversionPrinter
{
        char specifier;
        void (*conversion_type)(va_list args);
} ConversionPrinter;
/**
 * struct FormatHandler - Represents a mapping of format specifiers
 * to their corresponding handler functions.
 *
 * @specifier: The character representing the format specifier.
 * @handler: A function pointer to the handler function that processes
 * the specific format specifier.
 */
typedef struct FormatHandler
{
        char specifier;
        void (*handler)(va_list args, Flags flags);
} FormatHandler;

/*Integer handlers*/
void handle_integer(va_list args, Flags flags);
int length_flag_checker(va_list args, Flags flags);
void print_integer(unsigned int num, Flags flags);
void print_num_recursive(int num);

/*Usigned integer handlers*/
void handle_unsigned_integer(va_list args, Flags flags);
void print_unsigned_integer(unsigned int num, Flags flags);

/*Char handlers*/
void handle_char(va_list args, Flags flags);
void print_char(unsigned int c, Flags flags);

/*String handlers*/
void handle_string(va_list args, Flags flags);

/* Octal handlers*/
void handle_octal(va_list args, Flags flags);
void print_octal(unsigned int num, Flags flags);

/*Hexadecimal Handlers*/
void handle_hexadecimal(va_list args, Flags flags);
void print_hexadecimal(unsigned int num, Flags flags);

/* Pointer Handler*/
void handle_pointer(va_list args, Flags flags);

/*Binary Handler*/
void handle_binary(va_list args, Flags flags);

/*Reverse handler*/
void handle_reverse(va_list args, Flags flags);

/*Rot13 handler*/
void handle_rot13(va_list args, Flags flags);

/*Handle Custom s*/
void handle_custom_S(va_list args, Flags flags);

/*Helper function*/
int calculate_field_width(int num);
void handle_width_flag(int num_width, Flags flags,
                unsigned int num, void (*specific_print_function)(unsigned int, Flags));

/*Main functions*/
int _printf(const char *format, ...);
int get_precision(const char *format, int *i);
int get_zero_flag(const char *format, int *i);
int get_field_width(const char *format, int *i);
Flags process_flags(const char *format, int *i);
void set_plus_flag(Flags *flags);
void set_space_flag(Flags *flags);
void set_hash_flag(Flags *flags);
void set_minus_flag(Flags *flags);
int find_format_handler(const char specifier,
                FormatHandler format_handlers[], int num_handlers);
void handle_space_or_plus_flag(Flags flags);
int _putchar(char c);

#endif
