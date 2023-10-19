#include "shell.h"
/**
 * main - function that runs shell
 * @ac: number of arguments
 * @av: pointer to array of arguments
 * @env: pointer to array of environmental variables
 * Return: 0 (Success)
 */
int main(int ac, char **av, char **env)
{
	int cycles = 0;
	char *buff = NULL;
	size_t buf_size = 0;
	ssize_t char_read = 0;;
	(void)ac;

	while (1)
	{
		cycles++;
		prompt();
		signal(SIGINT, _handle);
		char_read = getline(&buff, &buf_size, stdin);
		if (char_read == EOF)
			_EOF(buff);
		else if (*buff == '\n')
			free(buff);
		else
		{
			command_shell(buff, av, env, cycles);
		}
		fflush(stdin);
		buff = NULL, buf_size = 0;
	}
	if (char_read == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
