#include "shell.h"
/**
 * execute - function that executes a command
 * @command: pointer to tokienized command
 * @name: name of the shell
 * @env: pointer to the enviromental variables
 * @cycles: number of executed cycles
 */
void execute_command(char **command, char *name, char **env, int cycles)
{
	struct stat st;

	(void)name, (void)cycles;

	if (my_strcmp(command[0], "env") != 0)
	{
		print_env(env);
	}
	if (command[0][0] == '/' || command[0][0] == '.')
	{
		if (stat(command[0], &st) == 0)
		{
			if (execve(command[0], command, env) < 0)
			{
				perror(name);
				free_exit(command);
			}
		}
		else
		{
			perror(name);
			free_exit(command);
		}
	}
	else
	{
		find_command(env, command, name, cycles);
	}
}
