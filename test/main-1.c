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

	printf("%%d, %%i\n");

	len = _printf("integer[d]: '%d', integer[i]: '%i'\n", 2048, 0x1cf);
	len2 = printf("integer[d]: '%d', integer[i]: '%i'\n", 2048, 0x1cf);
	printf("\n_printf: %d\nprintf:  %d\n", len, len2);

	return (0);
}
