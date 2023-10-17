#include "shell.h"
/**
 * execute_command - function that executes a command in a child process.
 * @input: The command to be executed.
 * @envp: An array of environment variable strings.
 */
void execute_command(char *input, char **envp)
{
        pid_t child_pid;
        int status;
        char error_message[] = "Error: Command not found 0\n";
        char error_message_signal[] = "Error: Command terminated by signal 0\n";
        char *command_path = get_command_path(input);

        if (command_path == NULL)
        {
                write(STDERR_FILENO, "Error: Command not found\n", sizeof("Error: Command not found\n") - 1);
                write(STDERR_FILENO, input, _strlen(input));
                write(STDERR_FILENO, "\n", 1);
                free(command_path);
                return;
        }
        child_pid = fork();

        if (child_pid == -1)
        {
                char error[] = "Error: fork\n";
                write(STDERR_FILENO, error, sizeof(error) - 1);
                free(command_path);
                exit(EXIT_FAILURE);
        }

        if (child_pid == 0)
        {
                char *args[100];
                int arg_count = 0;
                int i = 0;
                char *command = NULL;

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
        command = args[0];

        if (my_strcmp(input, "env") == 0)
        {
                char **env = envp;
                while (*env != NULL)
                {
                        write(STDOUT_FILENO, *env, _strlen(*env));
                        write(STDOUT_FILENO, "\n", 1);
                        env++;
                }
                free(command_path);
                exit(EXIT_SUCCESS);
        } else if (my_strcmp(input, "ls") == 0 || my_strcmp(input, "/bin/ls") == 0)
        {
                char *ls_args[] = {"/bin/ls", NULL};
                execve(ls_args[0], ls_args, envp);
                write(STDERR_FILENO, "Error: execve\n", sizeof("Error: execve\n") - 1);
                free(command_path);
                exit(EXIT_FAILURE);
        }

        if (execve(command, args, envp) == -1)
        {
                write(STDERR_FILENO, "Error: No such file or directory\n", sizeof("Error: No such file or directory\n") - 1);
                free(command_path);
                exit(EXIT_FAILURE);
        }
        }
        else {
        waitpid(child_pid, &status, 0);
        if (WIFEXITED(status)) {
        int exit_status = WEXITSTATUS(status);
        if (exit_status != 0) {
        error_message[32] = '0' + exit_status % 10;
        error_message[31] = '0' + (exit_status / 10) % 10;
        write(STDERR_FILENO, error_message, sizeof(error_message) - 1);
        }
        } else if (WIFSIGNALED(status)) {
        int signal_code = WTERMSIG(status);
        error_message_signal[30] = '0' + signal_code % 10;
        write(STDERR_FILENO, error_message_signal, sizeof(error_message_signal) - 1);
        }
        free(command_path);
        }
}
