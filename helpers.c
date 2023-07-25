#include "main.h"

/**
* _str_contains - check if string contains substring
* @needle: substring
* @haystack: string
* Return: 1 or 0
*/

int _str_contains(char **needle, char **haystack)
{
	int i = 0, j = 0;

	while (needle[i] != NULL)
	{
		while (haystack[j] != NULL)
		{
			if (strcmp(needle[i], haystack[j]) == 0)
			{
				return (1);
			}

			j++;
		}

		i++;
	}

	return (0);
}



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
* eliminateWhitespaces - eliminate whitespaces from a string
* @token: string to be trimmed
* Return: ptr to trimmed string
*/

char *eliminateWhitespaces(char *token)
{
	int i, j;
	char *newToken;

	newToken = malloc(sizeof(char) * strlen(token));

	for (i = 0, j = 0; token[i] != '\0'; i++)
	{
		if (token[i] != ' ')
		{
			newToken[j] = token[i];
			j++;
		}
	}

	return (newToken);
}

/**
* _strtok - tokenizes a given string
* @str: string to be tokenized
* @delim: delimiters to be used
* Return: trimmed string
*/

char *_strtok(char *str, const char *delim)
{
	static char *save;
	char *token;
	int i, j;
	int len;

	/* Check if no string is provided */

	if (str == NULL)
	{
		str = save;
	}

	len = _strlen(str);

	for (i = 0; i < len; i++) /* loop through the string */
	{
		for (j = 0; delim[j] != '\0'; j++) /* loop through delimiter */
		{
			if (str[i] == delim[j])
			{
				/* Checks if delimiter is present in the string */
				str[i] = '\0'; /* Null terminator: End of current function call */
				save = &str[i + 1]; /* Pointer to next char: Next call goes from here */
				return (eliminateWhitespaces(str));
			}
		}
	}

	if (str == save) /* No more tokens left */
	{
		return (NULL);
	}

	token = str;
	save = NULL; /* Reset to Null */

	return (eliminateWhitespaces(token));
}
