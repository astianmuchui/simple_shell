#include "main.h"

/**
* main - get line
* Return: 0
*/

int main(void)
{

	char *line = NULL;

	size_t len = 0;
	ssize_t read;

	printf("$ ");

	read = getline(&line, &len, stdin);

	if (read == -1)
	{
		printf("Error: Failed to read line\n");

		return (1);
	}

	printf("You entered: %s", line);

	free(line);

	return (0);

}
