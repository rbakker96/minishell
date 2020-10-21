/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_signal.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 13:15:18 by qli           #+#    #+#                 */
/*   Updated: 2020/10/21 17:50:39 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		g_exit_signal = 0;
int		g_counter = 0;

void	handle_all_signal(t_data *data)
{
	if (signal(SIGINT, &sigint_handler) == SIG_ERR)
		data->exit_code = 1;
	if (signal(SIGQUIT, &sigquit_handler) == SIG_ERR)
		data->exit_code = 1;
	//g_exit_signal = 0;
}

void	print_prompt(void)
{
	ft_printf("\n");
	ft_printf("\033[1;32m");
	ft_printf("→ ");
	ft_printf("\033[1;36m");
	ft_printf("%s", g_dir_path);
	ft_printf(" ");
	ft_printf("\033[0m");
// printf("\b\b\b");
// printf("\033[1;32m→\033[1;36m minishell\033[0m \n");
}

void	sigint_handler(int signum) // CTRL - C
{
	char enter;
	int	ret;

	ret = 0;
	enter = '\n';
	// printf("pid is %d\n", g_pid);
	// fflush(NULL);
	g_exit_signal = 2;
	if (g_pid == 0)
	{
		write(1, "\b\b  \b\b", 6);
		print_prompt();	
	}
	else
	{
		ret = kill(g_pid, g_exit_signal);
		if (ret == 0)
		{
			write(1, &enter, 1);
			g_pid = 0;
			return ;
		}
		else if (ret == -1)
		{
			write(1, "\b\b  \b\b", 6);
			print_prompt();
		}
	}
	signal(signum, sigint_handler);
	

	// write(1, "\b\b", 2);
	// write(1, "  ", 2);
	// write(1, "\b\b", 2);
	// write(1, &enter, 1);
	// g_exit_signal = 2;
	// if (kill(-g_pid, g_exit_signal) == -1)
	// 	print_prompt();
	
	// signal(signum, sigint_handler);
}

void	sigquit_handler(int signum) // CTRL - backslash
{
	// write(1, "Quit: 3\n", 8);
	write(1, "\b\b", 2);
	write(1, "  ", 2);
	write(1, "\b\b", 2);
	g_exit_signal = 3;
	if (g_pid > 0)
		kill(g_pid, g_exit_signal);
	signal(signum, sigquit_handler);
}

// how could this function only kill the child process and exit (130) in the child
// and leave the parent process alive?

// void	handle_sigint(int sig)
// {
	// printf("interrupt signal %d received\n", sig);
	// // signal(sig, SIG_IGN); // will ignore after once
	// signal(sig, &handle_sigint);
	// if (g_pid && sig)
	// {
	// 	kill(g_pid, 2); // only stops the child process
	// 	// exit(130);
	// }
	// signal(sig, &handle_sigint);
	// kill(pid, 2);
	// fflush(NULL);
	// g_sigint_code = 1;
	// signal(sig, SIG_DFL); // carry out default function after catching the signal
// }

// void handle_sigint(int sig) 
// { 
//     // printf("inside handle signal function\n");
// 	signal(sig, &handle_sigint);
// 	// write(1, "\n", 1);
// 	// // signal(sig, handle_sigint);
// 	// exit(130);
// }

		// if (g_sigint_code == 1)
		// {
		// 	printf("CAME HERE\n");
		// 	printf("g_pid is %d\n", g_pid);
		// 	kill(g_pid, 2);
		// 	g_sigint_code = 0; // not sure if needs to reset
		// }