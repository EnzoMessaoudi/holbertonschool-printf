#include "main.h"
#include <stdarg.h>

/**
* handle_cs - Link to _printf and used to take in paramater the %
* @array: Is used to change what the user want instead of the %
* @args: Whqt the user want instead of the %
* Return: Return false if not the good value or the number of characters
*/

int handle_cs(char array, va_list args)
{
	int nb = 0;

	if (array == 'c')
	{
		char c = va_arg(args, int);

		write(1, &c, 1);
		nb++;
	}
	else if (array == 's')
	{
		char *str = va_arg(args, char *);

		if (!str)
			str = "(null)";
		while (*str)
		{
			write(1, str, 1);
			nb++;
			str++;
		}
	}
	else if (array == '%')
	{
		write(1, "%", 1);
		nb++;
	}
	else 
		return ('f');

	return (nb);
}
