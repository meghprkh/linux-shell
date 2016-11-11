#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../shell.h"

void get_line(char *input) {
    fgets (input, LIMIT - 1, stdin);
    if (feof(stdin)) {
        printf("exit\n");
        exit (EXIT_SUCCESS);
    }
}
