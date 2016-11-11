#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../shell.h"

void check_and_execute_inbuilt (char **argv, int argc) {
    if (strcmp (argv[0], "cd") == 0) {
        inbuilt_cd (argv, argc);
        exit (EXIT_SUCCESS);
    } else if (strcmp (argv[0], "echo") == 0) {
        inbuilt_echo (argv, argc);
        exit (EXIT_SUCCESS);
    } else if (strcmp (argv[0], "fg") == 0) {
        inbuilt_fg (argv, argc);
        exit (EXIT_SUCCESS);
    } else if (strcmp (argv[0], "jobs") == 0) {
        inbuilt_jobs (argv, argc);
        exit (EXIT_SUCCESS);
    } else if (strcmp (argv[0], "killallbg") == 0) {
        inbuilt_killallbg (argv, argc);
        exit (EXIT_SUCCESS);
    } else if (strcmp (argv[0], "pwd") == 0) {
        inbuilt_pwd (argv, argc);
        exit (EXIT_SUCCESS);
    } else if (strcmp (argv[0], "pinfo") == 0) {
        inbuilt_pinfo (argv, argc);
        exit (EXIT_SUCCESS);
    } else if (strcmp (argv[0], "sendsig") == 0) {
        inbuilt_sendsig (argv, argc);
        exit (EXIT_SUCCESS);
    }
}
