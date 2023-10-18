#include "shell.h"
/**
 * _env - function that prints all environmental variables
 * @env: The pointer to environmental variables
 */
void _env(char **env)
{
	size_t i = 0;

	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
