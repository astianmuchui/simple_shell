#include "main.h"

/**
 * _binarypath - return an array of all directories in path
 * Return: Array
*/

char **_binarypath(void)
{
    char** binaries = malloc(MAX_BINARIES * sizeof(char*));
    int count = 0;

    DIR* dir = opendir("/bin");
    if (dir == NULL) {
        perror("Failed to open directory");
        return NULL;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            binaries[count] = strdup(entry->d_name);
            count++;
            if (count >= MAX_BINARIES) {
                printf("Maximum number of binaries reached. Some entries may be omitted.\n");
                break;
            }
        }
    }

    closedir(dir);
    binaries[count] = NULL;  // Add NULL terminator to mark the end of the array

    return binaries;
}

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

int main(void)
{
	char cmd[] = "chmod u+x .";
	char **array, *chmod;
	int status, *arr_count, i;
	int argc = arg_count(cmd);
	printf("%d args \n", argc);
	
	chmod = "chmod";
	if(in_arr(*chmod, cmd) == 1)
	{
		printf("Chmod present :) \n");
	}

	array = _binarypath();

	arr_count = _count(array);

	for (i = 0; i < *arr_count; i++)
	{
		printf("[%d] %s \n", i, array[i]);
	}


}