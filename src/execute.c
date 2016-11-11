#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../shell.h"

void execute (char **argv, int argc, int input_fd, int output_fd) {
    if (argc == 0) return;
    else if (strcmp (argv[0], "quit") == 0 || strcmp (argv[0], "exit") == 0)
        exit (EXIT_SUCCESS);
    else execute_system (argv, argc, input_fd, output_fd);
}
