#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <limits.h>
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>

#define MAX_ARGUMENTS 1024
#define MAX_BINARIES 100

pid_t _process_id(void);
pid_t _process_ppid(void);

int *(_count) (char **array);
ssize_t c_getline(char **buffer, size_t *n, FILE *stream);

char *_strtok(char *str, const char *delim);
int arg_count(char *str);

int handle_command(char *command);
int execute(char *command);

int in_arr(char needle, char haystack[]);
char **_binarypath(void);

#endif
