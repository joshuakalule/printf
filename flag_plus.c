#include "main.h"

/**
 * plus_decimal_flag - add a '+' at the left of non negative numbers
 * @strnum: string to manipulate
 */
void plus_decimal_flag(char *strnum)
{
	int size = (int)strlen(strnum);
	int i;

	if (strnum[0] == '-')
		return;

	/* 'add a byte for the new ' '(space) to be added at the beginning */
	strnum = realloc(strnum, size + 1 + 1);
	if (!strnum)
		exit(1);

	/* single shift the entire string to the right */
	for (i = size; i >= 0; i--)
	{
		strnum[i + 1] = strnum[i];
	}

	/* add the '+' */
	strnum[0] = '+';
}

/**
 * plus_flag - add a sign (+/-) at the beginning of the strnum
 * @conversion: conversion char
 * @strnum: string to be manipulated
 */
void plus_flag(char conversion, char *strnum)
{
	if (conversion == 'd')
		plus_decimal_flag(strnum);
	else if (conversion == 'i')
		plus_decimal_flag(strnum);
}
