/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/20 17:28:50 by qli           #+#    #+#                 */
/*   Updated: 2020/10/21 11:13:51 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void	handle_sigtstp(int sig)
{
	printf("stop not allow\n");
}

void	handle_sigcont(int sig)
{
	printf("Input number: \n");
	fflush(stdout);
}

int	main(int argc, char *argv[])
{
	// struct sigaction sig;
	// sig.sa_handler = &handle_sigtstp;
	// sig.sa_flags = SA_RESTART;
	// sigaction(SIGTSTP, &sig, NULL);

	signal(SIGINT, &handle_sigcont);
	int	x;
	printf("input number : ");
	scanf("%d", &x);
	printf("result %d * 5 = %d\n", x, x * 5);
	return (0);
}
