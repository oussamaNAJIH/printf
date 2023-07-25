#include "main.h"

/**
 * _printf - printf function
 * @format: A string
 * Return: int
 */
int _printf(const char *format, ...)
{
	int printed_chars;
	conver_t f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"r", print_reversed},
		{"R", rot13},
		{"u", unsigned_integer},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{NULL, NULL}
	};
	va_list arg_list;

<<<<<<< HEAD
	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	/*Calling parser function*/
	printed_chars = parser(format, f_list, arg_list);
	va_end(arg_list);
	return (printed_chars);
=======
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
count += _print_integer(args);
break;
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
>>>>>>> ce2f4c802cf030b08d69eb0c10b2edab18cb5a3c
}
