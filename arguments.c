#include "main.h"


/**
* _get_cmd_ - get command from stdin
* Return: char ptr
*/

char *_get_cmd_(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t characters;

	write(STDIN_FILENO, "($) ", 4);
	characters = getline(&line, &bufsize, stdin);

	if (characters == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline error");
			exit(EXIT_FAILURE);
		}
	}

	return (line);
}

/**
 * getArgs - get arguments from command line
 * @line: command line
 * Return: char ptr
*/

char **getArgs(char *line)
{
	int buffer_size = 64, i = 0;

	char *token, **args = malloc(buffer_size * sizeof(char *));

	if (!args)
	{
		fprintf(stderr, "Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	token = _strtok(line, DELIM); /* Replace this with custom strtok later */

	while (token != NULL)
	{
		if (token[0] == '#')
		{
			break;
		}

		args[i] = token;
		i++;

		if (i >= buffer_size)
		{
			buffer_size += 64;
			args = _realloc(args, buffer_size * sizeof(char *));
			/* Replace this with custom realloc later */

			if (!args)
			{
				fprintf(stderr, "Unable to allocate memory\n");
				exit(EXIT_FAILURE);
			}
		}

		token = _strtok(NULL, DELIM);
	}

	args[i] = NULL;
	return (args);
}
