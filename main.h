#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


/* task 0 functions */

int _printf(const char *format, ...);

/*task4 */

#define size_of_BUFF 1024

int handle_Buff(int c);

/* all we need in flags tasks */

#define flag_M  1
#define flag_P 2
#define flag_H 8
#define flag_Z 4
#define flag_S 16

int handle_flags(char *string);
int print_dec(va_list arg);
int print_char(va_list arg);
int print_string(va_list arg);
int print_percent(void);
int print_binary(va_list types);
int print_integer(va_list args);

