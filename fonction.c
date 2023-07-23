#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * print_decimal - Function that print Numbers.
 *@arg: Variadic Arguments from user [Int].
 * Return: Length of digits
 */
int print_decimal(va_list arg)
{
	int a = va_arg(arg, int);
	int len = 0;
	unsigned int m, d, count;

	if (a == 0)
	{
		write(1, "0", 1);
		return (++len);
	}
	if (a < 0)
	{
		write(1, "-", 1);
		len++;
		m = a * -1;
	}
	else
	{
		m = a;
	}
	d = m;
	count = 1;
	while (d > 9)
	{
		d /= 10;
		count *= 10;
	}
	while (count >= 1)
	{
		char s = ((m / count) % 10) + '0';

		write(1, &s, 1);
		len++;
		count /= 10;
	}
	return (len);
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
		write(1, str[i], 1);
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
