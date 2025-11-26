#include "main.h"
#include <stdarg.h>

/**
* handle_pourc - Link to _printf and used to take in paramater the %
* @array: Is used to change what the user want instead of the %
* @args: Whqt the user want instead of the %
* Return: Return false if not the good value and the number of characters if good
*/

int handle_pourc(char array, va_list args)
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
		return (nb);
	}
	else
		return (0);

	return (nb);
}
