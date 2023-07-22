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
