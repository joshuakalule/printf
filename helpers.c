#include "main.h"

/**
 * __less16 - handle numbers less than 16
 * @number: number
 * @hex_strnum: hex string number
 * @hex_add: value to convert 10, 11, ... into a, b, ... or A, B, ...
 */
void __less16(unsigned long number, char *hex_strnum, int hex_add)
{
	if (!hex_strnum)
		exit(1);
	hex_strnum[1] = '\0';
	if (number >= 10)
		hex_strnum[0] = (char)(number + hex_add);
	else
		hex_strnum[0] = (char)(number + 48);
}

/**
 * _hexadecimal_conversion - helper function for the hex conversion
 * @hex_add: value to help convert 10 <= numbers <= 15 to letters
 * @list: va_list arg
 *
 * Return: hex string conversion of the number fetched from va_list (list)
 */
char *_hexadecimal_conversion(int hex_add, va_list list)
{
	unsigned int number = va_arg(list, unsigned int);

	return (__hex_body(hex_add, number));
}

/**
 * __hex_body - helper method to handle hex conversion
 * @hex_add: value to convert 10, 11, ... into a, b, ... or A, B, ...
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
		__less16((unsigned long)number, hex_strnum, hex_add);
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
		hex_strnum[i] = (num >= 10) ? num + hex_add : num + 48;
		}
		else
		{
		hex_strnum[i] = ((num % 16) >= 10) ? (num % 16) + hex_add : (num % 16) + 48;
		}
		num /= 16;
	}
	return (hex_strnum);
}

/**
 * __hex_body_ld - hanlde unsigned decimal conversion
 * @hex_add: value to help convert 10 <= numbers <= 15 to letters
 * @number: number to convert to hex
 *
 * Return: hex string conversion of the number fetched from va_list (list)
 */
char *__hex_body_ld(int hex_add, unsigned long number)
{
	unsigned long i, num, count;
	char *hex_strnum = NULL;

	if (number < 16)
	{
		__less16(number, hex_strnum, hex_add);
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
		hex_strnum[i] = (num >= 10) ? (num + hex_add) : (num + 48);
		}
		else
		{
		hex_strnum[i] = (num % 16 >= 10) ? (num % 16) + hex_add : (num % 16) + 48;
		}
		num /= 16;
	}
	return (hex_strnum);
}
