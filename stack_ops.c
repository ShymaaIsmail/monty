#include "monty.h"

/**
* push - push
* @stack: stack
* @line_number: line_number
*/
void push(stack_t **stack, unsigned int line_number)
{
	printf("%d\n", shared_value.n);
	if (stack != NULL)
	{
		printf("s %d\n", line_number);
	}
}
/**
* pall - pall
* @stack: stack
* @line_number: line_number
*/
void pall(stack_t **stack, unsigned int line_number)
{
	if (stack != NULL)
	{
		printf("%d", line_number);
	}
}
/**
* pint - pint
* @stack: stack
* @line_number: line_number
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack != NULL)
	{
		printf("%d", line_number);
	}
}
/**
* pop - pop
* @stack: stack
* @line_number: line_number
*/
void pop(stack_t **stack, unsigned int line_number)
{
	if (stack != NULL)
	{
		printf("%d", line_number);
	}
}
