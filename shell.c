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
		if (isatty(STDIN_FILENO)) /* Check whether file descriptor refers to a terminal or not */
		{
			printf("($) ");
			read = getline(&line, &len, stdin);

			if (!read)
			{
				return (-1);
			}
			
			if (handle_command(line) != -1)
			{
				printf("Hata siwes kusema mengi \n");
			}
		}
		
	}


	free(line);

	return (0);
}
