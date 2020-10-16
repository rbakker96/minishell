/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_executable.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 20:12:02 by qli           #+#    #+#                 */
/*   Updated: 2020/10/16 14:41:22 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_executable(t_data *data, int cmd, int *tkn)
{
	create_args(data, cmd, *tkn);
	if (check_relative_path(data->commands[cmd]->tokens[*tkn]) == 1)
		run_executable(data);
	else if (data->commands[cmd]->tokens[*tkn][0] == '\0') //empty token
		run_empty_executable(data);
	else
		execute_absolute_executable(data, cmd, tkn);
}

void	run_empty_executable(t_data *data)
{
	close(data->iostream[READ]);
	close(data->iostream[WRITE]);
}

void	execute_absolute_executable(t_data *data, int cmd, int *tkn)
{
	struct	stat stats;
	int		i;

	i = 0;
	while (create_path_array(data, cmd, *tkn, i) != -1)
	{
		if (stat(data->args[0], &stats) == 0)
		{
			run_executable(data);
			return ;
		}
		i++;
	}
	exit(1); // change the exit code later
}

void		run_executable(t_data *data)
{
	dup2(data->iostream[READ], STDIN);
	dup2(data->iostream[WRITE], STDOUT);
	execve(data->args[0], data->args, data->envp);
}
