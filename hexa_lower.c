#include "main.h"

/**
 * lower_hex - function that writes signed hexadecimal integer
 * @args: variadic arguments
 * Return: the number of characters printed
 */
int lower_hex(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    unsigned int temp = num, bcount = 0;
    int reminder, i;
    char binary, *s;

    if (num < 2) {
        binary = '0' + num;
        write(STDOUT_FILENO, &binary, 1);
        return (1);
    }

    while (temp) { temp /= 16; bcount++; }
    
    if (!(s  = malloc(sizeof(char) * (bcount + 1)))) return (0);
    
    for (i = bcount - 1; i >= 0; i--, num /= 16) {
        reminder = num % 16;
        s[i] = (reminder > 9) ? (reminder - 10) + 'a' : reminder + '0';
    }
    
    s[bcount] = '\0';
    bcount = write(STDOUT_FILENO, s, bcount);
    free(s);

    return bcount;
}

