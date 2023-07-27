#include "main.h"

/**
* interactive - execute shell in interactive mode
* Return: none
*/

void interactive(void)
{
	char *line, **args;
	int status = -1;

	do {
		line = _get_cmd_();
		args = getArgs(line);

		if (_strcmp(line, "exit") == 0)
		{
			free(line);
			free(args);
			exit(EXIT_SUCCESS);
		}

		if (_strcmp(line, "env") == 0)
		{
			printenv();
		}

		status = _exec_(args); /* Execute command */
		free(line); /* Free memory allocated to line */
		free(args); /* Free memory allocated to args */

		if (status == 0)
		{
			exit(status);
		}

	} while (status == -1);

}


/**
* shellNotInteractive - execute shell in non-interactive mode
* @ac: number of arguments
* @av: arguments
* Return: none
*/

void shellNotInteractive(int ac, char **av)
{
	/**
	* av[0] - program_name
	* av[1] - commandName
	* av[2] - av[ac] - commands to be executed
	*/

	int i = 0, status, j = 2;
	char **args;

	if (ac < 2)
	{
		/* Since no extra command is provided, use interactive mode */
		interactive();
	}

	else if (feof(stdin))
	{
		exit(EXIT_SUCCESS);
	}

	else if (ac > 2)
	{
		for (j = 2; j < ac; j++)
		{
			args = malloc(sizeof(char *) * ac);

			/**
			* set args index of i to argument vector index of j
			*/

			args[i] = av[j];
			i++;
		}

		while (!WIFEXITED(status) && !WIFSIGNALED(status)) /* Signal */
		{
			status = _exec_(args);
		}
	}
}

/**
* joinPath - join a directory path and a file name
* @dir: directory
* @file: file
* Return: char ptr
*/

char *joinPath(char *dir, char *file)
{
	char *path;
	int i = 0, j = 0, len1 = 0, len2 = 0;

	len1 = _strlen(dir);
	len2 = _strlen(file);

	path = malloc(sizeof(char) * (len1 + len2 + 2));

	if (!path)
	{
		perror("memory error");
		exit(EXIT_FAILURE);
	}

	while (dir[i] != '\0')
	{
		path[i] = dir[i];
		i++;
	}

	path[i] = '/';

	while (file[j] != '\0')
	{
		/* Append filename after the added slash */

		path[i + 1] = file[j];
		i++;
		j++;

	}

	path[i + 1] = '\0'; /* Add null terminator: found this necessary */

	return (path);
}

/**
* _cmd_isvalid - checks if command is valid by searching the PATH and PWD
* @cmd: command
* Return: 1 if valid, -1 if not
*/

int _cmd_isvalid(char *cmd)
{
	/* Check if the command is an executable in the current path */
	if (access(joinPath(PWD, cmd), F_OK) == 0)
	{
		/* The file also needs to have a+x permissions */

		if (access(joinPath(PWD, cmd), X_OK) == 0)
		{
			return (1);
		}

		else
		{
			return (-1);
		}
	}

	else if (access(joinPath(PATH, cmd), F_OK) == 0)
	{
		return (1);
	}

	return (-1);
}
