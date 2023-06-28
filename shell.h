#ifndef SHELL_H
#define SHELL_H

/*---LIBRARIES---*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/*---Macros---*/
#define TOK_DELIM " \t\r\n\a\""
extern char **environ;

/*---PROTOTYPES---*/
/* main.c */
void shell_interactive(void);

/* shell_interactive.c */
char *read_line(void);
char **parse_line(char *input);
int exec_cmd(char *cmd);

/* execute_args */
int new_process(char **args);
void handle_path(char **args);

#endif
