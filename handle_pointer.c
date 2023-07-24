#include "main.h"

/**
 * handle_pointer - a function tha print a pointer
 * @args: list of arguments
 * Return: an int hhh
 */

int handle_pointer(va_list args)
{
	unsigned long n;
	char array[] = "0123456789abcdef";
	int x = -1, digit, i, wc = 0;
	void *ad = va_arg(args, void *);

	if (!ad)
		return (write(1, "(nil)", 5));

	n = (unsigned long)ad;
	_putchar('0');
	_putchar('x');

	for (i = 15; i >= 0; --i)
	{
		digit = (n >> (4 * i)) & 0xF;
		if (digit != 0 || i == 0)
		{
			x = i;
			break;
		}
	}

	for (i = x; i >= 0; --i)
	{
		digit = (n >> (4 * i)) & 0xF;
		wc += _putchar(array[digit]);
	}
	return (wc);
}
