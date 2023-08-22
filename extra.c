#include "monty.h"

/**
* mod - computes the modulus of the top two elements of the stack
* @stack: pointer to the stack
* @line_number: line number
* Return: void
*/

void mod(stack_t **stack, unsigned int line_number)
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
		tmp->next->n %= tmp->n;
		*stack = (*stack)->next;
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
* pchar - prints the char at the top of the stack
* @stack: pointer to the stack
* @line_number: line number
* Return: void
*/

void pchar(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack)
	{
		if ((*stack)->n >= 0 && (*stack)->n <= 127)
			printf("%c\n", (*stack)->n);
		else
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
* pstr - prints the string starting at the top of the stack
* @stack: pointer to the stack
* @line_number: line number
* Return: void
*/

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;

	while (tmp)
	{
		if (tmp->n >= 0 && tmp->n <= 127)
			printf("%c", tmp->n);
		else
			break;
		tmp = tmp->next;
	}
	printf("\n");
}

/**
* rotl - rotates the stack to the top
* @stack: pointer to the stack
* @line_number: line number
* Return: void
*/

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int tmp_n;

	(void)line_number;

	if (*stack && (*stack)->next)
	{
		tmp_n = tmp->n;
		while (tmp->next)
		{
			tmp->n = tmp->next->n;
			tmp = tmp->next;
		}
		tmp->n = tmp_n;
	}
}
