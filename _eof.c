#include "shell.h"
/**
 * _EOF - function that checks if buffer is EOF
 * @buff: The pointer to the input string
 */
void _EOF(char *buff)
{
	if (buff)
	{
		free(buff);
		buff = NULL;
	}

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "\n", 1);
	}
	free(buff);
	exit(EXIT_SUCCESS);
}
