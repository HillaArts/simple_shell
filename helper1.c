#include "shell.h"
/**
 * my_atoi - function that converts chars  to integer
 * @s: input string
 * Return: integer from conversion
 */
int my_atoi(char *s)
{
	int sign = 1;
	unsigned int total = 0;
	char null_flag = 0;

	if (s == NULL)
	{
		return (0);
	}
	while (*s)
	{
		if (*s == '-')
		{
			sign *= -1;
		}
		if (*s >= '0' && *s <= '9')
		{
			null_flag = 1;
			total = total * 10 + (*s - '0');
		}
		else if (*s < '0' || *s > '9')
		{
			if (null_flag == 1)
			{
				break;
			}
		}
		s++;
	}
	if (sign < 0)
	{
		total = (-1 * (total));
	}
	return (total);
}
/**
 * my_strcat - function that concatenates two strings
 * @dest: input string
 * @src: input string
 * Return: pointer to the resulting string
 */
char *my_strcat(char *dest, const char *src)
{
	char *temp = dest;

	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (temp);
}
/**
 * my_strcpy - function that copies a string to another string
 * @dest: pointer to the copyed string
 * @src: pointer to string to copy for
 * Return: pointer to copied string
 */
char *my_strcpy(char *dest, const char *src)
{
	char *aux = dest;

	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (aux);
}
