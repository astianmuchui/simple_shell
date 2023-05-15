#include "main.h"

/**
 * _count - count the number of elements in an array
 * @array: array to count
 * Return: pointer to total number
 */

int *_count(char **array)
{
	int count = 0;

	int *count_ptr = malloc(sizeof(int));

	if (count_ptr == NULL)
	{
		return (0);
	}

	while (*array != NULL)
	{
		count++;
		array++;
	}

	*count_ptr = count;
	return (count_ptr;)
}
