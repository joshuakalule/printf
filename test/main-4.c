#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../main.h"

int main(void)
{
	int len, len2;
	long int l = UINT_MAX;

	l += 1024;
	len = _printf("%b", l);
	len2 = printf("1111111111");
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
