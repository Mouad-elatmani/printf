#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

/**
 * handle_octal - a function that writes signed octal integer
 * @args:variadic arguments
 * Return:the number of characters printed
 */
int handle_octal(va_list args)
{
	unsigned int temp, bcount = 0, num = va_arg(args, unsigned int);
	char binary, *s;
	int i;

	if (num == 1 || num == 0)
	{
		binary = '0' + num;
		write(STDOUT_FILENO, &binary, 1);
		return (1);
	}
	for (temp = num; temp != 0; temp /= 8)
		bcount++;
	s = malloc(sizeof(char) * bcount + 1);
	if (s == NULL)
		return (0);
	for (i = bcount - 1; i >= 0; i--)
	{
		binary = (num % 8) + '0';
		s[i] = binary;
		num /= 8;
	}
	s[bcount] = '\0';
	bcount = write(STDOUT_FILENO, s, bcount);
	free(s);
	return (bcount);
}

