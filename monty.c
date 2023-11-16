#include "monty.h"

/**
* main - main (the start point of execute program)
* @ac: args counter
* @argv: pointer to 2d array for passed args
* Return: integer
*/
int main(int ac, char **argv)
{
	int exit_code = EXIT_SUCCESS;

	if (ac == 2)
	{
		exit_code = read_file(argv);
	}
	else
	{
		print_monty_error(USAGE, 0);
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
	stack_t **stack = initialize_empty_stack();

	if (lines != NULL)
	{
		for (line_index = 0; line_index < (unsigned int)shared_value.rows_count;
							line_index++)
		{
			if (*lines[line_index] != NULL)
			{
				exit_code = process_line(stack, lines[line_index], line_index + 1);
			}
			if (exit_code != EXIT_SUCCESS)
			{
				break;
			}
		}
		free_all_lines(lines);
	}
	return (exit_code);
}
