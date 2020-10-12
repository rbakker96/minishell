/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_pipe_fd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 20:48:16 by qli           #+#    #+#                 */
/*   Updated: 2020/10/12 16:30:00 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_child_pipe_fds(t_data *data)
{
	if (data->pipe_pos == 0)
		child_first_pipe_setup(data, data->pipe_pos);
	else if (data->pipe_pos > 0 && data->pipe_pos < data->pipe_num - 1)
		child_between_pipe_setup(data, data->pipe_pos);
	else if (data->pipe_pos > 0 && data->pipe_pos == data->pipe_num - 1)
		child_last_pipe_setup(data, data->pipe_pos);
}

void	set_parent_pipe_fds(t_data *data)
{
	printf("data->fd[0] is %d\n", data->fd[0]);
	printf("data->fd[1] is %d\n", data->fd[1]);	
	if (data->pipe_pos == 0)
		parent_first_pipe_setup(data, data->pipe_pos);
	else if (data->pipe_pos > 0 && data->pipe_pos < data->pipe_num - 1)
		parent_between_pipe_setup(data, data->pipe_pos);
	else if (data->pipe_pos > 0 && data->pipe_pos == data->pipe_num - 1)
		parent_last_pipe_setup(data, data->pipe_pos);
}