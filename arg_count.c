#include "main.h"

/**
 * arg_count - counts arguments seperated by spaces
 * @str: string
 * Return: number of arguments
*/

int arg_count(char *str)
{
    int i = 0, count = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ' ')
            count++;
        i++;
    }
    return (count + 1);
}