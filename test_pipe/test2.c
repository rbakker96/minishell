
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* runs the shell equivalent of date | wc */
/* runs the shell equivalent of ls | ws */
/* runs the shell equivalent of date | cat */

int main (int argc, char **argv)
{
	int pipefd[2];
	int status;
	int done;
	int pid;

	done = 0;
	pipe(pipefd);
	pid = fork();
	if (pid == 0) //left child (left cmd of the pipe)
	{
		close(pipefd[0]); //close unused read end
		dup2(pipefd[1], 1); //make output go to pipe
		execlp(argv[1], argv[1], (char *)NULL); //execute argv[1]
		close(pipefd[1]); //close write pipe after finished using
	}
	pid = fork();
	if (pid == 0) //right child (right cmd of the pipe)
	{
		close(pipefd[1]); //close unused write end
		dup2(pipefd[0], 0); //get input from pipe
		execlp(argv[2], argv[2], (char *)NULL); //execute argv[2]
		close(pipefd[0]); // close read pipe after finishing using
	}
	wait(&status);
	return (0);
}