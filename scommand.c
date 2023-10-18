#include "shell.h"
/**
 * command_shell - command to execute shell
 * @buff: input command buffer
 * @av: command-line arguments
 * @env: environment variables
 * @cycles: Number of cycles (or any relevant parameter)
 * This function tokenizes and executes a shell command based
 * on the input buffer.i
 */
void command_shell(char *buff, char **av, char **env, int cycles)
{
	char **command = NULL;

	buff[_strlen(buff) - 1] = '\0';

	command = tokening(buff, " \0");

	free(buff);

	if (command && command[0])
	{
		if (my_strcmp(command[0], "exit") != 0)
			shell_exit(command);
		else if (my_strcmp(command[0], "cd") != 0)
			chdir(command[1]);
		else if (my_strcmp(command[0], "env") != 0)
			_env(env);
		else
		{
			createchild(command, av[0], env, cycles);
		}
	}
	else
	{
		free_dp(command);
	}
}
