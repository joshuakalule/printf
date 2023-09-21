#include "main.h"

/**
 * dump - empty the contents of the buffer to stdout
 * @buffer: buffer
 * @buffer_size: number of elements in the buffer
 * @count: pointer to the number of characters printed
 */
void dump(char buffer[], int *buffer_size, int *count)
{
	if (*buffer_size == 0)
		return;
	/* print onto the stdout (1) file descriptor */
	write(1, buffer, *buffer_size);
	/* update the number of characters printed */
	*count += *buffer_size;
	/* reset the buffer size to 0 */
	memset(buffer, 0, BUFSIZE);
	*buffer_size = 0;
}

/**
 * append - add characters from src to buffer
 * @src: pointer to the source characters
 * @buffer: buffer
 * @bsize: pointer to the current size of the buffer
 * @count: pointer to number of characters printed
 *
 * Note: src should be terminated with a '\0'
 */
void append(char *src, char *buffer, int *bsize, int *count)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		/* send to stdout if full */
		if (*bsize >= BUFSIZE)
			dump(buffer, bsize, count);

		/* add char to buffer */
		buffer[(*bsize)++] = src[i];
	}
}

/**
 * append_char - add ch to buffer
 * @ch: character to add
 * @buffer: buffer
 * @bsize: pointer to the current size of the buffer
 * @count: pointer to number of characters printed
 */
void append_char(char ch, char *buffer, int *bsize, int *count)
{
	char ptr[2];

	ptr[0] = ch;
	ptr[1] = '\0';
	append(ptr, buffer, bsize, count);
}

/**
 * check - check if 'ch' is in 'string'
 * @ch: character to look for
 * @string: character array to look in
 *
 * Return: 1(FOUND) 0(NOT FOUND)
 */
int check(char ch, char *string)
{
	int i;

	if (ch == '\0' || string == NULL)
		return (0);
	for (i = 0; string[i] != '\0'; i++)
	{
		if (ch == string[i])
			return (1);
	}
	return (0);
}

/**
 * int_to_str - convert an integer to string as is
 * @number: integer number
 *
 * Return: pointer to character array of the stringified number
 */
char *int_to_str(int number)
{
	char *numstring;
	int i, num, count;

	if (number == 0)
	{
		numstring = malloc(3);
		numstring[0] = '+';
		numstring[1] = '0';
		numstring[2] = '\0';
		return (numstring);
	}

	count = 0;
	num = number;
	while (num != 0)
	{
		num /= 10;
		count++;
	}

	numstring = malloc(sizeof(char) * (count + 1 + 1));
	if (!numstring)
		exit(1);
	numstring[count + 1] = '\0';
	numstring[0] = (number > 0) ? '+' : '-';
	num = number;
	for (i = count; i > 0; i--)
	{
		if (number < 0)
			numstring[i] = (num % 10) * (-1) + 48;
		else
			numstring[i] = (num % 10) + 48;
		num /= 10;
	}
	return (numstring);
}
