#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../shell.h"
#define SKIP_EMPTY while (*input == ' ' || *input == '\t') input++

void put_word_in_string (char **input, char **output) {
    if (output != NULL) *output = malloc(LIMIT);
    int c;
    for (c = 0; **input != '\0' && **input != ' ' && **input != '\n'; (*input)++, c++) {
        if (output != NULL) (*output)[c] = **input;
        // printf("%c %c\n", **input, (*output)[c]);
    }
    if (output != NULL) (*output)[c] = '\0';
}

int parse_line (char *input, char **argv, char **input_redir, char **output_redir, int *append) {
    int c, argc = 0;
    while (*input == ' ' || *input == '\t') input++;
    if (*input == '\n') return 0;
    while (*input != '\0' && *input != '\n') {
        if (*input == '<') {
            input++;
            SKIP_EMPTY;
            put_word_in_string(&input, input_redir);
            SKIP_EMPTY;
        } else if (*input == '>') {
            input++;
            if (append) *append = 0;
            if (*input == '>') {
                if (append) *append = 1;
                input++;
            }
            SKIP_EMPTY;
            put_word_in_string(&input, output_redir);
            SKIP_EMPTY;
        } else {
            put_word_in_string(&input, &argv[argc]);
            SKIP_EMPTY;
            argc++;
        }
    }
    argv[argc] = NULL;
    return argc;
}
