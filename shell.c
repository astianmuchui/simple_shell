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
	char cwd_buff[1024], *argv[1024], *command;
	int arg_c, i;
	char path[] = "/bin/";
	
	
	getcwd(cwd_buff, sizeof(cwd_buff));



	while (1)
	{
		if (isatty(STDIN_FILENO)) /* Check whether file descriptor refers to a terminal or not */
		{
			printf("%s: $ ",cwd_buff);
			read = getline(&line, &len, stdin);

			if (!read)
			{
				printf("Error: Failed to read line\n");

				return (-1);
			}

			/* Use strtok to create an array of strings */
			
			arg_c = arg_count(line);
			
			for (i = 0; i < arg_c; i++)
			{
				argv[i] = _strtok(line, " ");
			}


			/* We need to concatenate path[] with the first 
				commandline argument since it is a binary */
			command = argv[0];


			strcat(path, command);



			/* printf(" Args: %d, 1st Command:  %s", arg_c ,path); */

			/* Reset commands and path to null */

			for (i = 0; i < arg_c; i++)
			{
				argv[i] = NULL; /* clear array to prevent re-execution */
			}

			path[0] = '\0'; /* Null it out to prevent conactenation  */

		}

	}


		free(line);

		return (0);
}
