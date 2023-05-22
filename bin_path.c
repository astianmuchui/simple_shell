#include "main.h"

/**
 * _binarypath - return an array of all directories in path
 * Return: Array
*/


char _binarypath(void)
{
	char *path = getenv("PATH");
	char **path_arr = malloc(sizeof(char *) * 1024);
	int i = 0;

	path_arr[i] = _strtok(path, ":");
	i++;

	while (path_arr[i - 1] != NULL)
	{
	path_arr[i] = _strtok(NULL, ":");
	i++;
	}

	return (**path_arr);
}