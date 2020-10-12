/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child_pipe_fd_setup.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 21:04:03 by qli           #+#    #+#                 */
/*   Updated: 2020/10/12 16:29:26 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	child_first_pipe_setup(t_data *data, int pipe_pos)
{
	if (data->pipe_num == 0)
	{
		dup2(data->fd[0], 0);
		dup2(data->fd[1], 1);		
	}
	else if (data->pipe_num > 0 && data->fd[1] == 1) // need to understand how fds are set currently
	{
		dup2(data->fd[0], 0);
		close(data->pipefd[pipe_pos][0]);
		dup2(data->pipefd[pipe_pos][1], 1);
		close(data->pipefd[pipe_pos][1]);
	}
	else if (data->pipe_num > 0 && data->fd[1] != 1)
	{
		dup2(data->fd[0], 0);
		dup2(data->fd[1], 1);
		close(data->pipefd[pipe_pos][0]);
		close(data->pipefd[pipe_pos][1]);	
	}
}

void	child_between_pipe_setup(t_data *data, int pipe_pos)
{
	if (data->fd[0] == 0 && data->fd[1] == 1)
	{
		close(data->pipefd[pipe_pos - 1][1]);
		dup2(data->pipefd[pipe_pos - 1][0], 0);
		close(data->pipefd[pipe_pos - 1][0]);
		close(data->pipefd[pipe_pos][0]);
		dup2(data->pipefd[pipe_pos][1], 1);
		close(data->pipefd[pipe_pos][1]);
	}
	else if (data->fd[0] != 0 && data->fd[1] == 1)
	{
		close(data->pipefd[pipe_pos - 1][1]);
		close(data->pipefd[pipe_pos - 1][0]);
		dup2(data->fd[0], 0);
		close(data->pipefd[pipe_pos][0]);
		dup2(data->pipefd[pipe_pos][1], 1);
		close(data->pipefd[pipe_pos][1]);		
	}
	else if (data->fd[0] == 0 && data->fd[1] != 1)
	{
		close(data->pipefd[pipe_pos - 1][1]);
		dup2(data->pipefd[pipe_pos - 1][0], 0);
		close(data->pipefd[pipe_pos - 1][0]);
		close(data->pipefd[pipe_pos][0]);
		close(data->pipefd[pipe_pos][1]);
		dup2(data->fd[1], 1);	
	}
	else if (data->fd[0] != 0 && data->fd[1] != 1)
	{
		close(data->pipefd[pipe_pos - 1][1]);
		close(data->pipefd[pipe_pos - 1][0]);
		close(data->pipefd[pipe_pos][0]);
		close(data->pipefd[pipe_pos][1]);
		dup2(data->fd[0], 0);
		dup2(data->fd[1], 1);	
	}
}

void	child_last_pipe_setup(t_data *data, int pipe_pos)
{
	if (data->fd[0] == 0)
	{
		close(data->pipefd[pipe_pos - 1][1]);
		dup2(data->pipefd[pipe_pos - 1][0], 0);
		close(data->pipefd[pipe_pos - 1][0]);
		dup2(data->fd[1], 1);
	}
	if (data->fd[0] != 0)
	{
		close(data->pipefd[pipe_pos - 1][1]);
		close(data->pipefd[pipe_pos - 1][0]);
		dup2(data->fd[0], 0);
		dup2(data->fd[1], 1);
	}
}
