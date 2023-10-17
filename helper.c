#include "shell.h"
/**
 * _strcpy - string copy function.
 *
 * This function copies the contents of the source
 * string into the destination string.
 *
 * dest: Destination string.
 * src: Source string.
 *
 * @return: A pointer to the destination string.
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
	dest[i] = src[i];
	i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - Calculate the length of a string.
 *
 * This function calculates the length of a string without
 * using the standard library strlen function.
 *
 * @param str: The input string.
 *
 * @return: The length of the string.
 */
int _strlen(const char *str)
{
	int length = 0;

	while (str[length] != '\0')
	{
	length++;
	}
	return (length);
}


/**
 * my_strcmp - Compare two strings
 * @str1: The first string
 * @str2: The second string
 *
 * Return: 0 if the strings are equal, a negative value if str1
 * is lexicographically.
 * less than str2, or a positive value if str1 is
 * lexicographically greater than str2.
 */
int my_strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str1 == *str2)
	{
	str1++;
	str2++;
	}

	return ((*(unsigned char *)str1) - (*(unsigned char *)str2));
}


/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string to be concatenated.
 * Return: A pointer to the resulting string.
 */
char *_strcat(char *dest, const char *src)
{
	int dest_len = 0;
	int src_len = 0;
	int i;

	while (dest[dest_len] != '\0')
	{
	dest_len++;
	}

	while (src[src_len] != '\0')
	{
	src_len++;
	}

	for (i = 0; i < src_len; i++)
	{
	dest[dest_len + i] = src[i];
	}

	dest[dest_len + src_len] = '\0';

	return (dest);
}

