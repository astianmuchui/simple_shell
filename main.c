#include "main.h"

/**
* main - execute shell
* @ac: number of arguments
* @av: arguments
* Return: 0 always
*/

int main(int ac, char **av)
{
	if (isatty(STDIN_FILENO))
	{
		interactive();
	}
	else
	{
		shellNotInteractive(ac, av);
	}
	return (0);
}
