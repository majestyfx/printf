#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fnt - struct function up
 * by jone and ciny
 *
 * @fnt: format
 * @fn: associated functio
 */

struct fnt 
{
	char fnt;
	int (*fn)(va_list, char[], int, int, int, int,);
}:

/**
 * typedf struct fmt int_t - struct 
 */

/* function to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* function to print string in reverse */
int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size);

/* function to print a string in rot 13 */
int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int write_number(va_list types, char buffer[], int flags, int width, int precision, int size);
int write_num(va_list types, char buffer[], int flags, int width, int precision, int size);
int write_pointer(va_list types, char buffer[], int flags, int width, int precision, int size);
int write_unsgned(va_list types, char buffer[], int flags, int width, int precision, int size);

/***************UTILS***********************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgned

#endif
