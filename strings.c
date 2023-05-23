#include "main.h"

/**
* _count - count the elems in an array
* @array: array
* Return: pointer to array count
*/

int *_count(char **array)
{
	int index, *count = 0;

	for (index = 0; *array[index] != '\0'; index++)
	{
		count++;
	}

	return (count);
}


/**
 * _strlen - count string length
 * @string: string to count
 * Return: number
*/

int _strlen(char *string)
{
	int i, count = 0;

	for (i = 0; string[i] != '\0'; i++)
	{
		count++;		
	}

	return (count);
}

/**
 * binary_search - search binaries array
 * @binaries: binaries array
 * @target: binaries to look for
 * Return: 1 or 0
*/

int binary_search(char** binaries, const char* target)
{
    int i;

    for (i = 0; binaries[i] != NULL; i++)
	{
		
        if (_strcmp(binaries[i], target) == 0)
		{
            return (1);
        }

		free(binaries[i]);
    }

	free(binaries);
    return (0);
}

/**
 * _strcmp - compare strings
 * @s1: first string
 * @s2: second sring
 * Return: 1 or -1 or 0
*/

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 > *s2)
		{
			return (1);
		}
		else if (*s1 < *s2)
		{
			return (-1);
		}
		s1++;
		s2++;
	}

	if (*s1 == '\0' && *s2 == '\0')
	{
		return (0);
	}
	else if (*s1 == '\0')
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}
