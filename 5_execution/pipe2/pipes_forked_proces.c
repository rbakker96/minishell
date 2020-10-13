/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipes_forked_proces.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/13 15:08:14 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/13 17:02:32 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	pipes_forked_proces(t_data *data, int cmd)
{
	int pipe_index;

	pipe_index = data->commands[cmd]->pipe_index;
	if (data->commands[cmd]->pipe_amount > 0) // and with input redirect
	{
		if (pipe_index != 0)
		{
			dup2(data->commands[cmd]->fd[pipe_index][0], 0);
			close(data->commands[cmd]->fd[pipe_index][0]);
		}
		if (pipe_index < data->commands[cmd]->pipe_amount)
		{
			dup2(data->commands[cmd]->fd[pipe_index][1], 1);
			close(data->commands[cmd]->fd[pipe_index][1]);
		}
	}
}
