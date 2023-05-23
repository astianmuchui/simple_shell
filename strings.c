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

int binary_search(char** binaries, char* target)
{
	int buffer_count,i;

	buffer_count = binCount();

	for (i = 0; i < buffer_count; i++)
	{
		if (_strcmp(binaries[i], target))
		{
			return (1);
		}
		else
		{
			return (-1);
		}
	}

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


/**
* _strtok - tokenizes a given string
* @str: string to be tokenized
* @delim: delimiters to be used
* Return: pointer to next character
*/

char *_strtok(char *str, const char *delim)
{
	static char *save;
	char *token;
	int i, j;
	int len;

	if (str == NULL) /* Check if no string is provided */
	str = save;

	len = strlen(str);

	for (i = 0; i < len; i++) /* loop through the string */
	{
		for (j = 0; delim[j] != '\0'; j++) /* loop through delimiter */
		{
			if (str[i] == delim[j]) /* Checks if delimiter is present in the string */
			{
				str[i] = '\0'; /* Null terminator: End of current function call */
				save = &str[i + 1]; /* Pointer to next char: Next call goes from here */
				return (str);
			}
		}
	}
	if (str == save) /* No more tokens left */
		return (NULL);

	token = str;
	save = NULL; /* Reset to Null */

	return (token);
}

