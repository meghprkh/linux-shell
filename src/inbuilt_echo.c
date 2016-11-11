#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../shell.h"

void inbuilt_echo (char **argv, int argc) {
    int i;
    for (i = 1; i < argc - 1; i++) printf("%s ", argv[i]);
    printf("%s\n", argv[i]);
}
