#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../shell.h"

void inbuilt_jobs (char **argv, int argc) {
    int i, j = 1;
    for (i = 0; i < 32768; i++) {
        if (bg_processes[bg_order[i]])
            printf("[%d] %s [%d]\n", j++, bg_processes[bg_order[i]], bg_order[i]);
    }
}
