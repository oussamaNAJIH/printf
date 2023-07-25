#include "main.h"

/**
 * _print_string - print a %s string
 * @args: The argument list
 * Return: The number of characters written
 */
int _print_string(va_list args)
{
int count = 0;
char *str = va_arg(args, char *);
if (str == NULL)
{
str = "(null)";
}
while (*str)
{
_putchar(*str);
str++;
count++;
}
return (count);
}
