#include "main.h"

/**
* main - display prompt
* Return: always
*/

int main(void)
{

if (isatty(STDIN_FILENO))
{
	char pwd[1024];

	char *line = NULL;

	size_t len = 0;

	size_t read;

	printf("$ ");
	read = getline(&line, &len, stdin);

	if (!read)
	{
		printf("Error: Failed to read line\n");

		return (-1);
	}

	printf("You entered: %s", line);

	free(line);

	}

	return (0);
}
