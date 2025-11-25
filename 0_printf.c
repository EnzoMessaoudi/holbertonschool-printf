#include "handle_pourc.c"
#include "main.h"
#include <unistd.h>

int_printf(const char *format, ...)
{
	int i, return_pourc, total = 0;
	va_list args; 
	va_start (args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == % && args)
		{
			return_pourc = handle_pourc(format[i] + 1, args);

			if (return_pourc == "false")
			{
				write(format[i]);
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
			write(format[i])
			total ++;
		}
	}
	printf("\n");
	va_end(args);
	return(total);
}
