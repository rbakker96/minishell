/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_signal.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/21 13:15:18 by qli           #+#    #+#                 */
/*   Updated: 2020/10/21 18:37:47 by qli           ########   odam.nl         */
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
	// g_exit_signal = 0;
}

void	print_prompt(void)
{
	write(1, "\b\b  \b\b", 6);
	ft_printf("\n\033[1;32m→\033[1;36m %s\033[0m ", g_dir_path);
}

void	sigint_handler(int signum)
{
	int	ret;

	ret = 0;
	g_exit_signal = 2;
	if (g_pid == 0)
		print_prompt();	
	else
	{
		ret = kill(g_pid, g_exit_signal);
		if (ret == 0)
		{
			write(1, "\n", 1);
			g_pid = 0;
		}
		else
			print_prompt();
	}
	signal(signum, sigint_handler);
}

void	sigquit_handler(int signum)
{
	int	ret;

	ret = 0;
	g_exit_signal = 3;
	if (g_pid == 0)
		write(1, "\b\b  \b\b", 6);
	else
	{
		ret = kill(g_pid, g_exit_signal);
		if (ret == 0)
			write(1, "Quit: 3\n", 8);
		else
			write(1, "\b\b  \b\b", 6);
	}
	signal(signum, sigquit_handler);
}
