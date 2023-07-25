#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <limits.h>
#include <errno.h>
#include <signal.h>


#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define _GNU_SOURCE
#define PATH getenv("PATH")
#define PWD getenv("PWD")
#define BIN "/bin"

extern char **environ;

void interactive(void);
char *_get_cmd_(void);

char **getArgs(char *line);
int _exec_(char **args);

int _str_contains(char **needle, char **haystack);
void shellNotInteractive(int ac, char **av);
char *joinPath(char *dir, char *file);

int _cmd_isvalid(char *cmd);
int _strlen(char *string);
int *_count(char **array);

char *_strtok(char *str, const char *delim);
char *eliminateWhitespaces(char *token);

void *_realloc(void *buffer, size_t size);
void printenv(void);

int contains_builtin(char **arg);
void cd(char **args);

char **returnenv(void);

#endif
