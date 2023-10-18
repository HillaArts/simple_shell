#include "shell.h"
/**
 * msgerror - function that prints message not found
 * @name: The name of the shell
 * @cycles: Number of cicles
 * @command: The pointer to tokenized command
 */
void msgerror(char *name, int cycles, char **command)
{
	char c;

	c = cycles + '0';
	write(STDOUT_FILENO, name, my_strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, command[0], my_strlen(command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
