/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parent_pipe_fd_setup.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 21:21:36 by qli           #+#    #+#                 */
/*   Updated: 2020/10/09 21:32:37 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	parent_first_pipe_setup(t_data *data, int cmd, int token_pos)
{
	printf("cmd is %d\n", cmd);
	printf("fd[1] is %d\n", data->fd[1]);
	printf("fd[0] is %d\n", data->fd[0]);
	// fd of out file always change, even though the fd already exist
	if (data->pipe_num > 0)
	{
		close(data->pipefd[token_pos][0]);
		close(data->pipefd[token_pos][1]);
	}

}

