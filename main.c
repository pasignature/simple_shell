#include "global_header.h"

/**
 *Main - Main entry point to program.
 *@argc: Argument count.
 *@argv: Argument vector.
 *Return: status code
 */
int main(int argc, char *argv[])
{

	if (argc > 0 && argv[0] != NULL)
		/* Run loop non-interactively. */
		hsh_loop();
	else
		/* Run command loop. */
		hsh_loop();

	/* Perform any shutdown/cleanup. */
	return (EXIT_SUCCESS);
}
