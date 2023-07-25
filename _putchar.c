#include <unistd.h>
/**
 * _putchar - write a char
 * @c: a char
 * Return: 1 on success and -1 otherwise
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
