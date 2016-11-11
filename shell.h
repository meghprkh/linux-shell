#ifndef SHELL_H
#define SHELL_H

#define LIMIT 1024

char homedir[LIMIT];

char *bg_processes[32768];
int bg_order[32768];
int bg_order_len;

int get_job_pid (int jobid);

int execute_system (char **argv, int argc, int input_fd, int output_fd);

int parse_line (char *input, char **argv, char **input_redir, char **output_redir, int *append);

void get_line(char *input);

char* get_relative_path (char *ucwd, char *from);

void prompt_print ();

void inbuilt_cd (char **argv, int argc);

void inbuilt_echo (char **argv, int argc);

void inbuilt_fg (char **argv, int argc);

void inbuilt_jobs (char **argv, int argc);

void inbuilt_killallbg (char **argv, int argc);

void inbuilt_pwd (char **argv, int argc);

void inbuilt_pinfo (char **argv, int argc);

void inbuilt_sendsig (char **argv, int argc);

void check_and_execute_inbuilt (char **argv, int argc);

void execute (char **argv, int argc, int input_fd, int output_fd);

void execute_with_pipes (char *input, int input_pipe);

void exit_handler (int sig);

#endif
