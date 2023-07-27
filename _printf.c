#include <unistd.h>
#include <stdarg.h>
#include "main.h"


/**
 * _printf - custom printf function in a single file
 * @format: The format string containing conversion specifiers
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);
if (!format || !format[0] || !format[1])
	return (-1);
while (*format)
{
if (*format != '%')
	count += _putchar(*format);
else
{
format++;
switch (*format)
{
case 'c':
count += _print_char(args);
break;
case 's':
count += _print_string(args);
break;
case 'd':
count += _print_d_integer(args);
break;
case 'i':
count += _print_i_integer(args);
break;
case '%':
count += _putchar('%');
break;
default:
count += _putchar('%');
count += _putchar(*format);
break;
}
}
format++;
}
va_end(args);
return (count);
}
