#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../shell.h"

void inbuilt_killallbg (char **argv, int argc) {
    union sigval sval;
    sval.sival_int = 1;
    int i;
    for (i = 0; i < 32768; i++) {
        if (bg_processes[bg_order[i]])
            sigqueue(bg_order[i], SIGKILL, sval);
    }
}
