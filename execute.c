#include "main.h"

/**
* _exec_ - execute command
* @args: arguments
* Return: -2
*/

int _exec_(char **args)
{
	pid_t pid;
	int status;
	char **envp;

	if (args[0] == NULL)
		return (-1);

	if (_cmd_isvalid(args[0])) /* Validate Command */
	{
		pid = fork();

		if (pid == 0)
		{
			envp = returnenv();

			if (execve(joinPath(BIN, *args), args, envp) == -1)
			{
				perror("Error executing command");
			}
			else
			{
				return (-1);
			}
		}
		else if (pid < 0)
		{
			perror("Could not fork a new process");
                }

		else
		{
			while (!WIFEXITED(status) && !WIFSIGNALED(status))
			{
				waitpid(pid, &status, WUNTRACED);
			}

			wait(NULL);
			interactive();
			return (-1);
		}
	}

	else
	{
		perror("Invalid command \n");
		interactive();
	}

	return (-1);
}

/**
* returnenv - returns environment variables
* Return: array
*/

char **returnenv(void)
{
	int envC = 0;
	char **env = environ;
	char **envp = malloc(sizeof(char *) * BUFSIZE);

	if (envp == NULL)
	{
		perror("Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (*env != NULL)
	{
		envp[envC] = *env;
		envC++;
		env++;
	}

	envp[envC] = NULL;

	return (envp);
}



/**
* _strcmp - compare strings
* @s1: first string
* @s2: second sring
* Return: 1 or -1 or 0
*/

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 > *s2)
		{
			return (1);
		}
		else if (*s1 < *s2)
		{
			return (-1);
		}
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (0);
	}
	else if (*s1 == '\0')
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}
