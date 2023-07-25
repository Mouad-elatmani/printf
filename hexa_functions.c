#include "main.h"

/**
 * print_hexa - a function to print hexaD
 * @args: the list afo arguments
 * @array: an array
 * Return: return wc
 */

int print_hexa(va_list argumentsn, char array[])
{
    unsigned int num, temp;
    int count = 0;

    num = va_arg(arguments, unsigned int);
    if (num == 0)
    {
        _putchar('0');
        return (1);
    }

    temp = num;
    while (temp != 0)
    {
        temp /= 16;
        count++;
    }

    char hex_value[count];

    while (count > 0)
    {
        count--;
        hex_value[count] = array[num % 16];
        num /= 16;
    }

    for (int i = 0; i < sizeof(hex_value); i++)
    {
        _putchar(hex_value[i]);
    }

    return sizeof(hex_value);
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
