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
	printf("%%S\n");

	printf("Custom string conversion: 'Best\\nSchool'\n");

	_printf("%S\n", "Best\nSchool");

	return (0);
}
