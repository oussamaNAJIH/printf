#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _print_char - print a char
 * @args: The argument list
 * Return: The number of characters written
 */
int _print_char(va_list args)
{
char ch = va_arg(args, int);
return (_putchar(ch));
}
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
str = "(null)";
while (*str)
{
count += _putchar(*str);
str++;
}
return (count);
}
/**
 * _print_integer - print a signed integer (d, i)
 * @args: The argument list
 * Return: The number of characters written
 */
int _print_integer(va_list args)
{
int rev_num = 0;
int num = va_arg(args, int);
int count = 0;
int sign = 1;
if (num < 0)
{
sign = -1;
count += _putchar('-');
}
if (num == 0)
{
count += _putchar('0');
return (count);
}
while (num != 0)
{
rev_num = rev_num * 10 + (num % 10);
num /= 10;
}
while (rev_num != 0)
{
count += _putchar('0' + (rev_num % 10) * sign);
rev_num /= 10;
}
return (count);
}
/**
 * _printf - custom printf function
 * @format: The format string containing conversion specifiers
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
va_start(args, format);

if( format == NULL)
    return (-1);
while (*format)
{
if (*format != '%')
{
count += _putchar(*format);
}
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
case 'i':
count += _print_integer(args);
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
