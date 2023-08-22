#include "monty.h"

/**
* swap - swaps the top two elements of the stack
* @stack: pointer to the stack
* @line_number: line number
* Return: void
*/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int tmp_n;

	(void) line_number;

	if (*stack && (*stack)->next)
	{
		tmp_n = tmp->n;
		tmp->n = tmp->next->n;
		tmp->next->n = tmp_n;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
* add - adds the top two elements of the stack
* @stack: pointer to the stack
* @line_number: line number
* Return: void
*/

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		tmp->next->n += tmp->n;
		*stack = (*stack)->next;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
* sub - subtracts the top two elements of the stack
* @stack: pointer to the stack
* @line_number: line number
* Return: void
*/

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		tmp->next->n -= tmp->n;
		*stack = (*stack)->next;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
* _div - divides the top two elements of the stack
* @stack: pointer to the stack
* @line_number: line number
* Return: void
*/

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		if (tmp->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		tmp->next->n /= tmp->n;
		*stack = (*stack)->next;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
* mul - multiplies the top two elements of the stack
* @stack: pointer to the stack
* @line_number: line number
* Return: void
*/

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		tmp->next->n *= tmp->n;
		*stack = (*stack)->next;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
