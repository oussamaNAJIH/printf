#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - custom printf function
 * @format: The format string containing conversion specifiers
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...);
/**
 * _putchar - write a char to stdout
 * @c: The character to print
 * Return: The number of characters written
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
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
_print_string("(null)");
while (*str)
{
_putchar(*str);
str++;
count++;
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
int num = va_arg(args, int);
int count = 0;
int divisor = 1;
int temp;
int sign = 1;
if (num < 0)
{
sign = -1;
count += _putchar('-');
num = -num;
}
if (num == 0)
{
count += _putchar('0');
return (count);
}
temp = num;
while (temp > 9)
{
divisor *= 10;
temp /= 10;
}
while (divisor > 0)
{
int digit = num / divisor;
count += _putchar('0' + digit * sign);
num %= divisor;
divisor /= 10;
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

if (!format || !format[0])
{
return (-1);
}
va_start(args, format);
if (!format || !format[0])
{
return (-1);
}
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
