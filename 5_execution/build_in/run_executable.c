/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_executable.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 20:12:02 by qli           #+#    #+#                 */
/*   Updated: 2020/10/15 18:10:17 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_executable(t_data *data, int cmd, int *tkn)
{
	int	needed_tokens;

	needed_tokens = calculate_needed_tokens(data, cmd, (*tkn));
	create_args(data, cmd, (*tkn));
	if (check_relative_path(data->commands[cmd]->tokens[(*tkn)]) == 1)
	{
		if (fork_executable(data, cmd))
			run_executable_error(data, data->commands[cmd]->tokens[(*tkn)]);
	}
	else
		execute_absolute_executable(data, cmd, tkn, 0);
	(*tkn) = needed_tokens;
	update_token_position(data, cmd, tkn);
}

void	execute_absolute_executable(t_data *data, int cmd, int *tkn, int x)
{
	struct stat stats;

	while (create_path_array(data, cmd, (*tkn), x) != -1)
	{
		if (stat(data->args[0], &stats) == 0)
		{
			fork_executable(data, cmd);
			return ;
		}
		x++;
	}
	run_executable_error(data, data->commands[cmd]->tokens[(*tkn)]);
}

int		fork_executable(t_data *data, int cmd)
{
	int pid;
	int status;

	pid = fork();
	if (pid == -1)
		fork_error(data, cmd);
	if (pid == 0)
	{
		dup2(data->iostream[0], 0);
		dup2(data->iostream[1], 1);
		execve(data->args[0], data->args, data->envp);
		exit(1);
	}
	wait(&status);
	printf("status = %d\n", status);
	return (status);
}
