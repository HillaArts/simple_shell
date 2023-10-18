#include "shell.h"

/**
 * execute_builtin_command - Function to execute built-in commands.
 * @command: The command to be executed.
 * @envp: An array of environment variable strings.
 */
void execute_builtin_command(char *command, char **envp)
{
    if (my_strcmp(command, "env") == 0)
    {
        char **env = envp;
        while (*env != NULL)
        {
            write(STDOUT_FILENO, *env, _strlen(*env));
            write(STDOUT_FILENO, "\n", 1);
            env++;
        }
        exit(EXIT_SUCCESS);
    }
    /* Handle other built-in commands here, if any */
}
