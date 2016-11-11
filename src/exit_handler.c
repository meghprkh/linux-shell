#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "../shell.h"

void exit_handler (int sig) {
    pid_t pid;
    int status;
    pid = wait (&status);
    if (bg_processes[pid]) {
        printf ("\nprocess %s with pid %d exited ", bg_processes[pid], pid);
        if (WIFEXITED(status)) printf ("normally.\n");
        else printf ("with exit status %d.\n", WEXITSTATUS(status));
        free (bg_processes[pid]); bg_processes[pid] = NULL;
        prompt_print ();
        fflush (stdout);
    }
}
