#include "main.h"

/**
 * print_hexa - a function to print hexaD
 * @args: the list afo arguments
 * @array: an array
 * Return: return wc
 */

int print_hexa(va_list args, char array[])
{
	int i = size_of_buff - 2, wc;
	unsigned long int n = va_arg(args, unsigned long int);
	char buff[size_of_buff];

	if (n == 0)
		buff[i--] = '0';

	buff[size_of_buff - 1] = '\0';

	while (n > 0)
	{
		buff[i--] = array[n % 16];
		n /= 16;
	}

	i++;

	wc = write(1, &buff[i], size_of_buff - 1 - i);

	return (wc);
}

/**
 * upper_hexa - a funxtion that print upper hexa
 * @args: the list of arguments
 * Return: an int
 */

int upper_hexa(va_list args)
{
	return (print_hexa(args, "0123456789ABCDEF"));
}

/**
 * lower_hexa - a funxtion that print lower hexa
 * @args: the list of arguments
 * Return: an int
 */

int lower_hexa(va_list args)
{
	return (print_hexa(args, "0123456789abcdef"));
}
