#include "monty.h"

/**
* push - pushes an element to the stack
* @stack: pointer to the stack
* @line_number: line number
* Return: void
*/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	(void) line_number; /* Typecast */

	new_node = (stack_t *) malloc(sizeof(stack_t));

	if (!new_node)
	{
		/* Memory error */
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = data_t; /* Assign data */
	new_node->prev = NULL; /* No prev since it is at the top */
	new_node->next = *stack; /* Update to Point to the top of the stack */

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
* print_stack - prints all the elements of the stack
* @stack: pointer to the stack
* @line_number: line number
* Return: void
*/

void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;

	while (tmp) /* Traverse */
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
* peek - prints the top element of the stack
* @stack: pointer to the stack
* @line_number: line number
* Return: void
*/

void peek(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	if (*stack)
		fprintf(stdout, "%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't peek, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
* pop - removes the top element of the stack
* @stack: pointer to the stack
* @line_number: line number
* Return: void
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;

	if (*stack)
	{
		*stack = (*stack)->next;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
* nop - does nothing
* @stack: pointer to the stack
* @line_number: line number
* Return: void
*/

void nop(stack_t **stack, unsigned int line_number)
{
	/* Render void */
	(void)stack;
	(void)line_number;
}
