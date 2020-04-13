#include "global_header.h"

/* List of builtin commands definitions and their corresponding functions. */
char *builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int (*builtin_func[]) (char **) = {
	&hsh_cd,
	&hsh_help,
	&hsh_exit
};

/**
 *hsh_num_builtins - calculates sizeof array containing builtins.
 *Return: total builtin array size.
 */
int hsh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 *hsh_execute - Execute shell built-in or launch program.
 *@args: Null terminated list of arguments.
 *
 *Return: 1 if the shell should continue running, 0 if it should terminate
 */
int hsh_execute(char **args)
{
	int i;

	if (args[0] == NULL)
	{
		/* An empty command was entered. */
		return (1);
	}

	for (i = 0; i < hsh_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((builtin_func[i])(args));
		}
	}

	return (hsh_launch(args));
}

/**
   @brief Bultin command: change directory.
   @param args List of args.  args[0] is "cd".  args[1] is the directory.
   @return Always returns 1, to continue executing.
*/
int hsh_cd(char **args)
{
	if (args[1] == NULL) {
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
	} else {
		if (chdir(args[1]) != 0) {
			perror("hsh");
		}
	}
	return 1;
}

/**
 *hsh_help - Builtin command: print help.
 *@args: List of args.  Not examined - now examined.
 *Return: Always returns 1, to continue executing.
 */
int hsh_help(char **args)
{
	int i;

	if (args[0] != NULL)
		printf("Andrew and Mohamed Shell\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");

	for (i = 0; i < hsh_num_builtins(); i++)
	{
		printf("  %s\n", builtin_str[i]);
	}

	printf("Use the man command for information on other programs.\n");
	return (1);
}

/**
 *hsh_exit - Builtin command: exit.
 *@args: List of args.  Not examined.
 *return: Always returns 0, to terminate execution.
 */
int hsh_exit(char **args)
{
	if (args[0] == NULL)
		return (0);
	else
		return (0);
}
