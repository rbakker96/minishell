
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int pid;
	int status;
	int new_fd;

	if (argc != 2)
	{
		printf("argument count not correct\n");
		exit(1);
	}
	if ((new_fd = open(argv[1], O_CREAT|O_TRUNC|O_WRONLY, 0644)) < 0)
	{
		perror(argv[1]);
		exit(1);
	}
	printf("this goes to the standard output.\n");
	printf("now the standard output will go to [%s].\n", argv[1]);
	// this new file will become the standard output
	// standard output is file descriptor 1. so we use dup2
	// to copy the new fd onto fd 1
	// dup2 will close the current standard output
	dup2(new_fd, 1);
	printf("this goes to the standard output.\n");
	return (0);
}
