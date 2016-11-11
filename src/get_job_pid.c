#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../shell.h"

int get_job_pid (int jobid) {
    int i, j = 0;
    for (i = 0; i < 32767 && j != jobid; i++)
        if (bg_processes[bg_order[i]]) j++;
    if (i == 32767) return -1;
    return bg_order[i-1];
}
