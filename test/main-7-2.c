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

	printf("Flag: ' '(space)\n\n");

	len = _printf("'% d'\n", 38);
	len2 = printf("'% d'\n", 38);
	if (len != len2)
		printf("Failed!\n");
	printf("\n_printf: %d\nprintf:  %d\n\n", len, len2);
	
	len = _printf("'% d'\n", -38);
	len2 = printf("'% d'\n", -38);
	if (len != len2)
		printf("Failed!\n");
	printf("\n_printf: %d\nprintf:  %d\n\n", len, len2);

	len = _printf("'% d'\n", 0);
	len2 = printf("'% d'\n", 0);
	if (len != len2)
		printf("Failed!\n");
	printf("\n_printf: %d\nprintf:  %d\n\n", len, len2);
	
	return (0);
}
