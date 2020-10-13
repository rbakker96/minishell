/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child_pipe_fd_setup.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 21:04:03 by qli           #+#    #+#                 */
/*   Updated: 2020/10/13 18:12:25 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	child_first_pipe_setup(t_data *data)
{
	int pos;

	pos = data->pipe_pos;
	if (data->pipe_num == 0)
	{
		dup2(data->fd[0], 0);
		dup2(data->fd[1], 1);
	}
	else if (data->pipe_num > 0 && data->fd[1] == 1)
	{
		dup2(data->fd[0], 0);
		close(data->pipefd[pos][0]);
		dup2(data->pipefd[pos][1], 1);
		close(data->pipefd[pos][1]);
	}
	else if (data->pipe_num > 0 && data->fd[1] != 1)
	{
		dup2(data->fd[0], 0);
		dup2(data->fd[1], 1);
		close(data->pipefd[pos][0]);
		close(data->pipefd[pos][1]);
	}
}

void	child_last_pipe_setup(t_data *data)
{
	int pos;

	pos = data->pipe_pos;
	if (data->fd[0] == 0)
	{
		dup2(data->fd[1], 1);
		close(data->pipefd[pos - 1][1]);
		dup2(data->pipefd[pos - 1][0], 0);
		close(data->pipefd[pos -1][0]);

	}
	if (data->fd[0] != 0)
	{
		dup2(data->fd[0], 0);
		dup2(data->fd[1], 1);
		close(data->pipefd[pos - 1][1]);
		close(data->pipefd[pos - 1][0]);
	}
}

void	child_between_pipe_setup(t_data *data)
{
	int pos;

	pos = data->pipe_pos;
	if (data->fd[0] == 0 && data->fd[1] == 1)
	{
		close(data->pipefd[pos - 1][1]);
		dup2(data->pipefd[pos - 1][0], 0);
		close(data->pipefd[pos - 1][0]);
		close(data->pipefd[pos][0]);
		dup2(data->pipefd[pos][1], 1);
		close(data->pipefd[pos][1]);
	}
	else if (data->fd[0] != 0 && data->fd[1] == 1)
	{
		close(data->pipefd[pos - 1][1]);
		close(data->pipefd[pos - 1][0]);
		dup2(data->fd[0], 0);
		close(data->pipefd[pos][0]);
		dup2(data->pipefd[pos][1], 1);
		close(data->pipefd[pos][1]);
	}
	else if (data->fd[0] == 0 && data->fd[1] != 1)
	{
		close(data->pipefd[pos - 1][1]);
		dup2(data->pipefd[pos - 1][0], 0);
		close(data->pipefd[pos - 1][0]);
		close(data->pipefd[pos][0]);
		close(data->pipefd[pos][1]);
		dup2(data->fd[1], 1);
	}
	else if (data->fd[0] != 0 && data->fd[1] != 1)
	{
		close(data->pipefd[pos - 1][1]);
		close(data->pipefd[pos - 1][0]);
		close(data->pipefd[pos][0]);
		close(data->pipefd[pos][1]);
		dup2(data->fd[0], 0);
		dup2(data->fd[1], 1);
	}
}
