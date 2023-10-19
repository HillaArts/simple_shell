#include "shell.h"
/**
 * exitshell - exiting shell function
 * @command: spliting command pointer
 * Return: 
 */
void exitshell(char **command)
{
	int status = 0;

	if (command[1] == NULL)
	{
		_free(command);
		exit(EXIT_SUCCESS);
	}

	status = my_atoi(command[1]);
	_free(command);
	exit(status);
}
