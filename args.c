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


