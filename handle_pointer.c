#include "main.h"

#include <stdlib.h>
#include <stdio.h>
/**
 * helper_xP - a function that help to print pointer
 * @num: the number we gonna use
 * @bcount: a parameter number 1
 * Return: the character
*/

char *helper_xP(int bcount, unsigned long num)
{
	char *s = malloc(sizeof(char) * (bcount + 1));
	int rem;
	char *ptr;

	if (s == NULL)
		return (NULL);

	s[bcount] = '\0';

	ptr = s + bcount - 1;

	while (num > 0)
	{
		rem = num % 16;
		*ptr-- = (rem > 9) ? ('a' + (rem - 10)) : ('0' + rem);
		num /= 16;
	}

	return (s);
}


/**
 * handle_pointer - a function that writes signed hexadecimal integer
 * @args:variadic arguments
 * Return:the number of characters printed
*/
int handle_pointer(va_list args)
{
	unsigned long num = (unsigned long) va_arg(args, void *);
	char *s;
	unsigned long temp;
	int bcount = 0;

	if (num == 0)
		return (write(STDOUT_FILENO, "(nil)", 5));

	for (temp = num; temp != 0; temp /= 16)
		bcount++;

	s = helper_xP(bcount, num);

	if (s == NULL)
		return (0);

	write(STDOUT_FILENO, "0x", 2);
	write(STDOUT_FILENO, s, bcount);

	free(s);
	return (bcount + 2);
}
