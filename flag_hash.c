#include "main.h"

/**
 * hash_oct_flag - add a '0'(zero) at the beginning of the strnum
 * @strnum: string to manipulate
 */
void hash_oct_flag(char *strnum)
{
	int size = (int)strlen(strnum);
	int i;

	if (strnum[0] == '0')
		return;

	/* 'add a byte for the new '0' to be added at the beginning */
	strnum = realloc(strnum, size + 1 + 1);
	if (!strnum)
		exit(1);

	/* single shift the entire string to the right */
	for (i = size; i >= 0; i--)
	{
		strnum[i + 1] = strnum[i];
	}

	/* add the '0' */
	strnum[0] = '0';
}

/**
 * hash_hex_flag - add a '0x' or '0X' to the strnum
 * @ch: conversion char
 * @strnum: string to manipulate
 */
void hash_hex_flag(char ch, char *strnum)
{
	int size = (int)strlen(strnum);
	int i;

	/* add 2 bytes for the new '0x' to be added at the beginning */
	strnum = realloc(strnum, size + 1 + 2);
	if (!strnum)
		exit(1);

	/* double shift the entire string to the right */
	for (i = size; i >= 0; i--)
	{
		strnum[i + 2] = strnum[i];
	}

	/* add '0x' or '0X' */
	strnum[0] = '0';
	strnum[1] = ch;
}
/**
 * hash_flag - manipulate strnum into its alternate form
 * @conversion: conversion applied to the strnum
 * @strnum: string to manipulate
 */
void hash_flag(char conversion, char *strnum)
{
	if (strnum[0] == '0' && strnum[1] == '\0')
		return;

	if (conversion == 'o')
	{
		hash_oct_flag(strnum);
	}
	else if (conversion == 'x')
	{
		hash_hex_flag('x', strnum);
	}
	else if (conversion == 'X')
	{
		hash_hex_flag('X', strnum);
	}
}
