#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>

#define MAX_INPUT_LENGTH 1024

void input_check(char *input, int interactive_mode);

#endif
