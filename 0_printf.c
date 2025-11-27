#include "main.h"
#include <unistd.h>

int _printf(const char *format, ...)
{
	int i, return_pourc, total = 0;
	va_list args; 
	va_start (args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{

			if (format[i + 1] == 'c' || format [i + 1] == 's' || format[i + 1] == '%')
				return_pourc = handle_cs(format[i + 1], args);
			else if (format[i + 1] == 'd' || format [i + 1] == 'i')
				return_pourc = handle_di(args);
			else
			{
				write(1, &format[i], 1);
				total ++;
				continue;
			}
				total += return_pourc;
				i++;
		}
		else
		{
			write(1, &format[i], 1);
			total ++;
		}
	}
	va_end(args);
	return(total);
}
