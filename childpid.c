#include "shell.h"
/**
 * createchild - function that make sub process
 * @name: pointer to the name of shell
 * @command: pointer to spliting command
 * @env: pointer to the  enviromental variables
 * @cycles: number of executed cicles
 */
void createchild(char **command, char *name, char **env, int cycles)
{
	int pid = 0;
	int status = 0;
	int wait_error = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		free_exit(command);
	}
	else if (pid == 0)
	{
		execute(command, name, env, cycles);
		_free(command);
	}
	else
	{
		wait_error = waitpid(pid, &status, 0);
		if (wait_error < 0)
		{
			free_exit(command);
		}
		_free(command);
	}
}
