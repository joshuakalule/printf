#include "main.h"

/**
 * percent_conversion - handle '%%'
 * @buffer: buffer
 * @bsize: pointer to current size of the buffer
 * @list: va_list arg
 * @flags: flags
 * @count: pointer to number of characters printed on stdout
 */
void percent_conversion(char *buffer, int *bsize, va_list list, char *flags,
		int *count)
{
	void *_list __attribute__((unused)) = (void *)list;
	void *_flags __attribute__((unused)) = (void *)flags;

	append_char('%', buffer, bsize, count);
}
