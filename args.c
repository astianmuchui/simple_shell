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
* main - get commandline arguments
* @av: Null terminated array of strings
* @ac: number of items in the @av array
* Return: always 0
*/

int main(int ac, char **av)
{
	int *arr_count = _count(av);

	printf("%d\n", *arr_count = ac);

	return (0);
}

