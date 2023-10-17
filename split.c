#include "shell.h"

/**
 * split_input - Split a string into an array of words.
 * @input: The input string to split.
 *
 * Return: An array of words (tokens) or NULL on failure.
 */
char **split_input(char *input)
{
	char **args = (char **)malloc(MAX_ARGS * sizeof(char *));
	int i = 0;
	char *start = input;

	if (args == NULL)
	{
		perror("split_input");
		exit(EXIT_FAILURE);
	}
	while (*input)
	{
		if (*input == ' ' || *input == '\t' || *input == '\n')
		{
			*input = '\0';
			if (start != input)
			{
				args[i] = _strdup(start);
				if (args[i] == NULL)
				{
					perror("split_input");
					exit(EXIT_FAILURE);
				}
				i++;
			}
			start = input + 1;
		}
		input++;
	}
	if (start != input)
	{
		args[i] = _strdup(start);
		if (args[i] == NULL)
		{
			perror("split_input");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	args[i] = NULL;
	return (args);
}
