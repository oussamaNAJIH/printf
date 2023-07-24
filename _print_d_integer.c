#include "main.h"
/**
 * _print_d_integer - print a signed integer (d, i)
 * @args: The argument list
 * Return: The number of characters written
 */
int _print_d_integer(va_list args)
{
int num = va_arg(args, int);
int count = 0;
int divisor = 1;
int temp;
if (num < 0)
{
count += _putchar('-');
num = -num;
}
if (num == 0)
{
count += _putchar('0');
return (count);
}
temp = num;
while (temp > 9)
{
divisor *= 10;
temp /= 10;
}
while (divisor > 0)
{
int digit = num / divisor;
count += _putchar('0' + digit);
num %= divisor;
divisor /= 10;
}
return (count);
}
