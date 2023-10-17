#include "shell.h"

/**
 * execute_env - Executes the "env" command to print environment variables.
 */
void execute_env(void)
{
	char *env_var = *environ;
	size_t len;

	while (env_var != NULL)
	{
		len = strlen(env_var);
		write(STDOUT_FILENO, env_var, len);
		write(STDOUT_FILENO, "\n", 1);
		env_var = *(++environ);
	}
}
