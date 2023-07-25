#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
* struct convert - defines a structure for symbols and functions
*
* @sym: The operator
* @f: The function associated
*/
struct convert
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convert conver_t;

<<<<<<< HEAD
/*Main functions*/
int parser(const char *format, conver_t f_list[], va_list arg_list);
=======
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
>>>>>>> ce2f4c802cf030b08d69eb0c10b2edab18cb5a3c
int _printf(const char *format, ...);
int _put_char(char);
int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_integer(va_list);
int print_number(va_list);
int print_binary(va_list);
int print_reversed(va_list arg);
int rot13(va_list);
int unsigned_integer(va_list);
int print_octal(va_list list);
int print_hex(va_list list);
int print_heX(va_list list);

/*Helper functions*/
unsigned int base_len(unsigned int, int);
char *rev_string(char *);
void write_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
int print_unsgined_number(unsigned int);


#endif
