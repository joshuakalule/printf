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

	printf("%%p\n");

	len = _printf("pointer: '%p'\n", (void *)&len);
	len2 = printf("pointer: '%p'\n", (void *)&len);
	printf("\n_printf: %d\nprintf:  %d\n", len, len2);

	return (0);
}
