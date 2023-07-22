#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: the string to printout
 * Return: returns the number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int printed_chars = 0;
while (*format)
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
{
char ch = (char) va_arg(args, int);
putchar(ch);
printed_chars++;
break;
}
case 's':
{
const char *str = va_arg(args, const char *);
while (*str)
{
putchar(*str);
str++;
printed_chars++;
}
break;
}
case '%':
{
putchar('%');
printed_chars++;
break;
}
default:
{
putchar('%');
printed_chars++;
break;
}
}
}
else
{
putchar(*format);
printed_chars++;
}
format++;
}
va_end(args);
return (printed_chars);
}
