#include "main.h"

/**
 * in_arr - checks if a character is in an array
 * @needle: character to check
 * @haystack: array
 * Return: 1 or 0
 */

int in_arr(char needle, char haystack[])
{
    int i = 0;

    while (haystack[i] != '\0')
    {
        if (haystack[i] == needle)
            return (1);
        i++;
    }

    return (0);
}

