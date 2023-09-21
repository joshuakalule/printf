#include "main.h"

/**
 * octal_conversion - handle 'o'
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 * @flags: flags
 * @count: pointer to the number of characters printed onto stdout
 */
void octal_conversion(char *buffer, int *bsize, va_list list, char *flags,
		int *count)
{
	void *_flags __attribute__((unused)) = (void *)flags;
	unsigned int number = va_arg(list, unsigned int);
	unsigned int i, num, c;
	char *octal_strnum;

	if (number < 8)
	{
		append_char(number + 48, buffer, bsize, count);
		return;
	}

	c = 1;
	num = number;
	while (num >= 8)
	{
		num /= 8;
		c++;
	}
	octal_strnum = malloc(sizeof(char) * (c + 1));
	if (!octal_strnum)
		exit(1);
	octal_strnum[c] = '\0';
	num = number;
	for (i = c - 1; num > 0; i--)
	{
		if (num < 8)
			octal_strnum[i] = num + 48;
		else
			octal_strnum[i] = (num % 8) + 48;
		num /= 8;
	}
	append(octal_strnum, buffer, bsize, count);
	free(octal_strnum);
}

/**
 * hexadecimal_lower_conversion - handle 'x'
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 * @flags: flags
 * @count: pointer to the number of characters printed onto stdout
 */
void hexadecimal_lower_conversion(char *buffer, int *bsize, va_list list,
		char *flags, int *count)
{
	void *_flags __attribute__((unused)) = (void *)flags;
	char *hex_strnum = _hexadecimal_conversion(87, list);

	append(hex_strnum, buffer, bsize, count);
	free(hex_strnum);
}

/**
 * hexadecimal_upper_conversion - handle 'X'
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 * @flags: flags
 * @count: pointer to the number of characters printed onto stdout
 */
void hexadecimal_upper_conversion(char *buffer, int *bsize, va_list list,
		char *flags, int *count)
{
	void *_flags __attribute__((unused)) = (void *)flags;
	char *hex_strnum = _hexadecimal_conversion(55, list);

	append(hex_strnum, buffer, bsize, count);
	free(hex_strnum);
}

/**
 * custom_string_conversion - handle 'S'
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 * @flags: flags
 * @count: pointer to the number of characters printed onto stdout
 */
void custom_string_conversion(char *buffer, int *bsize, va_list list,
		char *flags, int *count)
{
	void *_flags __attribute__((unused)) = (void *)flags;
	char *string = va_arg(list, char *);
	unsigned int i;
	char *fstring = NULL;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] < 32 || string[i] >= 127)
		{
			append("\\x", buffer, bsize, count);
			if (string[i] < 16)
				append_char('0', buffer, bsize, count);
			fstring = __hex_body(55, string[i]);
			append(fstring, buffer, bsize, count);
			free(fstring);
		}
		else
		{
			append_char(string[i], buffer, bsize, count);
		}
	}
}

/**
 * pointer_conversion - handle 'p'
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 * @flags: flags
 * @count: pointer to the number of characters printed onto stdout
 */
void pointer_conversion(char *buffer, int *bsize, va_list list, char *flags,
		int *count)
{
	void *_flags __attribute__((unused)) = (void *)flags;
	void *pointer = va_arg(list, void *);
	char *fstring = __hex_body_ld(87, (unsigned long)pointer);

	append("0x", buffer, bsize, count);
	append(fstring, buffer, bsize, count);

	free(fstring);
}
