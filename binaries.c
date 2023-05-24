#include "main.h"

/**
 * _binarypath - return array of binaries in /bin
 * Return: Pointer to array[]
*/

char **_binarypath(void)
{

	char **binaries = malloc(MAX_BINARIES * sizeof(char *));
	int count = 0;
	struct dirent *entry;

	DIR *dir = opendir("/bin");

	if (dir == NULL)
	{
		perror("Failed to open directory");
		return (NULL);
	}


	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_type == DT_REG)
		{
			binaries[count] = strdup(entry->d_name);
			if (count >= MAX_BINARIES)
			count++;
			{
				printf("Maximum number of binaries reached. Some entries may be omitted.\n");
				break;
			}
		}
	}

	closedir(dir);
	binaries[count] = NULL;

	return (binaries);
}

/**
 * binCount - count binaries
 * Return: number of binaries
*/

int binCount(void)
{
	struct dirent *entry;

	char **binaries = malloc(MAX_BINARIES * sizeof(char *));

	int count = 0;
	DIR *dir = opendir("/bin");

	if (dir == NULL)
	{
		perror("Failed to open directory");
		return (-1);
	}


	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_type == DT_REG)
		{
			binaries[count] = strdup(entry->d_name);
			count++;
			if (count >= MAX_BINARIES)
			{
				printf("Maximum number of binaries reached.");
				break;
			}
		}
	}

	closedir(dir);
	binaries[count] = NULL;
	free(binaries);

	return (count);
}

/**
 * in_arr - checks if an element is in an array
 * @needle: element to check
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
