#include "main.h"

/**
* main - display prompt
* Return: always
*/

int main(void)
{

	char *line = NULL;

	size_t len = 0;

	size_t read;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			read = getline(&line, &len, stdin);

			if (!read)
			{
				printf("Error: Failed to read line\n");

				return (-1);
			}

			printf("You entered: %s", line);

		}

	}
		free(line);

		return (0);
	}
