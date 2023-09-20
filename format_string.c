#include "main.h"
/**
 * specifier - handle the '%' format specifier and all its elements
 * @format: pointer to the format string
 * @ci: pointer to the current index of the format string
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 * @count: pointer to the number of chars printed onto stdout
 *
 * Description:
 * Based on the syntax for conversion specification 'man 3 printf'
 * %[flag][width][.precision][length modifier]conversion
 */
void specifier(char *format, int *ci, char *buffer, int *bsize, va_list list,
	   int *count)
{
	char *flags = NULL;
	char length_modifier[3] = {'\0'};
	char conversion = '\0';
	char flag_array[] = FLAG_ARRAY;
	char length_modifier_array[] = LEN_MODIFIER_ARRAY;
	char conversion_array[] = CONVERSION_ARRAY;
	int i;

	/* flags */
	for (i = 0; i < FLAG_ARRAY_SIZE; i++)
	{
		if (format[*ci] == flag_array[i])
		{
			(*ci)++;
			/* ... */
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

	run_conversion(conversion, buffer, bsize, list, flags, count);
	/* printf("flags: [%s], length modifier: [%s], conversion: [%c]\n\n",
			flags, length_modifier, conversion); */
}
