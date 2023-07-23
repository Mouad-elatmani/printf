    #include "main.h"
    /**
     * print_binary - Prints an unsigned number
     * @types: Lista of arguments
     * Return: Numbers of char printed.
     */
    int print_binary(va_list types)
    {
        unsigned int n, max, i, sum;
        unsigned int a[32];
        int count;
        n = va_arg(types, unsigned int);
        max = 2147483648; /* (2 ^ 31) */
        a[0] = n / max;
        for (i = 1; i < 32; i++)
        {
            max /= 2;
            a[i] = (n / max) % 2;
        }
        for (i = 0, sum = 0, count = 0; i < 32; i++)
        {
            sum += a[i];
        if (sum || i == 31)
        {
            char z = '0' + a[i];
            write(1, &z, 1);
            count++;
        }
        }
        return (count);
    }
