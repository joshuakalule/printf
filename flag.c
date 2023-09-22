#include "main.h"

/**
 * execute_flags - perform operations for each flag
 * @ch: conversion char
 * @strnum: string to manipulate
 * @flags: pointer to the flags
 */
void execute_flags(char ch, char *strnum, char *flags)
{
	int i;
	char hash_conversions[] = HASH_CONVERSIONS;
	char space_conversions[] = SPACE_CONVERSIONS;
	char plus_conversions[] = PLUS_CONVERSIONS;

	for (i = 0; flags[i] != '\0'; i++)
	{
		if (flags[i] == '#' && check(ch, hash_conversions))
			hash_flag(ch, strnum);

		if (flags[i] == ' ' && check(ch, space_conversions))
			space_flag(ch, strnum);

		if (flags[i] == '+' && check(ch, plus_conversions))
			plus_flag(ch, strnum);
	}
}
