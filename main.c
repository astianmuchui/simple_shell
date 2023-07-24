#include "main.h"
/**
 * A simple unix shell in C
 * Mixed version
 * By Seb & Brenda
*/


/**
 * main - execute shell
 * @argc: number of arguments
 * @argv: arguments
 * @env: environment
 * Return: 0 always
*/



int main(int ac, char **av)
{

        if (isatty(STDIN_FILENO))
                interactive();
        else
                shellNotInteractive(ac, av);

        return (0);
}