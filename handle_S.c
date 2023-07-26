#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

/**
 * handle_S - a function that prints a string in hexadecimal representation.
 * @args: variadic arguments
 * Return: the number of characters printed
 */
int handle_S(va_list args)
{
    char *str, binary, *s;
    int len = 0, j, i = 0, bcount = 2;
    unsigned int num;
    int reminder;

    str = va_arg(args, char*);
    if (str == NULL)
    {
        str = "(null)";
        write(STDOUT_FILENO, str, len = strlen(str));
        return (len);
    }
    while (str[i] != '\0')
    {
        num = (unsigned int)str[i];
        s  = malloc(sizeof(char) * bcount + 1);
        if (s == NULL) return -1;
        for (j = bcount - 1; j != -1; j--)
        {
            reminder = num % 16;
            binary = (reminder > 9) ? (reminder - 10) + 'A' : reminder + '0';
            s[j] = binary;
            num = num / 16;
        }
        s[bcount] = '\0';
        if ((str[i] >= 0 && str[i] < 32) || (str[i] >= 127))
        {
            len +=  write(STDOUT_FILENO, "\\x", 2) + write(STDOUT_FILENO, s, 2);
        }
        else
        {
            write(STDOUT_FILENO, &str[i], 1);
            len++;
        }
        free(s);
        i++;
    }
    return (len);
}

