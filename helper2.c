#include "shell.c"
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
int _strcmp(const char *s1, const char *s2)
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
