#include "main.h"

/**
 * struct w - width info struct
 * @width: the width
 * @processed_chars: processed characters
 */

typedef struct w{
    int width;
    int processed_chars;
} widthData;

/**
 * handle_width - calculte the width
 * @string: the string we gonna use
 * @arr: the argument pointer
 * Return: the width
 */

widthData handle_width(const char *string, va_list arr)
{
	int total_width = 0;
	const char *temp = string;

	while (*temp != '\0')
	{
		if (_digit(*temp))
			total_width = total_width * 10 + (*temp - '0');
		else if (*temp == '*')
		{
			temp++;
			total_width = va_arg(arr, int);
			break;
		}
		else
			break;
		temp++;
	}
	widthData data = {total_width, temp - string};
	return (data);
}

/**
 * _digit - check if character is digit
 * @x: the character we gonna check
 * Return: 0 or 1
 */

/* if it didnt work we gonna use -char x- instead of -int x-*/
int _digit(int x)
{
	return (x >= '0' && x <= '9');
}
