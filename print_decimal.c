#include "main.h"
/**
 * print_decimal - function that prints a decimal
 * @arg_list: va_list containing the decimal to print
 * Description: prints a decimal using _putchar
 * Return: number of characters printed
 */
int print_decimal(va_list arg_list)
{
	int length, power_of_ten, j, digit, num, num_copy, count = 0;

	num = va_arg(arg_list, int);
	if (num != 0)
	{
		if (num < 0)
		{
			_putchar('-');
			count++;
		}
		num_copy = num;
		length = 0;
		while (num_copy != 0)
		{
			num_copy /= 10;
			length++;
		}
		power_of_ten = 1;
		j = 1;
		while (j <= length - 1)
		{
			digit = num / power_of_ten;
			if (num < 0)
				_putchar((digit * -1) + '0');
			else
				 _putchar(digit + '0');
			count++;
			num -= digit * power_of_ten;
			power_of_ten /= 10;
			j++
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
