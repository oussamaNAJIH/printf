#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int cur;
	int width = 0;

	for (cur = *i + 1; format[cur] != '\0'; cur++)
	{
		if (is_digit(format[cur]))
		{
			width *= 10;
			width += format[cur] - '0';
		}
		else if (format[cur] == '*')
		{
			cur++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cur - 1;

	return (width);
}
