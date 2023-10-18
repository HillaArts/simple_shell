#include "shell.h"
/**
 * my_fprintf - function similar to fprintf
 * @stream: The output stream (e.g., stderr)
 * @format: The format string
 * @...: Variable number of arguments to be formatted and printed
 * Description: This function mimics the behavior of fprintf by taking
 * a format string and a variable number of arguments and printing
 * the formatted output to the specified stream.
 */
void my_fprintf(FILE *stream, const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vfprintf(stream, format, args);
	va_end(args);
}
