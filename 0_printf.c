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
			return_pourc = handle_pourc(format[i + 1], args);

			if (return_pourc == 0)
			{
				write(1, &format[i], 1);
				total ++;
			}
			else
			{
				total += return_pourc;
				i++;
			}
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
