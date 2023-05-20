#include "main.h"

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

