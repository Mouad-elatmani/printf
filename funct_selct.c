#include "main.h"
/**
 * func_select - selects the function based on the format
 * @format: format specifier character
 * Return: pointer to the appropriate printing function
 */
int (*func_select(char format))(va_list)
{
	switch (format)
	{
	case 'c':
		return (&print_ch);
	case 's':
		return (&print_str);
	case 'd':
		return (&print_decimal);
	case 'i':
		return (&print_int);
	case '%':
		return (&print_percent);
	case 'b':
		return (&print_bin);
	default:
		return (NULL);
	}
}
