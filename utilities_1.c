#include "main.h"

/**
 * unsigned_int_to_str - convert an unsigned integer to string as is
 * @number: unsigned integer number
 *
 * Return: pointer to character array of the stringified number
 */
char *unsigned_int_to_str(unsigned int number)
{
	char *numstring;
	unsigned int i, num, count;

	if (number == 0)
	{
		numstring = malloc(2);
		numstring[0] = '0';
		numstring[1] = '\0';
		return (numstring);
	}

	count = 0;
	num = number;
	while (num != 0)
	{
		num /= 10;
		count++;
	}

	numstring = malloc(sizeof(char) * (count + 1));
	if (!numstring)
		exit(1);
	numstring[count] = '\0';
	num = number;
	for (i = count - 1; num > 0; i--)
	{
		numstring[i] = (num % 10) + 48;
		num /= 10;
	}
	return (numstring);
}
