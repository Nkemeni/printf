#include <unistd.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _strlen - returns the length of a string
 * @s: the string whose length is to be determine
 *
 * Return: the length of the string as an integer
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}


/**
 * _puts - prints a string
 * @str: string to be printed on the stdout
 */
void _puts(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}


/**
 * _printf - produces output according to a format
 * @format: pointer to pointer specifier
 *
 * Return: the number of characters printed excluding the null
 */
int _printf(const char *format, ...)
{
	va_list arg_list;
	int len;

	va_start(arg_list, format);
	len = 0;

	while (*format != '\0')
	{
		if (*format == '%')
			format++;
		if (*format == 'c')
		{
			char val;

			val = va_arg(arg_list, int);
			_putchar(val);
			len++;
		}
		else if (*format == 's')
		{
			char *val;

			val = va_arg(arg_list, char *);
			_puts(val);
			len += _strlen(val);
		}
		else
		{
			_putchar(*format);
			len++;
		}
		format++;
	}
	va_end(arg_list);

	return (len);
}


