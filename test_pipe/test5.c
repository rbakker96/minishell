
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// redirecting in a new process
// Use fork to run a separate process while sending its output to the created file, instead of stdout
// RUN dup2 CALL IN THE CHILD SO THAT WE DO NOT OVERWITE THE STDOUT OF THE PARENT
// Also close the stdin since we do not want the forked process trying to read from there
void runcmd(int fd, char **cmd);

int main(int argc, char **argv)
{
	int pid;
	int status;
	int new_fd;
	char *cmd[] = {"/bin/ls","/", NULL};

	if (argc != 2)
	{
		printf("incorrect input\n");
		exit(1);
	}
	if ((new_fd = open(argv[1], O_CREAT|O_TRUNC|O_WRONLY, 0644)) < 0)
	{
		perror(argv[1]);
		exit(1);
	}
	printf("writing output of the command %s to \"%s\"\n", cmd[0], argv[1]);

	// run command will send stdout to newfd
	runcmd(new_fd, cmd);
	printf("all done\n");
	return (0);
}

// fork a child process and run the cmd
// send the stdout to fd
// the stdout is closed?
// parent process waits for the child to terminate
void runcmd(int fd, char **cmd)
{
	int status;
	int pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(fd, 1);
		execvp(cmd[0], cmd);
		perror(cmd[0]);
		exit(1);
	}
	wait(&status);
}
