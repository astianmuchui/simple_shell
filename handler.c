#include "main.h"

/**
 * extract_bin - extract binary file called from command
 * @command: command parsed
 * @binary: buffer to store binary file name
 * Return: pointer to char
*/


void extract_bin(char *command, char *binary)
{
    int i = 0, j = 0;

    while (command[i] == ' ')
    {
        i++;
    }

    while (command[i] != ' ' && command[i] != '\0')
    {
        binary[j] = command[i];
        i++;
        j++;
    }

    binary[j] = '\0';
}

int validate_command(char *command)
{
    char binary[MAX_ARGUMENTS];
    char **binaries;
    extract_bin(command, binary);

    binaries = _binarypath();

    return (binary_search(binaries, binary));

}

int main(void)
{
	char *command = "nmcli -nlxa";
	char binary[100];

extractbin(command, binary);

printf("%s\n", binary);
return (0);
}

