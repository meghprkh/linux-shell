#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shell.h"

void sigint_handler (int sig) {
    printf ("\n");
    prompt_print ();
    fflush (stdout);
}

int main () {
    bg_order_len = 0;
    signal(SIGCHLD, exit_handler);
    signal(SIGINT, sigint_handler);
    char uinput[LIMIT];
    getcwd (homedir, LIMIT - 1);
    while (1) {
        prompt_print ();
        get_line (uinput);
        char *input = strtok (uinput, ";");
        while (input) {
            execute_with_pipes (input, -1);
            input = strtok (NULL, ";");
        }
    }
    return 0;
}
