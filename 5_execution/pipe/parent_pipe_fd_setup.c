/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parent_pipe_fd_setup.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 21:21:36 by qli           #+#    #+#                 */
/*   Updated: 2020/10/12 18:00:55 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	parent_first_pipe_setup(t_data *data)
{
	int pos;

	pos = data->pipe_pos;
	if (data->pipe_num > 0)
	{
		printf("PARENT - 1\n");
		printf("read end is %d\n", data->pipefd[pos][0]);
		printf("write end is %d\n", data->pipefd[pos][1]);
		close(data->pipefd[pos][0]);
		close(data->pipefd[pos][1]);
	}
}

void	parent_last_pipe_setup(t_data *data)
{
	int pos;

	pos = data->pipe_pos;
	printf("PARENT - 3\n");
	printf("read end is %d\n", data->pipefd[pos - 1][0]);
	printf("write end is %d\n", data->pipefd[pos - 1][1]);
	close(data->pipefd[pos - 1][0]);
	close(data->pipefd[pos - 1][1]);	
}

void	parent_between_pipe_setup(t_data *data)
{
	int pos;

	pos = data->pipe_pos;
	printf("PARENT - 2\n");
	close(data->pipefd[pos - 1][0]);
	close(data->pipefd[pos - 1][1]);
	close(data->pipefd[pos][0]);
	close(data->pipefd[pos][1]);	
}
