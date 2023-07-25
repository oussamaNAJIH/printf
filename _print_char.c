#include "main.h"

/**
 * _print_char - print a char
 * @args: The argument list
 * Return: The number of characters written
 */
int _print_char(va_list args)
{
char ch = va_arg(args, int);
_putchar(ch);
return (1);
}
