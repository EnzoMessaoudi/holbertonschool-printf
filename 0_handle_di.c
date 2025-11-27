#include "main.h"
#include <stdarg.h>

/**
* handle_di - Function that write float and integrer
* @args: What the user want instead of the value
* Return: Return 0 if failed or number of characters writed
*/

int handle_di(va_list args)
{
	int nb_total = 0, value = va_arg(args, unsigned int), is_negative = 0, j, i = 0;
	char buffer[20];

	if (value == 0)
	{
		write(1, "0", 1);
		return (1);
	}

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

	if (is_negative == 1)
		buffer[i++] = '-';

	for (j = i - 1; j >= 0; j--)
	{
		write(1, &buffer[j], 1);
		nb_total++;
	}

	return (nb_total);
}
