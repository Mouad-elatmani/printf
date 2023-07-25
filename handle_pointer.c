#include "main.h"

/**
 * handle_pointer - a function tha print a pointer
 * @args: list of arguments
 * Return: an int hhh
 */

int handle_pointer(va_list list)
{
	void *pointer;
	char *s = "(nil)";
	long int res;
	int number;
	int i;

	pointer = va_arg(list, void*);
	if (pointer == NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			_putchar(s[i]);
		}
		return (i);
	}

	res = (unsigned long int)pointer;
	_putchar('0');
	_putchar('x');
	number = lower_hexa(list);
	return (number + 2);
}
