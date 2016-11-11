#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../shell.h"

void prompt_print () {
    char hostname[LIMIT];
    gethostname (hostname, LIMIT - 1);
    char ucwd[LIMIT];
    getcwd (ucwd, LIMIT - 1);
    char *pcwd = get_relative_path (ucwd, homedir);
    printf ("<%s@%s:%s> ", getlogin(), hostname, pcwd);
}
