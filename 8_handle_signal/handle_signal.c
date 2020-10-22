/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_signal.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 13:15:18 by qli           #+#    #+#                 */
/*   Updated: 2020/10/22 14:13:56 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		g_exit_code = 0;

void	signal_handler(void)
{
	if (signal(SIGINT, &sigint_handler) == SIG_ERR)
		g_exit_code = 1;
	if (signal(SIGQUIT, &sigquit_handler) == SIG_ERR)
		g_exit_code = 1;
}

void	print_prompt(void)
{
	write(2, "\b\b  \b\b", 6);
	ft_printf("\n\033[1;32m→\033[1;36m %s\033[0m ", g_dir_path);
}

void	sigint_handler(int signum)
{
	int	ret;

	ret = 0;
	g_exit_code = 2;
	if (g_pid == 0)
	{
		g_exit_code = 1;
		print_prompt();
	}
	else
	{
		ret = kill(g_pid, g_exit_code);
		if (ret == 0)
		{
			write(2, "\n", 1);
			g_pid = 0;
		}
		else
		{
			g_exit_code = 1;
			print_prompt();
		}
	}
	signal(signum, sigint_handler);
}

void	sigquit_handler(int signum)
{
	int	ret;

	ret = 0;
	g_exit_code = 3;
	if (g_pid == 0)
	{
		write(2, "\b\b  \b\b", 6);
		g_exit_code = 0;
	}
	else
	{
		ret = kill(g_pid, g_exit_code);
		if (ret == 0)
		{
			write(2, "Quit: 3\n", 8);
			g_pid = 0;
		}
		else
		{
			write(2, "\b\b  \b\b", 6);
			g_exit_code = 0;
		}
	}
	signal(signum, sigquit_handler);
}
