#include "shell.h"
/**
 * main - Entry point for the simple shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * @envp: An array of environment variable strings.
 * Return: 0 on success.
 */
int main(int argc, char **argv, char **envp)
{
	char prompt[] = "simple_shell$ ";
	char *input = NULL;
	size_t len = 0;
	ssize_t read;
	(void)argv;
	(void)argc;

	while (1)
	{
		write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
		read = getline(&input, &len, stdin);
		if (read == -1)
	{
	if (feof(stdin))
	{
		write(STDOUT_FILENO, "\n", 1);
		break;
	}
	else
	{
		char error[] = "Error: getline/n";
		
		write(STDERR_FILENO, error, sizeof(error) - 1);
		exit(127);
	}
	}
		if (input[read - 1] == '\n')
		{
			input[read - 1] = '\0';
		}
		if (my_strcmp(input, "exit") == 0)
		{
			exit(0);
		}
		if (my_strncmp(input, "exit ", 5) == 0)
		{
			int status = _atoi(input + 5);
			exit(status);
		}
		execute_command(input, envp);
		free(input);
	}
	return (0);
}
