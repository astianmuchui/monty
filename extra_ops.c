#include "monty.h"

/**
* rotr - rotates the stack to the bottom
* @stack: pointer to the stack
* @line_number: line number
* Return: void
*/

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int tmp_n;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp_n = tmp->n;
		while (tmp->prev)
		{
			tmp->n = tmp->prev->n;
			tmp = tmp->prev;
		}
		tmp->n = tmp_n;
	}
}

/**
* stack - sets the format of the data to a stack (LIFO)
* @stack: pointer to the stack
* @line_number: line number
* Return: void
*/

void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
* queue - sets the format of the data to a queue (FIFO)
* @stack: pointer to the stack
* @line_number: line number
* Return: void
*/

void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
* free_stack - frees a stack
* @stack: pointer to the stack
* Return: void
*/

void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
