#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, print = 0, print_chars = 0;
	int f, w, p, s, b_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[b_ind++] = format[i];
			if (b_ind == BUFF_SIZE)
				print_buffer(buffer, &b_ind);
			/* write(1, &format[i], 1);*/
			print_chars++;
		}
		else
		{
			print_buffer(buffer, &b_ind);
			f = get_flags(format, &i);
			w = get_width(format, &i, list);
			p = get_precision(format, &i, list);
			s = get_size(format, &i);
			++i;
			print = handle_print(format, &i, list, buffer,
				f, w, p, s);
			if (print == -1)
				return (-1);
			print_chars += print;
		}
	}

	print_buffer(buffer, &b_ind);

	va_end(list);

	return (print_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
