#include "shell.h"
/**
 * my_strtok - custom strtok function
 * @delim: bytes set that delimit the
 * tokens in the parsed string
 * @str: string to parse
 * Return: start token
 */
char *my_strtok(char *str, const char *delim)
{
	char *start;
	static char *end;

	if (str)
	{
		end = str;
	}
	else
	{
		if (!end)
		{
			return (NULL);
		}
		str = end;
	}
	str = token_finder(str, delim);

	if (*str == '\0')
	{
		end = NULL;
		return (NULL);
	}
	start = str;
	while (*str && !my_delim(*str, delim))
	{
		str++;
	}

	if (*str)
	{
		*str = '\0';
		end = str + 1;
	}
	else
	{
		end = NULL;
	}
	return (start);
}
/**
 * my_delim - function helps checking if a character is a delimiter
 * @delim: delimiter
 * @c: character value
 * Return: delimiter
 */
int my_delim(char c, const char *delim)
{
	return (strchr(delim, c) != NULL);
}
/**
 * my_strncmp - fuction that compares two strings
 * @s1: ...
 * @s2: ....
 * @n: ....
 * Return: ...
 */
int my_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}
