#include "main.h"
#include <stdarg.h>

/**
* handle_di - Function that write float and integrer
* @array: Value passes by the user
* @va_list: What the user want instead of the value
* Return: Return 0 if failed or number of characters writed
*/

int handle_di(va_list args)
{
	int nb_total = 0, value = va_arg(args, int), is_negative, j, i = 0;
	char buffer[12];

	if (value == 0)
		return (0);

	if (value < 0)
	{
		is_negative = 1;
		value = - value;
	}
	while (value > 0)
	{
		buffer[i++] = '0' + (value % 10);
		value /= 10;
	}

	if (is_negative == 1)
		buffer[i++] = '-';

	for (j = i; j >= 0; j--)
	{
		write(1, &buffer[j], 1);
		nb_total++;
	}

	return (nb_total);
}
