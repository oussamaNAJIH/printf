#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int cur = *i + 1;
	int s = 0;

	if (format[cur] == 'l')
		s = S_LONG;
	else if (format[cur] == 'h')
		s = S_SHORT;

	if (s == 0)
		*i = cur - 1;
	else
		*i = cur;

	return (s);
}
