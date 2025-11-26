#include "main.h"
#include <stdarg.h>

/**
* handle_di - Function that write float and integrer
* @array: Value passes by the user
* @va_list: What the user want instead of the value
* Return: Return 0 if failed or number of characters writed
*/

int handle_di(char array, va_list args)
{
	int nb = 0;

	if (array == 'd' || array == 'i')
	{
		int value = va_arg(args, int);
		char buffer[12];
		int is_negative, j, i = 0;

		if (value == 0)
			return (0);

		if (value < 0)
		{
			is_negative = 1;
			value = -value;
		}
		while (value > 0)
		{
			buffer[i++] = '0' + (value % 10);
			value /= 10;
		}

		if (is_negative)
			buffer[i++] = '-';

		for (j = i; j >= 0; j--)
		{
			write(1, &buffer[j], 1);
			nb++;
		}
	}
	else
		return (0);

	return (nb);
}
