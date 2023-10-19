#include "shell.h"
/**
 * my_getpath - function to gets the full value from
 * enviromental variable PATH
 * @env: pointer to enviromental variables
 * @command: user input
 * Return: tokenized pathways for commands
 */
char **my_getpath(char **env, char **command)
{
	char *pathvalue = NULL;
	char **pathways = NULL;
	int len;
	unsigned int i = 0;
	pid_t pid = 1;

	while (env[i])
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			pathvalue = env[i] + 5;

			if (pathvalue[0] == '\0')
			{
				my_fprintf(stderr, "./hsh: %d: %s: not found\n", pid, command[0]);
				exit(127);
			}

			while (pathvalue[0] == ':')
				pathvalue++;

			len = my_strlen(pathvalue);
			while (len > 0 && pathvalue[len - 1] == ':')
			{
				pathvalue[len - 1] = '\0';
				len--;
			}
			pathways = spliting(pathvalue, ":");
			return (pathways);
		}
		i++;
	}

	my_fprintf(stderr, "./hsh: %d: %s: not found\n", pid, command[0]);
	exit(127);
}
