#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

pid_t _process_id(void);
pid_t _process_ppid(void);
int *(_count) (char **array);
ssize_t c_getline(char **buffer, size_t *n, FILE *stream);

#endif
