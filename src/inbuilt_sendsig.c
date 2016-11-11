#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../shell.h"

void inbuilt_sendsig (char **argv, int argc) {
    int pid = get_job_pid(atoi(argv[1]));
    if (pid < 0) {
        printf ("Job %s doesnot exist!\n", argv[1]);
        return;
    }
    int sig = atoi(argv[2]);
    union sigval sval;
    sval.sival_int = 1;
    sigqueue(pid, sig, sval);
}
