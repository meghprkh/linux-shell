#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../shell.h"

void inbuilt_pwd (char **argv, int argc) {
    char acwd[LIMIT];
    getcwd (acwd, LIMIT - 1);
    printf("%s\n", acwd);
}
