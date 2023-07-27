#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fnt - struct function up
 * chukwuebuka and omar
 *
 * @fnt: format
 * @fn: associated functio
 */

struct fnt 
{
	char fnt;
	int (*fn)(va_list, char[], int, int, int, int);
}:

/**
 * typedf struct fmt int_t - struct 
 */

int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size);

int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size);

int handle_write_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int write_number(va_list types, char buffer[], int flags, int width, int precision, int size);
int write_num(va_list types, char buffer[], int flags, int width, int precision, int size);
int write_pointer(va_list types, char buffer[], int flags, int width, int precision, int size);
int write_unsgned(va_list types, char buffer[], int flags, int width, int precision, int size);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgned;

#endif
