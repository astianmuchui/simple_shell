#include "main.h"

/**
 * _count - count the number of elements in an array
 * @array: array to count
 * Return: pointer to total number
 */

int *(_count) (char **array)
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
    return count_ptr;
}

/**
 * main - entry point
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 * Return: always 0
 */

int main(int ac, char **av)
{
    int *arr_count = _count(av);

    if (*arr_count == ac) /* Confirms that the above function pointer works */
    {
        int j = 0;

        while (j < *arr_count)
        {
            printf("%s\n",av[j]);
            j++;
        }
    }


    free(arr_count); 
    return 0;
}
