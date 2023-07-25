#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int cur = *i + 1;
	int pre = -1;

	if (format[cur] != '.')
		return (pre);

	pre = 0;

	for (cur += 1; format[cur] != '\0'; cur++)
	{
		if (is_digit(format[cur]))
		{
			pre *= 10;
			pre += format[cur] - '0';
		}
		else if (format[cur] == '*')
		{
			cur++;
			pre = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cur - 1;

	return (pre);
}
