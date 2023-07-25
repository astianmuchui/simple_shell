#include "main.h"

/**
 * _exec_ - execute command
 * @args: arguments
 * Return: -1
 */
int _exec_(char **args)
{
	pid_t pid;
	int status;
	char **envp;

	if (args[0] == NULL)
		return (-1);
	pid = fork();

	if (pid == 0)
	{
		if (_cmd_isvalid(args[0])) /* Validate Command */
	}	
			envp = returnenv();

			if (execve(joinPath(BIN, *args), args, envp) == -1)
				perror("Unable to execute");
		}
	}
	else if (pid < 0)
	{
		perror("errors in forking.\n");
	}

	else
	{
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
		{
			waitpid(pid, &status, WUNTRACED);
		}
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
