#ifndef GLOBAL_HEADER
#define GLOBAL_HEADER

#define HSH_TOK_BUFSIZE 64
#define HSH_TOK_DELIM " \t\r\n\a"

/* where each function comes from */

#include <sys/wait.h>/* waitpid() and associated macros */
/*#include <sys/types.h>  pid_t */
#include <unistd.h>/* chdir(), fork(), exec(), pid_t */
/* malloc(), realloc(), free() , exit(), execvp(),EXIT_SUCCESS, EXIT_FAILURE */
#include <stdlib.h>
#include <stdio.h> /* fprintf(), printf(), stderr, getchar(), perror() */
#include <string.h> /* strcmp(), strtok() */

/* Function Declarations for builtin shell commands: */
int hsh_cd(char **args);
int hsh_help(char **args);
int hsh_exit(char **args);

int hsh_num_builtins(void);
int hsh_launch(char **args);
int hsh_execute(char **args);
char *hsh_read_line(void);
char **hsh_split_line(char *line);
void hsh_loop(void);

#endif
