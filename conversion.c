#include "main.h"

/**
 * run_conversion - handle conversion specifiers
 * @ch: conversion character
 * @buffer: buffer
 * @bsize: pointer to the current size of the buffer
 * @list: va_list argument
 * @flags: pointer to the flags
 * @count: pointer to the nuber of characters printed onto stdout
 */
void run_conversion(char ch, char *buffer, int *bsize, va_list list,
		char *flags, int *count)
{
	int i;

	conversion_t conversions[] = {
		{'c', character_conversion},
		{'s', string_conversion},
		{'%', percent_conversion},
		{'d', decimal_conversion},
		{'i', decimal_conversion},
		{'b', binary_conversion},
		{'u', unsigned_decimal_conversion},
		{'o', octal_conversion},
		{'x', hexadecimal_lower_conversion},
		{'X', hexadecimal_upper_conversion},
		{'S', custom_string_conversion},
		{'p', pointer_conversion},
		{'\0', NULL}
	};

	for (i = 0; conversions[i].ch != '\0'; i++)
	{
		if (ch == conversions[i].ch)
			conversions[i].f(buffer, bsize, list, flags, count);
	}
}
