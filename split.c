#include "shell.h"
/**
 * spliting - function use for spliting and make full string command
 * @buff: The pointer to input string
 * @s: The delimiter for strtok
 * Return: string
 */
char **spliting(char *buff, const char *s)
{
	char *split = NULL;
        char **commands = NULL;
	int i = 0;
	size_t bufsize = 0;

	if (buff == NULL)
	{
		return (NULL);
	}
	bufsize = my_strlen(buff);
	commands = malloc((bufsize + 1) * sizeof(char *));
	if (commands == NULL)
	{
		perror("Unable to allocate buffer");
		free(buff);
		_free(commands);
		exit(EXIT_FAILURE);
	}

	split = my_strtok(buff, s);
	while (split != NULL)
	{
		commands[i] = malloc(my_strlen(split) + 1);
		if (commands[i] == NULL)
		{
			perror("Unable to allocate buffer");
			_free(commands);
			return (NULL);
		}
		my_strcpy(commands[i], split);
		split = my_strtok(NULL, s);
		i++;
	}
	commands[i] = NULL;
	return (commands);
}
