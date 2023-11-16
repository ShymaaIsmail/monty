#include "monty.h"


/**
* _div - _div
* @stack: stack
* @line_number: line_number
*/
void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_stack(stack);
		print_monty_error(FEW_DIV_NODES, 1, (int)line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *temp_first = *stack;
		stack_t *temp_second = (*stack)->next;

		if (temp_first->n == 0)
		{
			free_stack(stack);
			print_monty_error(DIV_BY_ZERO, 1, (int)line_number);
			exit(EXIT_FAILURE);
		}
		else
		{
			int result = temp_second->n / temp_first->n;

			pop(stack, line_number);
			(*stack)->n = result;
		}
	}
}
/**
* mul - mul
* @stack: stack
* @line_number: line_number
*/
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_stack(stack);
		print_monty_error(FEW_MUL_NODES, 1, (int)line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *temp_first = *stack;
		stack_t *temp_second = (*stack)->next;
		int result = temp_second->n * temp_first->n;

		pop(stack, line_number);
		(*stack)->n = result;
	}
}
/**
* mod - mod
* @stack: stack
* @line_number: line_number
*/
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_stack(stack);
		print_monty_error(FEW_MOD_NODES, 1, (int)line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *temp_first = *stack;
		stack_t *temp_second = (*stack)->next;

		if (temp_first->n == 0)
		{
			free_stack(stack);
			print_monty_error(DIV_BY_ZERO, 1, (int)line_number);
			exit(EXIT_FAILURE);
		}
		else
		{
			int result = temp_second->n % temp_first->n;

			pop(stack, line_number);
			(*stack)->n = result;
		}
	}
}
