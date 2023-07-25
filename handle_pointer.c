#include "main.h"

/**
 * handle_pointer - a function that writes signed hexadecimal integer
 * @args:variadic arguments
 * Return:the number of characters printed
*/
int handle_pointer(va_list args)
{
	unsigned long num = (unsigned long) va_arg(args, void *);
	int bcount = 0, i, rem;
	char *s;
	unsigned long temp;

	if (num == 0)
		return (write(STDOUT_FILENO, "(nil)", 5) + 2);

	for (temp = num; temp != 0; temp /= 16)
		bcount++;

	s  = malloc(sizeof(char) * bcount + 1);
	if (s == NULL)
		return (NULL);

	for (i = bcount - 1; i >= 0; i--, num /= 16)
	{
		rem = num % 16;
		s[i] = rem + ((rem > 9) ? 'a' - 10 : '0');
	}

	s[bcount] = '\0';
	bcount =  write(STDOUT_FILENO, "0x", 2) + write(STDOUT_FILENO, s, bcount);
	free(s);

	return (bcount);
}

