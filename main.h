#ifndef main_h
#define main_h

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _strlenpf(char *s);
int _putchar(char c);
int (*get_pf_func(const char *s))(va_list list);
int print_char(va_list list);
int print_string(va_list list);
int print_per(va_list list __attribute__((unused)));
int print_integer(va_list list);
int _strcmp(char *s1, char ch);

/**
 * struct pf - Struct pf
 * @cha: character
 * @f: function asociated
 */
typedef struct pf
{
	char cha;
	int (*f)(va_list list);
} pf_t;

#endif
