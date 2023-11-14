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
