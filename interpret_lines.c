#include "monty.h"
/**
* interpret_lines - interpret_lines
* @lines: lines
* Return: int
*/
int interpret_lines(char ***lines)
{
	int exit_code = EXIT_SUCCESS;
	unsigned int line_index;
	int node_value;
	char *opcode;
	stack_t **stack;

	if (lines != NULL)
	{
		for (line_index = 0; lines[line_index] != NULL; line_index++)
		{
			opcode = lines[line_index][0];
			node_value = lines[line_index][1];

		}
	}
	return (exit_code);
}
