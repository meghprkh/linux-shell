#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../shell.h"

void inbuilt_fg (char **argv, int argc) {
    int pid = get_job_pid(atoi(argv[1])), status, wpid;
    if (pid < 0) {
        printf ("Job %s doesnot exist!\n", argv[1]);
        return;
    }
    free (bg_processes[pid]); bg_processes[pid] = NULL;
    do {
        wpid = waitpid(pid, &status, WUNTRACED);
    } while (!(WIFEXITED(status) || WIFSIGNALED(status)));
}
