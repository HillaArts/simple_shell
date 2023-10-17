#include "shell.h"

/**
 * setenv_command - Initialize a new environment variable or
 * modify an existing one.
 * @variable: The name of the environment variable.
 * @value: The value to assign to the environment variable.
 * Return: 0 on success, -1 on failure.
 */
int setenv_command(const char *variable, const char *value)
{
	int ret;

	if (variable != NULL && value != NULL)
	{
		ret = setenv(variable, value, 1);
		if (ret == -1)
		{
			perror("setenv_command");
			return (-1);
		}
		return (0);
	}
	return (-1);
}

/**
 * unsetenv_command - Remove an environment variable.
 * @variable: The name of the environment variable to remove.
 * Return: 0 on success, -1 on failure.
 */
int unsetenv_command(const char *variable)
{
	int ret;

	if (variable != NULL)
	{
		ret = unsetenv(variable);
		if (ret == -1)
		{
			perror("unsetenv_command");
			return (-1);
		}
		return (0);
	}
	return (-1);
}

