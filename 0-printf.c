#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * w_percent - write a '%'
 * @ptr: pointer to char
 * Return: number of characters written
 */
int w_percent(char *ptr)
{
	write(1, ptr, 1);
	return (1);
}

/**
 * w_char - write a single character
 * @list: va_list type argument
 * Return: number of characters written
 */
int w_char(va_list list)
{
	int tmp = va_arg(list, int);

	write(1, &tmp, 1);
	return (1);
}


/**
 * w_string - write a full string
 * @list: va_list type argument
 * Return: number of characters written
 */
int w_string(va_list list)
{
	int i, c = 0;
	char *tmp = va_arg(list, char *);

	if (!tmp)
	{
		write(1, "(null)", 6);
		c += 6;
		return (c);
	}

	for (i = 0; tmp[i] != '\0'; i++)
	{
		write(1, (tmp + i), 1);
		c++;
	}
	return (c);
}

/**
 * when_percent - handle cases when a '%' specifier has been used
 * @c: character after '%' sign
 * @list: va_list type
 *
 * Return: number of characters written to stdout
 */
int when_percent(char c, va_list list)
{
	int count = 0;

	if (c == '%')
	{
		count += w_percent(&c);
	}
	else if (c == 'c')
	{
		count += w_char(list);
	}
	else if (c == 's')
	{
		count += w_string(list);
	}
	else
	{
		write(1, "%", 1);
		write(1, &c, 1);
		count += 2;
	}

	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, count = 0, percent = 0;
	va_list list;

	if (!format)
		return (-1);

	va_start(list, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && percent == 0)
		{
			percent = 1;
			continue;
		}

		if (percent)
		{
			count += when_percent(format[i], list);

			percent = 0;
			continue;
		}

		write(1, (format + i), 1);
		count++;
	}
	va_end(list);

	if (percent)
		return (-1);
	return (count);
}
