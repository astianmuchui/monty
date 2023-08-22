#include "monty.h"

/**
* _memcpy - copies memory
* @dest: destination area
* @src: source memory
* @n: no of bytes to copy
* Return: *dest
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i]; /* Duplicate */
	}

	return (dest);
}

/**
* _realloc - reallocates a memory block
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

/**
* get_token - splits a string into tokens
* @line: string to split
* Return: array of tokens
*/

char **get_token(char *line)
{
	int buffer_size = 64, i = 0;

	char *token, **args = malloc(buffer_size * sizeof(char *));

	if (!args)
	{
		fprintf(stderr, "Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIM);

	while (token != NULL)
	{
		args[i] = token;
		i++;

		if (i >= buffer_size)
		{
			buffer_size += 64;
			args = _realloc(args, buffer_size * sizeof(char *));

			if (!args)
			{
				fprintf(stderr, "Unable to allocate memory\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, DELIM);
	}

	free(token);
	args[i] = NULL;
	return (args);
}
