#include "main.h"

/**
* printenv - prints current environment
* Return: none
*/

void printenv(void)
{
	char **env = environ;
	int i = 0;

	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
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
	char *builtins[] = {
		"cd",
		"env",
		"exit"
	};

	for (i = 0; builtins[i] != NULL; i++)
	{
		if (_str_contains(arg, (char **)builtins[i])) /* Typecast */
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
* cd - changes a working directory
* @args: directory
* Return: none
*/

void cd(char **args)
{
	DIR *dir;

	if (args == NULL)
	{
		perror("Please provide a directory\n");
	}

	/* Check if the directory actually exists */
	dir = opendir(*args);

	if (dir == NULL)
	{
		perror("Directory does not exist\n");
	}
	else
	{
		chdir(*args);
		closedir(dir);
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

