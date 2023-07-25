#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{

	int k, cur;
	int f = 0;
	const char F_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int F_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cur = *i + 1; format[cur] != '\0'; cur++)
	{
		for (k = 0; F_CH[k] != '\0'; k++)
			if (format[cur] == F_CH[k])
			{
				f |= F_ARR[k];
				break;
			}

		if (F_CH[k] == 0)
			break;
	}

	*i = cur - 1;

	return (f);
}
