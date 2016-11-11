#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../shell.h"

void execute_with_pipes (char *input, int input_pipe) {
    int i, argc, append, pipefd[2];

    char *next_command = strstr(input, "|");
    if (next_command != NULL) {
        *next_command = '\0';
        next_command++;
        if (pipe(pipefd) < 0) perror("Unable to create pipes");
    }

    char **argv = malloc(LIMIT);
    char *input_redir = NULL, *output_redir = NULL;
    argc = parse_line (input, argv, &input_redir, &output_redir, &append);
    int input_fd = -1, output_fd = -1;

    if (input_pipe >= 0) input_fd = input_pipe;
    else if (input_redir != NULL) input_fd = open(input_redir, O_RDONLY, 0);

    if (next_command != NULL) output_fd = pipefd[1];
    else if (output_redir != NULL) {
        int flags = O_WRONLY | O_CREAT;
        if (append) flags |= O_APPEND;
        else flags |= O_TRUNC;
        output_fd = open(output_redir, flags, 0644);
    }

    execute (argv, argc, input_fd, output_fd);
    for (i = 0; i < argc; i++) free (argv[i]);
    free (input_redir);
    free (output_redir);
    free (argv);
    if (next_command != NULL) execute_with_pipes (next_command, pipefd[0]);
}
