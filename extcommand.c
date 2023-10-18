#include "shell.h"

/**
 * execute_external_command - Function to execute external commands.
 * @input: The command to be executed.
 * @envp: An array of environment variable strings.
 * @command_path: The full path to the external command.
 */
void execute_external_command(char *input, char **envp, char *command_path)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        error_fork();
    }

    if (child_pid == 0)
    {
        char *args[100];
        int arg_count = 0;
        int i = 0;

        /* Parse the input command into arguments */
        while (input[i] != '\0' && arg_count < 100)
        {
            while (input[i] == ' ' || input[i] == '\t')
            {
                i++;
            }
            args[arg_count] = &input[i];
            arg_count++;
            while (input[i] != '\0' && input[i] != ' ' && input[i] != '\t')
            {
                i++;
            }
            if (input[i] != '\0')
            {
                input[i] = '\0';
                i++;
            }
        }
        args[arg_count] = NULL;

        /* Execute the external command */
        if (execve(command_path, args, envp) == -1)
        {
            error_execve();
        }
    }
    else
    {
        waitpid(child_pid, &status, 0);
        if (WIFEXITED(status) || WIFSIGNALED(status))
        {
            /* Handle exit status or termination by signal */
        }
        free(command_path);
    }
}

