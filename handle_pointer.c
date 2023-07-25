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
	void *ad = va_arg(args, void *);
	char buff[size_of_buff];
	int i = size_of_buff - 2;

	if (!ad)
		return (write(1, "(nil)", 5));

	buff[size_of_buff - 1] = '\0';
	n = (unsigned long)ad;

	_putchar('0');
	_putchar('x');

	while (n > 0)
	{
		buff[i--] = array[n % 16];
		n /= 16;
	}
	i++;
	return (write(1, &buff[i], size_of_buff - i - 1));
}
