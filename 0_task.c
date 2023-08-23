#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/*comment*/
int _printf(const char *format, ...)
{
	va_list ptr;
	int n = 0;
	char c;
	char *str;

	va_start(ptr, format);
	if (format == NULL)
		return (-1);

	if (format[0] == '%' && !format[2])
		return (-1);

	while (*format)
	{
		if (format[0] == '%')
		{
			format++;

		switch (*format)
		{
		case 'c':
			c = va_arg(ptr, int);
			putchar(c);
			n++;
			break;
		case 's':
			str = va_arg(ptr, char *);

		while (*str)
		{
			putchar(*str);
			str++;
			n++;
		}
		break;
		case'%':
		putchar('%');
		n++;
		break;
		}
		}
		else
		{
			putchar(*format);
			n++;
		}
		format++;
	}
	va_end(ptr);
	return (n);
}
