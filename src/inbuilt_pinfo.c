#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../shell.h"

void inbuilt_pinfo (char **argv, int argc) {
    char upid[LIMIT]; char *pid;
    if (argc < 2) { sprintf(upid, "%d", getpid()); pid = upid; }
    else pid = argv[1];

    printf("pid -- %s\n", pid);

    int targc, i;
    char **targv = malloc (LIMIT);

    char statuscmd[LIMIT] = "ps -o state= -p ";
    strcat (statuscmd, pid);
    printf ("Process Status -- "); fflush(stdout);
    targc = parse_line (statuscmd, targv, NULL, NULL, NULL);
    execute_system (targv, targc, -1, -1);
    for (i = 0; i < targc; i++) free (targv[i]);

    char memcmd[LIMIT] = "ps -o vsz= -p ";
    strcat (memcmd, pid);
    printf ("Virtual Memory -- "); fflush(stdout);
    targc = parse_line (memcmd, targv, NULL, NULL, NULL);
    execute_system (targv, targc, -1, -1);
    for (i = 0; i < targc; i++) free (targv[i]);

    char exelink[LIMIT] = "/proc/", exepath[LIMIT] = "";
    strcat(exelink, pid);
    strcat(exelink, "/exe");
    int exepath_size = readlink(exelink, exepath, LIMIT - 1);
    exepath[exepath_size] = '\0';
    char *relexepath = get_relative_path (exepath, homedir);
    printf ("Executable Path -- %s\n", relexepath);

    free (targv);
}
