#include "shell.h"
/**
 * getpid -  function that gets the process id
 * Return: pid
 */
pid_t getpid(void)
{
	pid_t pid = getpid();

	return (pid);
}
/**
 * printenv - function that prints all enviromental variables
 * @env: pointer to enviromental variables
 */
void printenv(char **env)
{
	size_t i = 0;
	size_t len = 0;

	while (env[i])
	{
		len = my_strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
