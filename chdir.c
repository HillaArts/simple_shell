#include "shell.h"
/**
 * chDIR - function that changes working directory
 * @path: new current working directory
 * Return: 1
 */
int chDIR(const char *path)
{
	char *buff = NULL;
	size_t size = 1024;

	if (path == NULL)
	{
		path = getcwd(buff, size);
	}
	if (chDIR(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}
