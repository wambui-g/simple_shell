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
void shell_non_interactive(void);

/* shell_interactive.c */
char *read_line(void);
char **parse_line(char *input);
void exec_cmd(char *cmd);

/* execute_args */
int new_process(char **args);
void handle_path(char **args);

/* shell_no_interactive */
char *read_stream(void);
/* char **split_line(char *line) */

/*---Builtin func---*/
int own_cd(char **args);
int own_exit(char **args);
int own_env(char **args);
int own_help(char **args);

#endif
