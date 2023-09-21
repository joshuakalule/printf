#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1024

#define FLAG_ARRAY_SIZE 5
#define FLAG_ARRAY {'#', '0', '-', ' ', '+'}

#define LEN_MODIFIER_ARRAY_SIZE 2
#define LEN_MODIFIER_ARRAY {'l', 'h'}

#define CONVERSION_ARRAY_SIZE 12
#define CONVERSION_ARRAY \
{'c', 's', '%', 'd', 'i', 'b', 'u', 'o', 'x', 'X', 'S', 'p'}

/**
 * struct conversion_s - simplify the conversion if statement
 * @ch: conversion character
 * @f: conversion function
 */
typedef struct conversion_s
{
	char ch;
	void (*f)(char *buffer, int *bsize, va_list list, char *flags, int *count);

} conversion_t;

/* core */
int _printf(const char *format, ...);
void specifier(char *, int *, char *, int *, va_list, int *, char *);
void run_conversion(char, char *, int *, va_list, char *, int *);

/* utility methods */
void dump(char buffer[], int *buffer_size, int *count);
void append(char *, char *, int *, int *);
void append_char(char, char *, int *, int *);
int check(char ch, char *string);
char *int_to_str(int number);
char *unsigned_int_to_str(unsigned int number);

/* helper methods */
char *_hexadecimal_conversion(int hex_add, va_list list);
char *__hex_body(int hex_add, unsigned int number);
char *__hex_body_ld(int hex_add, unsigned long number);

/* conversion methods */
void character_conversion(char *buffer, int *bsize, va_list list, char *flags,
		int *count);
void percent_conversion(char *buffer, int *bsize, va_list list, char *flags,
		int *count);
void string_conversion(char *buffer, int *bsize, va_list list, char *flags,
		int *count);
void decimal_conversion(char *buffer, int *bsize, va_list list, char *flags,
		int *count);
void binary_conversion(char *buffer, int *bsize, va_list list, char *flags,
		int *count);
void unsigned_decimal_conversion(char *buffer, int *bsize, va_list list,
		char *flags, int *count);
void octal_conversion(char *buffer, int *bsize, va_list list, char *flags,
		int *count);
void hexadecimal_lower_conversion(char *buffer, int *bsize, va_list list,
		char *flags, int *count);
void hexadecimal_upper_conversion(char *buffer, int *bsize, va_list list,
		char *flags, int *count);
void custom_string_conversion(char *buffer, int *bsize, va_list list,
		char *flags, int *count);
void pointer_conversion(char *buffer, int *bsize, va_list list, char *flags,
		int *count);


#endif
