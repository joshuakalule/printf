#include "main.h"

/**
 * character_conversion - handle 'c'
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 * @count: pointer to the number of characters printed onto stdout
 */
void character_conversion(char *buffer, int *bsize, va_list list, int *count)
{
	char ch = (char)va_arg(list, int);

	append_char(ch, buffer, bsize, count);
}

/**
 * string_conversion - handle 's'
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 * @count: pointer to the number of characters printed onto stdout
 */
void string_conversion(char *buffer, int *bsize, va_list list, int *count)
{
	char *string = va_arg(list, char *);

	append(string, buffer, bsize, count);
}

/**
 * decimal_conversion - handle 'd' & 'i'
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 * @count: pointer to the number of characters printed onto stdout
 */
void decimal_conversion(char *buffer, int *bsize, va_list list, char *flags, int *count)
{
	int number = va_arg(list, int);
	char *numstring = int_to_str(number);
	int i;

	/**
	 * the number comes with the sign whether +ve or -ve
	 * 0(zero) also comes as '+0'
	 */
	if (flags != NULL)
	{
		if (check(' ', flags) && number >= 0)
			numstring[0] = ' ';
	}
	else
	{
		/* default case - remove the '+' */
		if (number >= 0)
		{
			for (i = 1; numstring[i] != '\0'; i++)
				numstring[i - 1] = numstring[i];
			numstring[i - 1] = '\0';
		}
	}

	append(numstring, buffer, bsize, count);
	free(numstring);
}

/**
 * binary_conversion - handle 'b'
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 * @count: pointer to the number of characters printed onto stdout
 */
void binary_conversion(char *buffer, int *bsize, va_list list, int *count)
{
	unsigned int number = va_arg(list, unsigned int);
	unsigned int num;
	int i, c;
	char *binary_strnum;

	if (number == 0 || number == 1)
	{
		append_char(number + 48, buffer, bsize, count);
		return;
	}
	c = 1;
	num = number;
	while (num > 1)
	{
		num /= 2;
		c++;
	}
	binary_strnum = malloc(sizeof(char) * (c + 1));
	if (!binary_strnum)
		exit(1);
	binary_strnum[c] = '\0';
	num = number;
	for (i = c - 1; i >= 0; i--)
	{
		binary_strnum[i] = (num % 2) + 48;
		num /= 2;
	}

	append(binary_strnum, buffer, bsize, count);
	free(binary_strnum);
}

/**
 * unsigned_decimal_conversion - handle 'u'
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 * @count: pointer to the number of characters printed onto stdout
 */
void unsigned_decimal_conversion(char *buffer, int *bsize, va_list list, int *count)
{
	unsigned int number = va_arg(list, unsigned int);
	char *numstring = unsigned_int_to_str(number);

	append(numstring, buffer, bsize, count);
	free(numstring);
}

/**
 * octal_conversion - handle 'o'
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 * @count: pointer to the number of characters printed onto stdout
 */
void octal_conversion(char *buffer, int *bsize, va_list list, int *count)
{
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
 * @flags: pointer to flags
 * @count: pointer to the number of characters printed onto stdout
 */
void hexadecimal_lower_conversion(char *buffer, int *bsize, va_list list, int *count)
{
	char *hex_strnum = _hexadecimal_conversion(87, list);

	append(hex_strnum, buffer, bsize, count);
	free(hex_strnum);
}

/**
 * hexadecimal_upper_conversion - handle 'X'
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 * @flags: pointer to flags
 * @count: pointer to the number of characters printed onto stdout
 */
void hexadecimal_upper_conversion(char *buffer, int *bsize, va_list list, int *count)
{
	char *hex_strnum = _hexadecimal_conversion(55, list);

	append(hex_strnum, buffer, bsize, count);
	free(hex_strnum);
}

/**
 * custom_string_conversion - handle 'S'
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 * @flags: pointer to flags
 * @count: pointer to the number of characters printed onto stdout
 */
void custom_string_conversion(char *buffer, int *bsize, va_list list, int *count)
{
	char *string = va_arg(list, char *);
	unsigned int i, c;
	char *fstring;

	c = 0;
	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] < 32 || string[i] >= 127)
			c += 4;
		else
			c += 1;
	}

	fstring = malloc(sizeof(char) * (c + 1));
	if (!fstring)
		exit(1);

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] < 32 || string[i] >= 127)
		{
			append("\\x", buffer, bsize, count);
			if (string[i] < 16)
				append_char('0', buffer, bsize, count);
			fstring = __hex_body(55, string[i]);
			append(fstring, buffer, bsize, count);
		}
		else
		{
			append_char(string[i], buffer, bsize, count);
		}
	}
	free(fstring);
}

/**
 * pointer_conversion - handle 'p'
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 * @flags: pointer to flags
 * @count: pointer to the number of characters printed onto stdout
 */
void pointer_conversion(char *buffer, int *bsize, va_list list, int *count)
{
	void *pointer = va_arg(list, void *);
	char *fstring = __hex_body_ld(87, (long unsigned)pointer);

	append("0x", buffer, bsize, count);
	append(fstring, buffer, bsize, count);

	free(fstring);
}
