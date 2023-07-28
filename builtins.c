#include "main.h"

/**
* printenv - prints current environment
* Return: none
*/

void printenv(void)
{
	int i = 0;
	char **env = environ;
	for (i = 0; env[i] != NULL; i++)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
	}
}

/**
* contains_builtin - check if a builtin command was entered
* @arg: command
* Return: 1 or 0
*/

int contains_builtin(char **arg)
{
	int i;
	char *argp = (char *) arg;
	char *builtins[] = {
		"cd",
		"env",
		"exit"
	};

	for (i = 0; i < 3; i++)
	{
		if (argp == builtins[i])
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}

	return (-1);
}

/**
* path_exists - checks if a path exists
* @path: path
* Return: 1 or 0
*/

int path_exists(char *path)
{
	struct stat info;

	if (stat(path, &info) != -1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
* cd - changes a working directory
* @args: directory
* Return: none
*/

void cd(char **args)
{
	char *arg = (char *) args;

	if (!args)
	{
		perror("Too few arguments \n");
	}

	if (path_exists(arg) == 1)
	{
		chdir(arg);
	}
	else
	{
		perror("Directory does not exist\n");
	}
}

/**
* exit_shell - exits the shell
* @arg: exit code
* Return: none
*/

void exit_shell(int arg)
{
	if (arg == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (arg == 1)
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		exit(arg);
	}

}
