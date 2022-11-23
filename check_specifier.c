#include "main.h"
/**
 * check_specifier - check that character is a valid specifier and
 * assigns an appropriate fucntion to print it
 * @format: the specifier (char*)
 *
 * Return: pointer to function, if successful
 *  NULL pointer if not successful
 */
int (*check_specifier(const char *format))(va_list)
{
	int i;

	func_t spechar_array[6] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_cent},
		{"i", print_int},
		{"d", print_dec},
		{NULL, NULL}};
	for (i = 0; spechar_array[i].t != NULL; i++)
	{
		if (*(spechar_array[i].t) == *format)
		{
			return (spechar_array[i].f);
		}
	}

	return (NULL);
}
