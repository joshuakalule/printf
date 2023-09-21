#include "main.h"

/**
 * _printf - print a formated string
 * @format: format string
 *
 * Return: number of characters printed on stdout
 */
int _printf(const char *format, ...)
{
	int i = 0, chars_printed = 0, bsize = 0;
	char buffer[BUFSIZE] = {'\0'}, status[8] = {'\0'};
	va_list list;

	if (format == NULL)
		return (-1);

	/* initiate va_list */
	va_start(list, format);
	/* loop through all chars of format */
	for (i = 0; format[i] != '\0'; i++)
	{
		/* check for format specifier '%' */
		if (format[i] == '%')
		{
			/* execute flow for conversion specification */
			specifier((char *)format, &i, buffer, &bsize, list, &chars_printed, status);
		}
		else
		{
			/* add to buffer */
			append_char(format[i], buffer, &bsize, &chars_printed);
		}
	}
	/* empty the buffer onto stdout */
	dump(buffer, &bsize, &chars_printed);
	va_end(list);
	return (chars_printed);
}
