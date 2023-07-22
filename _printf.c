#include <unistd.h>
#include <stdarg.h>
#include "main.h"

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

	return (_putchar(ch));
}

/**
 * _print_string - print a %s string
 * @args: The argument list
 * Return: The number of characters written
 */
int _print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count;

	count = 0;
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
 * _printf - custom printf function
 * @format: The format string containing conversion specifiers
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;

	count = 0;
	va_start(args, format);
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
