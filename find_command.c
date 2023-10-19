#include "shell.h"
/**
 * find_command - find and execute a command
 * This function searches for a command in the directories specified in the
 * environment paths and executes it if found
 * @env: environment variables
 * @command: command to be executed
 * @name: program name
 * @cycles: number of times it circles to find a command
 */
void find_command(char **env, char **command, char *name, int cycles)
{
	char *full_path = NULL;
	int i = 0;
	char **pathways;
	struct stat st;

	pathways = my_getpath(env, command);
	while (pathways[i])
	{
		full_path = my_strcat(pathways[i], "/");
		full_path = my_strcat(full_path, command[0]);
		i++;
		if (stat(full_path, &st) == 0)
		{
			if (execve(full_path, command, env) < 0)
			{
				perror(name);
				_free(pathways);
				free_exit(command);
			}
			return;
		}
	}

	msgerror(name, cycles, command);
	_free(pathways);
}
