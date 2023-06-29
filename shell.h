#ifndef SHELL_H
#define SHELL_H

/*---LIBRARIES---*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <libgen.h>
#include <stddef.h>
#include <sys/types.h>

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
size_t _strlen(const char *str);
void error_handler(const char *prog_name, const char *arg);
int _strcmp(const char *str1, const char *str2);

#endif
