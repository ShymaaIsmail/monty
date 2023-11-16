#include "monty.h"

/**
* push - push
* @stack: stack
* @line_number: line_number
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = create_node(shared_value.n);
	stack_t *top = get_top_node(*stack);

	(void) line_number;
	if (*stack == NULL)
	{
		*stack = new_node;
		top = new_node;
	}
	else
	{
		top->next = new_node;
		new_node->prev = top;
		top = new_node;
	}
}
/**
* pall - pall
* @stack: stack
* @line_number: line_number
*/
void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (*stack != NULL)
	{
		stack_t *top = get_top_node(*stack);

		do {
			if (top != NULL)
			{
				char str[20];

				sprintf(str, "%d\n", top->n);
				write(STDOUT_FILENO, str, strlen(str));
				top = top->prev;
			}
		} while (top != NULL);
	}
}
/**
* pint - pint
* @stack: stack
* @line_number: line_number
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		print_monty_error(EMPTY_STACK, 1, (int)line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *top = get_top_node(*stack);
		char str[20];

		sprintf(str, "%d\n", top->n);
		write(STDOUT_FILENO, str, strlen(str));
	}
}
/**
* pop - pop
* @stack: stack
* @line_number: line_number
*/
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		print_monty_error(POP_EMPTY_STACK, 1, (int)line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *top = get_top_node(*stack);
		*stack = top->next;
		if (*stack != NULL)
		{
			(*stack)->prev = NULL;
		}
		free(top);
	}
}
