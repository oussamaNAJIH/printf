#include "main.h"

/**
 * _put_char - write char
 * @c: The character to write
 *
 * Return: int
 */
int _put_char(char c)
{
	return (write(1, &c, 1));
}
