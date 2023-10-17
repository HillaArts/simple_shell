#include "shell.h"
/**
 * get_command_path - Search for the command in the PATH.
 * @command: The command to search in the PATH.
 * Return: The full path to the command if found, or NULL if not found.
 */
char *get_command_path(char *command)
{
        char *path = getenv("PATH");
        char path_buffer[PATH_BUFFER_SIZE];
        int token_start = 0;
        int i = 0;

        path_buffer[PATH_BUFFER_SIZE - 1] = '\0';
        while (path[i] != '\0' && i < PATH_BUFFER_SIZE - 1)
        {
                if (path[i] == ':')
        {
                path_buffer[i] = '\0';
                if (access(path_buffer + token_start, F_OK) == 0)
        {
                char *full_path = (char *)malloc(_strlen(path_buffer + token_start)
                        + _strlen(command) + 2);

                if (full_path == NULL)
                {
                        return (NULL);
                }
                _strcpy(full_path, path_buffer + token_start);
                _strcat(full_path, "/");
                _strcat(full_path, command);
                return (full_path);
        }
                token_start = i + 1;
        }
                else
                {
                        path_buffer[i] = path[i];
                }
                i++;
        }
        path_buffer[i] = '\0';
        if (access(path_buffer + token_start, F_OK) == 0)
        {
                char *full_path = (char *)malloc(_strlen(path_buffer + token_start)
                        + _strlen(command) + 2);

                if (full_path == NULL)
                {
                        return (NULL);
                }
                _strcpy(full_path, path_buffer + token_start);
                _strcat(full_path, "/");
                _strcat(full_path, command);
                return (full_path);
        }
        return (NULL);
}
