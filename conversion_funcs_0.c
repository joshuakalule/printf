#include "main.h"

/**
 * character_conversion - handle 'c'
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 * @flags: flags
 * @count: pointer to the number of characters printed onto stdout
 */
void character_conversion(char *buffer, int *bsize, va_list list, char *flags,
		int *count)
{
	void *_flags __attribute__((unused)) = (void *)flags;
	char ch = (char)va_arg(list, int);

	if (ch == '\0')
		ch = 0;
	append_char(ch, buffer, bsize, count);
}

/**
 * string_conversion - handle 's'
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 * @flags: flags
 * @count: pointer to the number of characters printed onto stdout
 */
void string_conversion(char *buffer, int *bsize, va_list list, char *flags,
		int *count)
{
	void *_flags __attribute__((unused)) = (void *)flags;
	char *string = va_arg(list, char *);

	if (string == NULL)
	{
		append("(null)", buffer, bsize, count);
		return;
	}
	append(string, buffer, bsize, count);
}

/**
 * decimal_conversion - handle 'd' & 'i'
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 * @flags: flags
 * @count: pointer to the number of characters printed onto stdout
 */
void decimal_conversion(char *buffer, int *bsize, va_list list, char *flags,
		int *count)
{
	int number = va_arg(list, int);
	char *numstring = int_to_str(number);

	printf("number: %d\n", number);
	execute_flags('d', numstring, flags);

	append(numstring, buffer, bsize, count);
	free(numstring);
}

/**
 * binary_conversion - handle 'b'
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 * @flags: flags
 * @count: pointer to the number of characters printed onto stdout
 */
void binary_conversion(char *buffer, int *bsize, va_list list, char *flags,
		int *count)
{
	void *_flags __attribute__((unused)) = (void *)flags;
	unsigned int number = va_arg(list, long);
	unsigned int num;
	unsigned int i, c;
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
	for (i = c - 1; num >= 1; i--)
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
 * @flags: flags
 * @count: pointer to the number of characters printed onto stdout
 */
void unsigned_decimal_conversion(char *buffer, int *bsize, va_list list,
		char *flags, int *count)
{
	void *_flags __attribute__((unused)) = (void *)flags;
	unsigned int number = va_arg(list, unsigned int);
	char *numstring = unsigned_int_to_str(number);

	append(numstring, buffer, bsize, count);
	free(numstring);
}
