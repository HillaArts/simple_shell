#include "shell.h"
/**
 * execute_command - Function that executes a command in a child process.
 * @input: The command to be executed.
 * @envp: An array of environment variable strings.
 */
void execute_command(char *input, char **envp)
{
    char *command_path = get_command_path(input);

    if (command_path == NULL)
    {
        /* Handle the case when the command is not found */
        write(STDERR_FILENO, "Error: Command not found\n", sizeof("Error: Command not found\n") - 1);
        write(STDERR_FILENO, input, _strlen(input));
        write(STDERR_FILENO, "\n", 1);
    }
    else
    {
        if (is_builtin_command(input))
        {
            execute_builtin_command(input, envp);
        }
        else
        {
            execute_external_command(input, envp, command_path);
        }
    }
}
