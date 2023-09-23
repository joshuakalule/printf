#include "main.h"

/**
 * remove_flag - remove a flag
 * @ch: char to remove
 * @flags: flags array
 */
void remove_flag(char ch, char *flags)
{
	int i;

	for (i = 0; flags[i] != '\0'; i++)
	{
		if (flags[i] == ch)
			break;
	}

	while (1)
	{
		if (flags[i + 1] == '\0')
		{
			flags[i] = '\0';
			break;
		}
		flags[i] = flags[i + 1];
		i++;
	}
}


/**
 * add_flag - add a flag char to the flags
 * @ch: char to add
 * @flags: flags array
 */
void add_flag(char ch, char *flags)
{
	int i;

	if (check(ch, flags))
		return;

	for (i = 0; i < FLAG_ARRAY_SIZE; i++)
	{
		if (flags[i] == '\0')
		{
			flags[i] = ch;
			break;
		}
	}

	if ((ch == '-' && check('0', flags)) || (ch == '0' && check('-', flags)))
		remove_flag('0', flags);

	if ((ch == '+' && check(' ', flags)) || (ch == ' ' && check('+', flags)))
		remove_flag(' ', flags);
}

/**
 * handle_no_conversion - handles case when no conversion specifier is given
 * @ch: conversion char
 * @format: format string
 * @ci: pointer to the current index in format string
 * @buffer: buffer
 * @bsize: pointer to the buffer size
 * @count: pointer to the number of characters printed onto stdout
 * @status: array of return messages
 */
void handle_no_conversion(char ch, char *format, int *ci, char *buffer,
		int *bsize,	int *count, char *status)
{
	if (ch != '\0')
		return;

	if (format[*ci] != '\0' || *count != 0)
	{
		append_char('%', buffer, bsize, count);
		append_char(format[*ci], buffer, bsize, count);
		return;
	}
	status[0] = '0';
	(*ci)--;
}


/**
 * specifier - handle the '%' format specifier and all its elements
 * @format: pointer to the format string
 * @ci: pointer to the current index of the format string
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 * @count: pointer to the number of chars printed onto stdout
 * @status: array of return messages
 *
 * Description:
 * Based on the syntax for conversion specification 'man 3 printf'
 * %[flag][width][.precision][length modifier]conversion
 */
void specifier(char *format, int *ci, char *buffer, int *bsize, va_list list,
	   int *count, char *status)
{
	char flags[FLAG_ARRAY_SIZE] = {'\0'}, conversion = '\0';
	char length_modifier_array[] = LEN_MODIFIER_ARRAY;
	char conversion_array[] = CONVERSION_ARRAY, flag_array[] = FLAG_ARRAY;
	int i;

	(*ci)++;
	/* flags */
	for (i = 0; i < FLAG_ARRAY_SIZE; i++)
	{
		if (format[*ci] == flag_array[i])
		{
			add_flag(format[*ci], flags);
			(*ci)++;
			i = -1;
		}
	}
	/* length modifiers */
	for (i = 0; i < LEN_MODIFIER_ARRAY_SIZE; i++)
	{
		if (format[*ci] == length_modifier_array[i])
		{
			(*ci)++;
			/* ... */
		}
	}
	/* conversion */
	for (i = 0; i < CONVERSION_ARRAY_SIZE; i++)
	{
		if (format[*ci] == conversion_array[i])
		{
			conversion = format[*ci];
		}
	}
	handle_no_conversion(conversion, format, ci, buffer, bsize, count, status);
	run_conversion(conversion, buffer, bsize, list, flags, count);

	printf("flags: [%s], conversion: [%c]\n\n",
			flags, conversion);
}
