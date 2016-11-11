#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../shell.h"

void inbuilt_cd (char **argv, int argc) {
    if (argc < 2) { chdir (homedir); return; }
    char ufpath[LIMIT];
    char *fpath = ufpath;
    if (argv[1][0] == '~') sprintf(fpath, "%s%s", homedir, &argv[1][1]);
    else fpath = argv[1];
    if (chdir (fpath) == -1) perror (fpath);
}
