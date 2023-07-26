#include "main.h"

/**
* _realloc - reallocates a memory block using malloc and free
* @buffer: pointer to the memory previously allocated
* @size: size in bytes of the allocated space for ptr
* Return: pointer to the newly allocated memory
*/

void *_realloc(void *buffer, size_t size)
{
	size_t old_size = 64, cp_size;
	void *new_buffer;

	/* If the buffer is null, allocate memory of size new_size */
	if (buffer == NULL)
	{
		return (malloc(size));
	}

	if (size == 0)
	{
		free(buffer);
		return (NULL);
	}
	/* New buffer size */
	new_buffer = malloc(size);

	if (new_buffer == NULL)
	{
		return (NULL);
	}

	/* Copy the data from the old buffer to the new buffer */
	cp_size = (old_size < size) ? old_size : size;
	memcpy(new_buffer, buffer, cp_size);

	free(buffer);

	return (new_buffer);
}
