#include "main.h"

/**
* determinePath - determine the path of the file to exec
* @argv: the command that was actually entered
* Return: the path of the file to exec
*/

char *determine_path(char *argv)
{
	char *path, *joinedPath = joinPath(BIN, argv);

	if (strstr(argv, (const char *) BIN))
	{
		path = argv;
	}

	if (access(argv, F_OK) == 0 && access(argv, X_OK) == 0)
	{
		path = argv;
	}

	if (access(joinedPath, F_OK) == 0 && access(joinedPath, X_OK) == 0)
	{
		path = joinPath(BIN, argv);
	}
	else
	{
		free(path);
	}
	
	return (path);
}
