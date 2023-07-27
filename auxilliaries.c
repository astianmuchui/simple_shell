#include "main.h"

/**
* determinePath - determine the path of the file to exec
* @argv: the command that was actually entered
* Return: the path of the file to exec
*/

char *determine_path(char *argv)
{
	char *path;

	if (strstr(argv, (const char *) BIN))
	{
		path = argv;
	}

	if (access(argv, F_OK) == 0 && access(argv, X_OK) == 0)
		/* chmod a+x */
	{
		path = argv;
	}

	if (access(joinPath(BIN, argv),
				F_OK) == 0 && access(joinPath(BIN, argv), X_OK) == 0) /* chmod a+x */
	{
		path = joinPath(BIN, argv);
	}

	return (path);

}
