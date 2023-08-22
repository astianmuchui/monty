#include "monty.h"

/**
* main - entry point for monty interpreter
* @argc: number of arguments
* @argv: array of arguments
* Return: always 0
*/

int main(int argc, char **argv)
{
	/* Check if a file was entered */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	else
	{
		/* Try to access the file first */
		if (open_stream(argv[1]) == 0)
		{
			/* Execute the lines in the file */
			exec_bytecode(argv[1]);
		}
		else
		{
			/** Push an error to the std output */
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	}

	return (EXIT_SUCCESS);
}
