#include "monty.h"

stack_t shared_value = {0, NULL, NULL};
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
	if (line[1] != NULL)
	{
		shared_value.n = string_to_integer(line[1]);
	}
	while (opcode_index < 4)
	{
		instructions[opcode_index].f(stack, line_number);
		is_handeled_opcode = 1;
		break;
	}
	if (!is_handeled_opcode)
	{
		print_monty_error(INVALID_OPCODE, 2, line_number, opcode);
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
	int exit_code = EXIT_SUCCESS;
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
