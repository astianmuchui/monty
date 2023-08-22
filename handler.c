#include "monty.h"

stack_t *top;
int data_t;

/**
* open_stream - checks if a file can be opened
* @filename: name of file
* Return: 0 if file can be opened, -1 if not
*/

int open_stream(char *filename)
{
	int filedes;

	filedes = open(filename, O_RDONLY);

	if (filedes == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (-1);
	}
	else
	{
		return (0);
	}

	close(filedes);
}

/**
* exec_bytecode - executes the instructions in a file
* @filename: name of file
* Return: void
*/

void exec_bytecode(char *filename)
{
	instruction_t opts[] = {
		{"push", push},
		{"pall", print_stack},
		{"pint", peek},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"queue", queue},
		{"stack", stack},
		{"rotr", rotr},
		{"rotl", rotl},
		{NULL, NULL}
	};

	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		return;
	}

	/* Open the file and execute line by line */
	perform_exec(file, opts);

	free_stack(&top);
	fclose(file);
}

/**
* perform_exec - executes the instructions in the file
* @file: file to read
* @opts: array of structs containing the instructions
* Return: void
*/

void perform_exec(FILE *file, instruction_t opts[])
{
	int i = 0, line_number = 0;
	char line[256], **args;

	while (fgets(line, sizeof(line), file))
	{
		if (line[0] == '\n' || strstr(line, "#")) /* escape */
		{
			line_number++;
			continue;
		}
		line_number++;
		args = get_token(line);
		if (args == NULL)
		{
			line_number++;
			continue;
		}
		for (i = 0; opts[i].opcode != NULL; i++)
		{
			if (strcmp(args[0], opts[i].opcode) == 0)
			{
				if (strcmp(args[0], "push") == 0)
				{
					data_t = atoi(args[1]);
					if (data_t == 0 && strcmp(args[1], "0") != 0)
					{
						fprintf(stderr, "L%d: usage: push integer\n", line_number);
						exit(EXIT_FAILURE);
					}
				}
				opts[i].f(&top, line_number);
				break;
			}
		}
		if (opts[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, args[0]);
			exit(EXIT_FAILURE);
		}
	}
}
