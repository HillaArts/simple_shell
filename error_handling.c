#include "shell.h"

/**
 * error_command_not_found - Handle "Command not found" error.
 * @input: The command that was not found.
 */
void error_command_not_found(char *input)
{
    write(STDERR_FILENO, "Error: Command not found\n", sizeof("Error: Command not found\n") - 1);
    write(STDERR_FILENO, input, _strlen(input));
    write(STDERR_FILENO, "\n", 1);
}

/**
 * error_fork - Handle fork error.
 */
void error_fork()
{
    char error[] = "Error: fork\n";
    write(STDERR_FILENO, error, sizeof(error) - 1);
    exit(EXIT_FAILURE);
}

/**
 * error_execve - Handle execve error.
 */
void error_execve()
{
    write(STDERR_FILENO, "Error: execve\n", sizeof("Error: execve\n") - 1);
    exit(EXIT_FAILURE);
}

/**
 * error_no_such_file - Handle "No such file or directory" error.
 */
void error_no_such_file()
{
    write(STDERR_FILENO, "Error: No such file or directory\n", sizeof("Error: No such file or directory\n") - 1);
    exit(EXIT_FAILURE);
}

