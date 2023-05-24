#include "main.h"

extern char **environ;

/**
 * handle_command - handles the input command
 * @commands: command
 * Return: 1 or -1
*/

int handle_command(char *command)
{
	char *ext = "exit";

	/* Make sure command is valid */

	if (validate_command(command) == 1)
	{
		/* Handle exit command */
		if (command == ext)
		{
			exit(1);
		}

		return (1);
	}

	else
	{
		perror("No such file or directory");
		exit(-1);
		return (-1);
	}



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

/**
 * arg_count - counts arguments seperated by spaces
 * @str: string
 * Return: number of arguments
*/

int arg_count(char *str)
{
    int i = 0, count = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ' ')
            count++;
        i++;
    }
    return (count + 1);
}

/*

int main(void)
{
	char cmd[] = "chmod u+x .";
	char **binaries, *chmod;
	int argc = arg_count(cmd);
	printf("%d args \n", argc);
	
	chmod = "chmod";
	if(in_arr(*chmod, cmd) == 1)
	{
		printf("Chmod present :) \n");
	}

	binaries = _binarypath();

	if (binary_search(binaries,chmod) == 1)
	{
		printf("Command Exists \n");
	}

}
*/