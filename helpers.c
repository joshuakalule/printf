#include "main.h"

/**
 * __hex_body - helper method to handle hex conversion
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @number: number to convert to hex
 *
 * Return: hex string translation of number
 */
char *__hex_body(int hex_add, unsigned int number)
{
	unsigned int i, num, count;
	char *hex_strnum;

	if (number < 16)
	{
		hex_strnum = malloc(2);
		if (!hex_strnum)
			exit(1);
		hex_strnum[1] = '\0';
		if (number >= 10)
			hex_strnum[0] = number + hex_add;
		else
			hex_strnum[0] = number + 48;
		return (hex_strnum);
	}

	count = 1;
	num = number;
	while (1)
	{
		num /= 16;
		count++;
		if (num < 16)
			break;
	}
	
	hex_strnum = malloc(sizeof(char) * (count + 1));
	if (!hex_strnum)
		exit(1);
	hex_strnum[count] = '\0';
	num = number;
	for (i = count - 1; num > 0; i--)
	{
		if (num < 16)
		{
			if (num >= 10)
				hex_strnum[i] = num + hex_add;
			else
				hex_strnum[i] = num + 48;
		}
		else
		{
			if ((num % 16) >= 10)
				hex_strnum[i] = (num % 16) + hex_add;
			else
				hex_strnum[i] = (num % 16) + 48;
		}
		num /= 16;
	}
	return (hex_strnum);
}

/**
 * _hexadecimal_conversion - helper function for the hex conversion
 * @hex_add - value to help convert 10 <= numbers <= 15 to letters
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 *
 * Return: hex string conversion of the number fetched from va_list (list)
 */
char *_hexadecimal_conversion(int hex_add, va_list list)
{
	unsigned int number = va_arg(list, unsigned int);

	return (__hex_body(hex_add, number));
}

/**
 * __hex_body_ld - helper function for the hex conversion to hanlde unsigned decimals
 * @hex_add - value to help convert 10 <= numbers <= 15 to letters
 * @buffer: buffer
 * @bsize: pointer to the current buffer size
 * @list: va_list argument
 *
 * Return: hex string conversion of the number fetched from va_list (list)
 */
char *__hex_body_ld(int hex_add, long unsigned number)
{
	long unsigned i, num ,count;
	char *hex_strnum;

	if (number < 16)
	{
		hex_strnum = malloc(2);
		if (!hex_strnum)
			exit(1);
		hex_strnum[1] = '\0';
		if (number >= 10)
			hex_strnum[0] = number + hex_add;
		else
			hex_strnum[0] = number + 48;
		return (hex_strnum);
	}

	count = 1;
	num = number;
	while (1)
	{
		num /= 16;
		count++;
		if (num < 16)
			break;
	}
	
	hex_strnum = malloc(sizeof(char) * (count + 1));
	if (!hex_strnum)
		exit(1);
	hex_strnum[count] = '\0';
	num = number;
	for (i = count - 1; num > 0; i--)
	{
		if (num < 16)
		{
			if (num >= 10)
				hex_strnum[i] = num + hex_add;
			else
				hex_strnum[i] = num + 48;
		}
		else
		{
			if ((num % 16) >= 10)
				hex_strnum[i] = (num % 16) + hex_add;
			else
				hex_strnum[i] = (num % 16) + 48;
		}
		num /= 16;
	}
	return (hex_strnum);
}
