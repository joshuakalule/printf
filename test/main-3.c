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

	printf("%%u, %%o, %%x, %%X\n");

	len = _printf("unsigned: '%u', octal: '%o', hex: '%x', HEX: '%X'\n", 703704, 703704, 703704, 703704);
	len2 = printf("unsigned: '%u', octal: '%o', hex: '%x', HEX: '%X'\n", 703704, 703704, 703704, 703704);
	printf("\n_printf: %d\nprintf:  %d\n", len, len2);

	return (0);
}
