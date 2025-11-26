#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int handle_cs(char array, va_list args);
int handle_di(char array, va_list args);
int handle_anything(char array, va_list args);

#endif
