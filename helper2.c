#include "shell.h"
/**
 * my_strlen - function that finds the length of the string
 * @s: input string
 * Return: length of the string
 */
unsigned int my_strlen(const char *s)
{
	unsigned int len = 0;

	while (s[len])
	{
		len++;
	}
	return (len);
}
/**
 * my_strcmp - funtion that compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 1 if strings are the same, 0 if otherwise
 */
int my_strcmp(const char *s1, const char *s2)
{
	unsigned int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/**
 * my_fprintf - function similar to fprintf
 * @stream: The output stream (e.g., stderr)
 * @format: The format string
 * @...: Variable number of arguments to be formatted and printed
 * Description: This function mimics the behavior of fprintf by taking
 * a format string and a variable number of arguments and printing
 * the formatted output to the specified stream
 */
void my_fprintf(FILE *stream, const char *format, ...)
{
        va_list args;

        va_start(args, format);
        vfprintf(stream, format, args);
        va_end(args);
}
