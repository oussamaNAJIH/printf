#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>



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
 * _print_string - print a %s string
 * @str: The string to print
 * Return: The number of characters written
 */
int _print_string(char *str)
{
int i = 0;
if (str == NULL)
{
_print_string("(null)");
return (0);
}
while (str[i])
{
_putchar(str[i]);
i++;
}
return (i);
}
/**
 * _printf - custom printf function
 * @format: The format string containing conversion specifiers
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
int count = 0;
va_list args;
va_start(args, format);
if (!format || !format[0])
{
return (-1);
}
while (*format)
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
char c = va_arg(args, int);
_putchar(c);
count += _putchar(c);
}
else if
(*format == 's')
{
char *str = va_arg(args, char *);
count += _print_string(str);
}
else if
(*format == '%')
{
_putchar('%');
count++;
}
else
{
_putchar('%');
count++;
if (*format)
{
_putchar(*format);
count++;
}
}
format++;
}
else
{
_putchar(*format);
format++;
count++;
}
}
return (count);
}
