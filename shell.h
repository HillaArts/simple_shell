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

void command_shell(char *buff, char **av, char **env, int cycles);
void prompt(void);
void _EOF(char *buff);
void _handle(int signals);
void createchild(char **command, char *name, char **env, int cycles);
int my_atoi(char *s);
char *my_strcat(char *dest, const char *src);
char *my_strcpy(char *dest, const char *src);
unsigned int my_strlen(const char *s);
int my_strcmp(const char *s1, const char *s2);
void _env(char **env);
void my_fprintf(FILE *stream, const char *format, ...);
void execute_command(char **command, char *name, char **env, int cycles);
void find_command(char **env, char **command, char *name, int cycles);
char **my_getpath(char **env, char **command);
pid_t getpid(void);
void printenv(char **env);
void free_exit(char **command);
void _free(char **command);
#endif
