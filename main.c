#include "monty.h"

/**
 * main - Main function
 * @argc: Number of arguments.
 * @argv: Arguments
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	char *fileN = argv[1];

	if (argc == 2)
	{
		op_file(fileN);
		/*free_n();make this function to free nodes*/
	}
	else
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
}
