
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int pid;
	int status;
	int new_fd;
	char *cmd[] = {"/bin/ls", "-al", "/", NULL};

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
	// this new file will become the stdout
	// stdout is fd 1, so we use dup2 to copy
	// the new_fd onto fd1
	// dup2 will close the current standard out

	dup2(new_fd, 1);
	execvp(cmd[0], cmd);
	perror(cmd[0]); //it will only come here if error
	exit(1);
}