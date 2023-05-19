#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

pid_t _process_id(void);
pid_t _process_ppid(void);
int *(_count) (char **array);
ssize_t c_getline(char **buffer, size_t *n, FILE *stream);
char *_strtok(char *str, const char *delim);
int arg_count(char *str);
#endif
