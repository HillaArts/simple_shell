#ifndef _SHELL_H
#define _SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stddef.h>

#define BUFFER_SIZE 1024
#define MAX_INPUT 1024
#define PATH_BUFFER_SIZE 1024
#define MAX_ARGS 1024

extern char **environ;

char *get_command_path(char *command);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *_strcat(char *dest, const char *src);
int _atoi(char *str);
char *_strcpy(char *dest, const char *src);
char *my_getline(void);
int _strlen(const char *str);
void execute_env(void);
void execute_command(char *input, char **envp);
int my_strcmp(const char *str1, const char *str2);
int setenv_command(const char *variable, const char *value);
int unsetenv_command(const char *variable);
char **split_input(char *input);
char *_strdup(const char *s);
#endif /* _SHELL_H */
