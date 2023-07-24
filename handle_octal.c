#include "main.h"

/**
 * handle_octal - a function that print octal
 * @args: the list of arguments
 * Return: an int hhh
 */

int handle_octal(va_list args)
{
	unsigned long int n = va_arg(args, unsigned long int);
	int i = 0, wc = 0, j;
	int buff[size_of_buff];

	if (n == 0)
		return (_putchar('0'));

	while (n != 0)
	{
		buff[i] = n % 8;
		n /= 8;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		wc += _putchar('0' + buff[j]);
	}
	return (wc);
}
