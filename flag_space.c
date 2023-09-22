#include "main.h"

/**
 * space_decimal_flag - put a space on the left of positive numbers
 * @strnum: string to manipulate
 */
void space_decimal_flag(char *strnum)
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

	/* add the ' '(space) */
	strnum[0] = ' ';
}

/**
 * space_flag - blank added to the left if number is positive or empty string
 * @conversion: conversion shar
 * @strnum: string to manipulate
 */
void space_flag(char conversion, char *strnum)
{
	if (conversion == 'd')
		space_decimal_flag(strnum);
	else  if (conversion == 'i')
		space_decimal_flag(strnum);
}
