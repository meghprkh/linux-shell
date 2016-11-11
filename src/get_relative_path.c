#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../shell.h"

char* get_relative_path (char *ucwd, char *from) {
    char *cwd = ucwd;
    while (*cwd == *from) {
        cwd++; from++;
    }
    char *pcwd;
    if (*(from-1) == '\0') {
        ucwd[0] = '~'; ucwd[1] = '\0';
        pcwd = ucwd;
    } else if (*from == '\0') {
        pcwd = cwd - 1;
        *pcwd = '~';
    } else pcwd = ucwd;
    return pcwd;
}
