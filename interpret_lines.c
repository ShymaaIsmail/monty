#include "monty.h"

stack_t shared_value = {0, NULL, NULL};



/**
 * handle_push_param - handle_push_param
 * @line: line
 * @line_number: line_number
 * Return: exit code
*/
int handle_push_param(char **line, unsigned int line_number)
{
	int *value;
	int exit_code = EXIT_SUCCESS;

	if (line != NULL && line[1] != NULL)
	{
		value = string_to_integer(line[1]);
		if (value == NULL)
		{
			print_monty_error(INVALID_INT, 1, line_number);
			exit_code = EXIT_FAILURE;
		}
		else
		{
			shared_value.n = *value;
		}
	}
	return (exit_code);
}
/**
 * process_line - process_line
 * @stack: stack
 * @line: line
 * @line_number: line_number
 * Return: int
*/
int process_line(stack_t **stack, char **line, unsigned int line_number)
{
	int exit_code = EXIT_SUCCESS;
	int opcode_index = 0, is_handeled_opcode = 0;
	char *opcode;
	instruction_t instructions[] = { {"push", push},
	{"pall", pall}, {"pint", pint}, {"pop", pop}
	};

	opcode = line[0];
	if (strcmp(opcode, "push") == 0)
	{
		exit_code = handle_push_param(line, line_number);
		if (exit_code != EXIT_SUCCESS)
		{
			return (exit_code);
		}
	}
	while (opcode_index < 4)
	{
		if (strcmp(opcode, instructions[opcode_index].opcode) == 0)
		{
			instructions[opcode_index].f(stack, line_number);
			is_handeled_opcode = 1;
			break;
		}
		opcode_index++;
	}
	if (!is_handeled_opcode)
	{
		print_monty_error(INVALID_OPCODE, 2, line_number, opcode);
		exit_code = EXIT_FAILURE;
	}
	return (exit_code);
}
/**
* interpret_lines - interpret_lines
* @lines: lines
* Return: int
*/
int interpret_lines(char ***lines)
{
	int exit_code = 0;
	unsigned int line_index;
	stack_t **stack = NULL;

	if (lines != NULL)
	{
		for (line_index = 0; lines[line_index] != NULL; line_index++)
		{
			exit_code = process_line(stack, lines[line_index], line_index + 1);
			if (exit_code != EXIT_SUCCESS)
			{
				break;
			}
		}
		free_all_lines(lines);
	}
	return (exit_code);
}
