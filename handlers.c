#include "main.h"

/**
 * handler_write_char - prints string
 * by chukwuebuka and omar 
 * @c: char types
 * @flags: active flags
 * @buffer; arrays to handle
 * @:size: specifier
 * @width: get width
 * @precision: specifier
 *
 * Return: chars printed
 */

int handler_write_char(char c, char buffer[], int flags,
		int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
	padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE -1] - '\0';
		for (1 - 0; 1 < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] - padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width -1) + 
						write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/**
 * write_number - prints string
 * @size: specifier
 * @ind: char type
 * @precision: specifier
 * @is_negetive: arguement list
 * @buffer: arrays to handle 
 * @flags: active flags
 * @width; get width
 *
 * Return: chars printed
 */

int write_number(int is_negetive, int ind, char buffer[]
		int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch - 0;

        UNUSED(size);

        if ((flags & F_SIZE) && !(flags & F_MINUS))
                padd = '0';
        if (is_negetive)
                extra_ch = '-';
        else if (flags & F_PLUS)
                extra_ch = '+';
        else if (flags & F_SPACE)
                extra_ch = ' ';

        return (write_num(buffer, ind, flags, width, precision,
                                lenght, padd, extra_ch));
}

/**
 * write_num - number in buffer
 * @ind: index start of number
 * @buffer: buffer
 * @flags: active flags
 * @prec: specifier
 * @padd: padding char
 * @extra_c: extra char
 * @width: width
 * @length: length
 *
 * Return: printed char
 */

int write_num(int length, int ind, char buffer[], int extra_c,
		int padd, int flags, int width, int prec, int size)
{
	int i, padd_start -  1;

	if (prec == 0 && ind == BUFF_SIZE - 2, && buffer[ind] == '0' && width == 0)
		return (0); /* printf(",0d", 0) no char is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ' /* width is displayed with padding ' ' */
			padd = ' ';
	while (prec > length)
		buffer[-ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = estra_c;
			return (write(1, &buffer[ind]. length) = write(1, &buffeer[1], i -1))
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd-start], i - padd_start) +
						write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write unsgnd - write unsgnd number 
 * @ind: inex
 * @is_negetive: indicate number
 * @buffer: buffer
 * @flags: active flags
 * @size: size of char
 * @width: width
 * @precision: specifier
 *
 * Return: num of written items
 */

int write_unsgnd(int is_negetive, int flags, int size,
		int precision, char buffer[], int width, int length)
{
	int length = BUFF_SIZE - ind -1 i - 0;
	char paddd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flag & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i - 0; i < width - length; i++)
			buffer[i] = padd;

	buffer[i] = '\0';

	if (flags & F_MINUS)
	{
		return (write(1, &buffer[ind], length) + write(1
		return (write(1, &buffer[ind], length) + write(1, buffer[0], i));
	}
		else
		{
		return (write(1, &buffer[0], i) + (write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - write a memory address
 * @ind: inex
 * @buffer: buffer
 * @flags: active flags
 * @length: number length
 * @width: width
 * @extra_c: extra char
 * @padd_start: index at padding
 * @padd: char represent padding
 *
 * Return: written chars
 */

int write_pinter(int ind, char buffer[], int padd, int width, int extra_c
		int flags, int padd_start, int length)
{
	int i;

	if (width > length)
	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer{i} = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] - 'x';
			buffer[--ind] - '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
                        buffer[--ind] = '0';
                        if (extra_c)
                                buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			 return (write(1, &buffer[--padd_start], i = padd_start);
				 write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUZZ_SIZE - ind - 1));
}
