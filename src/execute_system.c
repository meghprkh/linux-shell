#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../shell.h"

int execute_system (char **argv, int argc, int input_fd, int output_fd) {
    if (argc == 0) return 0;

    pid_t pid, wpid;
    int status;

    int background = 0;
    if (argv[argc-1][0] == '&') {
        background = 1;
        free (argv[argc]);
        argv[--argc] = NULL;
    }

    pid = fork();
    if (pid > 0) {
        // Parent process
        if (input_fd >= 0) close (input_fd);
        if (output_fd >= 0) close (output_fd);
        if (!background) { // Not a background process
            do {
                wpid = waitpid(pid, &status, WUNTRACED);
            } while (!(WIFEXITED(status) || WIFSIGNALED(status)));
        } else {
            bg_order[bg_order_len++] = pid;
            bg_processes[pid] = malloc (LIMIT);
            strcpy (bg_processes[pid], argv[0]);
        }
    } else if (pid == 0) {
        // Child process
        if (input_fd >= 0) {
            dup2(input_fd, STDIN_FILENO);
            close(input_fd);
        }
        if (output_fd >= 0) {
            dup2(output_fd, STDOUT_FILENO);
            close(output_fd);
        }

        // Checks if its inbuilt, and if so executes the inbuilt and exits
        check_and_execute_inbuilt (argv, argc);

        if (execvp(argv[0], argv) == -1) {
            perror(argv[0]);
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("Forking error");
    }

    return 1;
}
