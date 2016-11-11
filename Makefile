shell: \
			main.o \
			execute_system.o \
			parse_line.o \
			get_line.o \
			get_relative_path.o \
			prompt_print.o \
			get_job_pid.o \
			inbuilt_cd.o \
			inbuilt_echo.o \
			inbuilt_fg.o \
			inbuilt_jobs.o \
			inbuilt_killallbg.o \
			inbuilt_pwd.o \
			inbuilt_pinfo.o \
			inbuilt_sendsig.o \
			check_and_execute_inbuilt.o \
			execute.o \
			execute_with_pipes.o \
			exit_handler.o
	$(CC) -g -o shell $^

clean:
	@rm -f *.o shell

main.o: shell.h main.c
	$(CC) -g -c main.c

execute_system.o: shell.h src/execute_system.c
	$(CC) -g -c src/execute_system.c

parse_line.o: shell.h src/parse_line.c
	$(CC) -g -c src/parse_line.c

get_line.o: shell.h src/get_line.c
	$(CC) -g -c src/get_line.c

get_relative_path.o: shell.h src/get_relative_path.c
	$(CC) -g -c src/get_relative_path.c

prompt_print.o: shell.h src/prompt_print.c
	$(CC) -g -c src/prompt_print.c

get_job_pid.o: shell.h src/get_job_pid.c
	$(CC) -g -c src/get_job_pid.c

inbuilt_cd.o: shell.h src/inbuilt_cd.c
	$(CC) -g -c src/inbuilt_cd.c

inbuilt_echo.o: shell.h src/inbuilt_echo.c
	$(CC) -g -c src/inbuilt_echo.c

inbuilt_fg.o: shell.h src/inbuilt_fg.c
	$(CC) -g -c src/inbuilt_fg.c

inbuilt_jobs.o: shell.h src/inbuilt_jobs.c
	$(CC) -g -c src/inbuilt_jobs.c

inbuilt_killallbg.o: shell.h src/inbuilt_killallbg.c
	$(CC) -g -c src/inbuilt_killallbg.c

inbuilt_pwd.o: shell.h src/inbuilt_pwd.c
	$(CC) -g -c src/inbuilt_pwd.c

inbuilt_pinfo.o: shell.h src/inbuilt_pinfo.c
	$(CC) -g -c src/inbuilt_pinfo.c

inbuilt_sendsig.o: shell.h src/inbuilt_sendsig.c
	$(CC) -g -c src/inbuilt_sendsig.c

check_and_execute_inbuilt.o: shell.h src/check_and_execute_inbuilt.c
	$(CC) -g -c src/check_and_execute_inbuilt.c

execute.o: shell.h src/execute.c
	$(CC) -g -c src/execute.c

execute_with_pipes.o: shell.h src/execute_with_pipes.c
	$(CC) -g -c src/execute_with_pipes.c

exit_handler.o: shell.h src/exit_handler.c
	$(CC) -g -c src/exit_handler.c
