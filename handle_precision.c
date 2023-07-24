#include "main.h"

/**
 * handle_precision - a function that calcule precision
 * @string: the string we gonna use
 * @arr: list of arguments
 * Return: the precision
 */

int handle_precision(const char *string, va_list arr)
{
	int i = 0;
	int precision = -1;

	/* look for the first '.' in string */

	while (string[i] != '\0' && string[i] != '.')
		i++;

	/* in case '.' doesnt exist  we gonna return -1 */

	if (string[i] == '\0')
		return (precision);

	precision = 0;
	i++;

	while (string[i] != '\0')
	{
		if (_digit(string[i])
		{
			precision = precision * 10 + (string[i] - '0');
			i++;
		}
		else if (string[i] == '*')
		{
			i++;
			precision = va_arg(arr, int);
			break;
		}
		else
			break;

	}
	return (precision);
}

/**
 * _digit - check if character is digit
 * @x: the char we gonna check
 * Return: 0 or 1
 */

int _digit(int x)
{
	return (x >= '0' && x <= '9');
}
