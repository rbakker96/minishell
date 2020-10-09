/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   child_pipe_fd_setup.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 21:04:03 by qli           #+#    #+#                 */
/*   Updated: 2020/10/09 21:18:08 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	child_first_pipe_setup(t_data *data, int cmd, int token_pos)
{
	if (data->pipe_num == 0)
	{
		dup2(data->fd[0], 0);
		dup2(data->fd[1], 1);		
	}
	else if (data->pipe_num > 0 && data->fd[1] == 1) // need to understand how fds are set currently
	{
		dup2(data->fd[0], 0);
		close(data->pipefd[token_pos][0]);
		dup2(data->pipefd[token_pos][1], 1);
		close(data->pipefd[token_pos][1]);
	}
	else if (data->pipe_num > 0 && data->fd[1] != 1)
	{
		dup2(data->fd[0], 0);
		dup2(data->fd[1], 1);
		close(data->pipefd[token_pos][0]);
		close(data->pipefd[token_pos][1]);	
	}
	printf("token_pos is %d\n", token_pos);
	printf("cmd is %d\n", cmd);
}
