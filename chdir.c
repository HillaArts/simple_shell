#include "shell.h"
/**
 * chdir - function that changes working directory
 * @path: new current working directory
 * Return: 1
 */
int chdir(const char *path)
{
	char *buff = NULL;
	size_t size = 1024;

	if (path == NULL)
	{
		path = getcwd(buff, size);
	}
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}
