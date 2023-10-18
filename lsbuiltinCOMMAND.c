#include "shell.h"

/**
 * is_builtin_command - Check if the given input is a built-in command.
 * @input: The command to check.
 * Return: 1 if it's a built-in command, 0 otherwise.
 */
int is_builtin_command(char *input)
{
    if (my_strcmp(input, "env") == 0 || my_strcmp(input, "ls") == 0)
    {
        return 1; /* It's a built-in command */
    }
    return 0; /* It's not a built-in command */
}
