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
	if (ch == 'c')
	{
		character_conversion(buffer, bsize, list, count);
	}
	else if (ch == 's')
	{
		string_conversion(buffer, bsize, list, count);
	}
	else if (ch == '%')
	{
		append_char('%', buffer, bsize, count);
	}
	else if (ch == 'd')
	{
		/* interpreted as signed decimal integers */
		decimal_conversion(buffer, bsize, list, flags, count);
	}
	else if (ch == 'i')
	{
		/* intepreted as specified base, default = base10 */
		decimal_conversion(buffer, bsize, list, flags, count);
	}
	else if (ch == 'b')
	{
		binary_conversion(buffer, bsize, list, count);
	}
	else if (ch == 'u')
	{
		unsigned_decimal_conversion(buffer, bsize, list, count);
	}
	else if (ch == 'o')
	{
		octal_conversion(buffer, bsize, list, count);
	}
	else if (ch == 'x')
	{
		hexadecimal_lower_conversion(buffer, bsize, list, count);
	}
	else if (ch == 'X')
	{
		hexadecimal_upper_conversion(buffer, bsize, list, count);
	}
	else if (ch == 'S')
	{
		custom_string_conversion(buffer, bsize, list, count);
	}
	else if (ch == 'p')
	{
		pointer_conversion(buffer, bsize, list, count);
	}
}
