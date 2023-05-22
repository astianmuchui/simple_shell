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
		if (isatty(STDIN_FILENO)) /* Check whether file descriptor refers to a terminal or not */		{
		{
			printf("($) ");
			read = getline(&line, &len, stdin);

			if (!read)
			{
				printf("Error: Could not read command \n");

				return (-1);
			}
			
			else if (handle_command(line) != -1) /* Command was read and binary exists  */
			{
				printf("We made it here \n");
				if (execute(line) == -1)
				{
					printf("Error: Could not execute command \n");

					return (-1);
				}

			}
		}

			
	}


	free(line);

	return (0);
}
}