#include "main.h"

/**
 * handle_rev - a function that prints the revof string
 * @args: the list of arguments
 * Return: an int
 */

int handle_rev(va_list args)
{
	int size, count = 0;
	char *txt = va_arg(args, char *);

	if (txt)
	{
		for (size = 0; *txt; txt++)
			size++;
		txt--;
		for (; size > 0; size--, txt--)
			count += _putchar(*txt);
	}
	return (count);
}
