#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
* print_binary - convert to binary
* @bin: number in decinal
* Return: number of chars printed
*/
int print_binary(va_list bin)
{
	unsigned int len, powten, j, digit, n, num;
	int count = 0;

	n = va_arg(bin, unsigned int);
	if (n == 0)
	{
		_putchar('0');
		return (1);
	}
		
	else
	{
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 2;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 2;
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			_putchar(digit + '0');
			count++;
			n -= digit * powten;
			powten /= 2;
		}
	}
	
	return (count);
}
