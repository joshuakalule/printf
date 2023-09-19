#include <limits.h>
#include <stdio.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;

	printf("%%c, %%s, %%\n");

	len = _printf("char: '%c', string: '%s', %%: '%%'\n", 65, "Hello world!");
	len2 = printf("char: '%c', string: '%s', %%: '%%'\n", 65, "Hello world!");
	printf("\n_printf: %d\nprintf:  %d\n", len, len2);

	return (0);
}
