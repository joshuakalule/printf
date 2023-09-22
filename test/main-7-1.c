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

	printf("Flag: '#'\n");

	len = _printf("octal (#): '%#o'\n", 38);
	len2 = printf("octal (#): '%#o'\n", 38);
	if (len != len2)
		printf("Failed!\n");
	printf("\n_printf: %d\nprintf:  %d\n\n", len, len2);

	len = _printf("hex (#): '%#x'\n", 1246);
	len2 = printf("hex (#): '%#x'\n", 1246);
	if (len != len2)
		printf("Failed!\n");
	printf("\n_printf: %d\nprintf:  %d\n\n", len, len2);

	len = _printf("HEX (#): '%#X'\n", 1246);
	len2 = printf("HEX (#): '%#X'\n", 1246);
	if (len != len2)
		printf("Failed!\n");
	printf("\n_printf: %d\nprintf:  %d\n\n", len, len2);
	
	return (0);
}
