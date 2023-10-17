#include "shell.h"
/**
 * _atoi - Converts a string to an integer.
 * @str: The string to be converted.
 * Return: The integer value of the string.
 */
int _atoi(char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == ' ' || str[i] == '\t')
	i++;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
/**
 * my_strncmp - Compare two strings up to a specified number of characters.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The maximum number of characters to compare.
 *
 * Return: 0 if the strings are equal up to n characters, a negative value if
 * s1 is lexicographically less than s2, or a positive value if s1 is
 * lexicographically greater than s2.
 */
int my_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && (*s1 == *s2))
	{
		n--;
		s1++;
		s2++;
	}
	if (n == 0)
	{
		return (0);
	}
	return (*s1 - *s2);
}
