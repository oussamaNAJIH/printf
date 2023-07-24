#include "main.h"

/**
 * _print_i_integer - print a signed integer i
 * @args: The argument list
 * Return: The number of characters written
 */
int _print_i_integer(va_list args)
{
int num = va_arg(args, int);
int count = 0, shift = 28, divisor = 1, digit;
if (num == 0)
{
count += putchar('0');
return (count);
}
if (num < 0)
{
count += putchar('-');
num = -num;
}
if (num >= 0x100)
{
count += putchar('0') + putchar('x');
count -= 2;
while ((num >> shift) == 0)
{
shift -= 4;
}
while (shift >= 0)
{
digit = (num >> shift) &0xF;
count += putchar(digit < 10 ? '0' + digit : 'a' + digit - 10);
shift -= 4;
}
}
else
{
while (divisor <= num / 10)
	divisor *= 10;
while (divisor > 0)
{
digit = num / divisor;
count += putchar('0' + digit);
num %= divisor;
divisor /= 10;
}
}
return (count);
}
