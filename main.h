#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>

/*
* _putchar function is the first one
*/
int _putchar(char c);

/*
* 0. I'm not going anywhere. You can print that wherever
* you want to. I'm here and I'm a Spur for life
*/
int _print_char(va_list args);
int _print_string(va_list args);

/*
* 1. Education is when you read the fine print.
* Experience is what you get if you don't
*/
int _print_integer(va_list args);

/*
* _printf function
*/
int _printf(const char *format, ...);


#endif
