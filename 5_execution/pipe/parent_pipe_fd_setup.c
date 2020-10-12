/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parent_pipe_fd_setup.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 21:21:36 by qli           #+#    #+#                 */
/*   Updated: 2020/10/12 16:28:46 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	parent_first_pipe_setup(t_data *data, int pipe_pos)
{
	// fd of out file always change, even though the fd already exist
	if (data->pipe_num > 0)
	{
		close(data->pipefd[pipe_pos][0]);
		close(data->pipefd[pipe_pos][1]);
	}
}

void	parent_between_pipe_setup(t_data *data, int pipe_pos)
{
	close(data->pipefd[pipe_pos - 1][0]);
	close(data->pipefd[pipe_pos - 1][1]);
	close(data->pipefd[pipe_pos][0]);
	close(data->pipefd[pipe_pos][1]);	
}

void	parent_last_pipe_setup(t_data *data, int pipe_pos)
{
	close(data->pipefd[pipe_pos - 1][0]);
	close(data->pipefd[pipe_pos - 1][1]);	
}
