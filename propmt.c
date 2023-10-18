#include "shell.h"
/**
 * prompt - function that prints the prompt
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "simpleshell$ ", 15);
	}
}
