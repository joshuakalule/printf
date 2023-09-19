#include "main.h"

void character_conversion(char *buffer, int *bsize, va_list list, int *count)
{
	char ch = (char)va_arg(list, int);

	append_char(ch, buffer, bsize, count);
}

void string_conversion(char *buffer, int *bsize, va_list list, int *count)
{
	char *string = va_arg(list, char *);
	int i;

	append(string, buffer, bsize, count);
}

void decimal_conversion(char *buffer, int *bsize, va_list list, char *flags, int *count)
{
	char *numstring = int_to_str(va_arg(list, int));
	int i, x;

	i = 0;
	if (numstring[0] == '+')
	{	
		if (check(' ', flags) == 1)
		{
			numstring[0] = ' ';
		}
		else if (check('+', flags) == 1)
		{
			/* do nothing */
		}
		else
		{
			/* default */
			i = 1;
		}
	}
	
	append(numstring, buffer, bsize, count);
	free(numstring);
}

void binary_conversion(char *buffer, int *bsize, va_list list, int *count)
{
	unsigned int number = va_arg(list, unsigned int);
	unsigned int num;
	int i, c;
	char *binary_strnum;

	if (number == 0)
	{
		buffer[(*bsize)++] = '0';
		return;
	}
	else if (number == 1)
	{
		buffer[(*bsize)++] = '1';
		return;
	}

	c = 1;
	num = number;
	while (1)
	{
		num /= 2;
		c++;
		if (num <= 1)
			break;
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
	for (i = 0; i < c; i++)
	{
		buffer[(*bsize)++] = binary_strnum[i];
	}
	free(binary_strnum);
}

void unsigned_decimal_conversion(char *buffer, int *bsize, va_list list, char *flags, int *count)
{
	unsigned int number = va_arg(list, unsigned int);
	char *numstring = unsigned_int_to_str(number);
	unsigned int i;

	for (i = 0; numstring[i] != '\0'; i++)
	{
		buffer[(*bsize)++] = numstring[i];
	}

	free(numstring);
}

void octal_conversion(char *buffer, int *bsize, va_list list, char *flags, int *count)
{
	unsigned int number = va_arg(list, unsigned int);
	unsigned int i, num, c;
	char *octal_strnum;

	if (number < 8)
	{
		buffer[(*bsize)++] = number + 48;
		return;
	}

	c = 1;
	num = number;
	while (1)
	{
		num /= 8;
		c++;
		if (num < 8)
			break;
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
	for (i = 0; i < c; i++)
	{
		buffer[(*bsize)++] = octal_strnum[i];
	}
	free(octal_strnum);
}

void hexadecimal_lower_conversion(char *buffer, int *bsize, va_list list, char *flags, int *count)
{
	char *hex_strnum = _hexadecimal_conversion(87, buffer, bsize, list);
	unsigned int i;

	for (i = 0; hex_strnum[i] != '\0'; i++)
	{
		buffer[(*bsize)++] = hex_strnum[i];
	}
	free(hex_strnum);
}

void hexadecimal_upper_conversion(char *buffer, int *bsize, va_list list, char *flags, int *count)
{
	char *hex_strnum = _hexadecimal_conversion(55, buffer, bsize, list);
	unsigned int i;

	for (i = 0; hex_strnum[i] != '\0'; i++)
	{
		buffer[(*bsize)++] = hex_strnum[i];
	}
	free(hex_strnum);
}

void custom_string_conversion(char *buffer, int *bsize, va_list list, char *flags, int *count)
{
	char *string = va_arg(list, char *);
	unsigned int i, x, c;
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
			buffer[(*bsize)++] = '\\';
			buffer[(*bsize)++] = 'x';
			if (string[i] < 16)
				buffer[(*bsize)++] = '0';
			fstring = __hex_body(55, buffer, bsize, string[i]);
			for (x = 0; fstring[x] != '\0'; x++)
				buffer[(*bsize)++] = fstring[x];
		}
		else
		{
			buffer[(*bsize)++] = string[i];
		}
	}
	free(fstring);
}

void pointer_conversion(char *buffer, int *bsize, va_list list, char *flags, int *count)
{
	void *pointer = va_arg(list, void *);
	char *fstring = __hex_body_ld(87, buffer, bsize, (long unsigned)pointer);
	int i;

	buffer[(*bsize)++] = '0';
	buffer[(*bsize)++] = 'x';
	for (i = 0; fstring[i] != '\0'; i++)
	{
		buffer[(*bsize)++] = fstring[i];
	}
	free(fstring);
}
