#include "main.h"


/**
 * validate_command - checks if command is in /bin
 * @command: command entered
 * Return: 1 or -1
*/

int validate_command(char *command)
{
    /* Tokenize string to obtain first command */
    char **binaries, *binary;

    binary = _strtok(command, " ");
    binaries = _binarypath();

    if (binary_search(binaries, binary) == 1)
    {
        return (1);
    }
    else
    {
        return (-1);
    }

    return (0);
}
