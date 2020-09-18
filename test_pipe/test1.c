
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

// example of parent writing into the pipe & child reading from the pipe

int main(int argc, char **argv)
{
	int pipefd[2];
	int pid;
	char buf;
	int status;
	int ret;

	if (argc <= 1)
	{
		printf("not enough argument\n");
		return (-1);
	}
	ret = pipe(pipefd); // pipe before fork so fds will be carried in both processes
	if (ret == -1)
	{
		perror("pipe");
		exit(1);
	}
	printf("pipefd[0] is %d\n", pipefd[0]);
	printf("pipefd[1] is %d\n", pipefd[1]);
	pid = fork();
	if (pid == 0)
	{
		close(pipefd[1]); // close unused write end
		while (read((pipefd[0]), &buf, 1) > 0)
			write(1, &buf, 1);
		write(1, "\n", 1);
		close(pipefd[0]); // close read end after finishing operation
	}
	else
	{
		close(pipefd[0]); // close unused read end
		write(pipefd[1], argv[1], strlen(argv[1])); // write to the write end
		close(pipefd[1]); // close write end after finishing
		wait(&status); // wait for child after all the parent actions
	}
	return (0);
}