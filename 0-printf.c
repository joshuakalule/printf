#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
	int i, j, count = 0;
	char *tmp;
	int tmp1;
	int percent = 0;
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
			if (format[i] == '%')
			{
				write(1, (format + i), 1);
				count++;
			}
			else if (format[i] == 'c')
			{
				tmp1 = va_arg(list, int);
				write(1, &tmp1, 1);
				count++;
			}
			else if (format[i] == 's')
			{
				tmp = va_arg(list, char *);
				if (!tmp)
				{
					write(1, "(null)", 6);
					count += 6;
				}
				else
				{
					for (j = 0; tmp[j] != '\0'; j++)
					{
						write(1, (tmp + j), 1);
						count++;
					}
				}
			}
			else
			{
				write(1, (format + i), 1);
				count++;
			}
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
