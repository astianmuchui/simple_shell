#include "main.h"

extern char **environ;

/**
 * handle_command - handles the input command
 * @commands: command
 * Return: 1 or -1
*/

int handle_command(char *command)
{
	char *buffer[1024], *binary,  arr, *binaries;
	int argc, i; /* number of arguments */

	argc = arg_count(command); /* Use custom strtok to create an array of strings */

	for (i = 0; i < argc; i++)
	{
		buffer[i] = _strtok(command, " ");
	}

	binary = buffer[0]; /* Since all commands must be in path */


	arr = _binarypath();
	binaries = &arr;

	if (in_arr(*binary, binaries) == -1) /* The command does not exist */
		return (-1);
	else
		return (1);

	return (0);
}


/**
 * execute - executes a command
 * Return: 1 or 0
*/


int execute(char *command)
{
	int argc, i;
	char *buffer[1024];
	pid_t child_p;
	char **envp = environ;


	argc = arg_count(command);

	for (i = 0; i < argc; i++)
	{
		buffer[i] = _strtok(command, " ");
	}

	child_p = fork();

	if (child_p == 0) /* child process */
	{
		execve(buffer[0], buffer, envp);
		perror("Error: Could not execute command \n");
		return (-1);
	}
	else if (child_p < 0) /* fork failed */
	{
		printf("Unable to create child process \n");
		return (-1);
	}
	else /* Parent process */
	{
		wait(0);
		return (1);
}
	}