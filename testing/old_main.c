include "shell.h"


/**
 * main - simple shell
 *
 * Return: 0 for  success
 */
int main(void)
{
        char input[MAX_INPUT_LENGTH];
        char prompt[] = "$ ";
        size_t prompt_length = sizeof(prompt) - 1;

        while (1)
        {
                write(STDOUT_FILENO, prompt, prompt_length);
                ssize_t input_length = read(STDIN_FILENO, input, sizeof(input));

                if (input_length == 0)
                        break;

                if (input_length == -1)
                {
                        perror("Read failed\n");
                        break;
                }
                input[input_length - 1] = '\0';
                int inp_exit = (input_length == 5 && input[0] == 'e' && input[1] == 'x'
                                && input[2] == 'i' && input[3] == 't' && input[4] == '\0');
                if (inp_exit)
                        break;
                pid_t pid = fork();

                if (pid < 0)
                {
                        perror("Fork failure\n");
                }
                else if (pid == 0)
                {
                        char *const argv[] = {input, NULL};

                        execve(input, argv, NULL);

                        char err_msg[] = ": No such file or directory\n";

                        write(STDERR_FILENO, err_msg, sizeof(err_msg) - 1);
                        _exit(1);
                }
                else
                        wait(NULL);
        }
        return (0);
}
