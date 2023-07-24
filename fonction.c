#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * print_i - prints integer
 * @args: integer argument
 * Return: the decimal function
 */

int print_integer(va_list args)
{
	return (print_dec(args));
}
/**
 * print_dec - Function that print Numbers.
 *@arg: Variadic Arguments from user [Int].
 * Return: Length of digits
 */
int print_dec(va_list decimal)
{
	int len, powten, j, digit, num, count = 0, num_neg;

	num = va_arg(decimal, int);
	if (num != 0)
	{
		if (num < 0)
		{
			write(1, '-', 1))
			count++;
		}
		num_neg = num;
		len = 0;
		while (num_neg != 0)
		{
			num_neg /= 10;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 10;
		for (j = 1; j <= len; j++)
		{
			digit = num / powten;
			if (n < 0)
				_putchar((digit * -1) + 48);
			else
				_putchar(digit + '0');
			count++;
			num -= digit * powten;
			powten /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}

/**
 * ch - Function  print characters.
 *@arg: Variadic Arguments from user [char]
 * Return: Length 1 that equal one character
 */
int print_char(va_list arg)
{
	char c = va_arg(arg, int);

	write(1, &c, 1);
	return (1);
}
/**
 *print_string - Function  print String.
 *@arg: Variadic Arguments from user [String]
 * Return: Length of string or length of chara displayhed
 */
int print_string(va_list arg)
{
	char *str;
	int  i = 0;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 *print_percent - percent sign
 *Return: Number of chars printed
 */
int print_percent(void)
{
	return (write(1, "%%", 1));
}
