#include "main.h"
#include <unistd.h>
/**
 * _printf - function that prints anything
 * @format: list of types of arguments passed to the function
 * Return: Returns number of printed characters if successful
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0, value = 0;
	va_list args;

	va_start(args, format);

	int (*f)(va_list);

	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
		{
			value = write(1, &format[i], 1);
			count = count + value;
			i++;
			continue;
		}
		if (format[i] == '%')
		{
			f = check_specifier(&format[i + 1]);
			if (f != NULL)
			{
				value = f(args);
				count = count + value;
				i = i + 2;
				continue;
			}
			if (format[i + 1] == '\0')
				break;
			if (format[i + 1] != '\0')
			{
				value = write(1, &format[i + 1], 1);
				count = count + value;
				i = i + 2;
				continue;
			}
		}
	va_end(args);
	}
	return (count);
}
