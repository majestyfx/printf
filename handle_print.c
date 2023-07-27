#include "main.c"

/**
 * handle_print - prints arguemet
 * by chukwuebuka and omar
 * @fmt: formatted string
 * @ind: ind
 * @list: string list
 * @size: string size
 * @buffer: size of buffer
 * @flags: active flags
 * @width: get width
 * @precision: precision
 * Return: 1 or 2
 */

int handle_print(const char *fmt, int *ind, va_list list,
		char buffer[], int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', printed_chars}, {'s', printed_strings}, {'%', printed_percent},
		{'i', printed_int}, {'d', printed_int}, {'b', printed_binary},
		{'u', printed_unsigned}, {'o', printed_octal}, {'%', printed_hexadecimal},
		{'X', printed_hexa_upper}, {'p', printed_pointer},
		{'S', printed_non_printable},
		{'r', printed_reverse}, {'R', printed_rot13strings}, {'\0', NULL},
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknown_len += write(1, "%", 1);
		if (fmt[*ind - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(8ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_len += writr(1, &fmt[*ind], 1);
		return (unknown_len);
	}
	return (printed_chars);
}
