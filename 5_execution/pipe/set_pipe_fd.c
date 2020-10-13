/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_pipe_fd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 20:48:16 by qli           #+#    #+#                 */
/*   Updated: 2020/10/12 17:15:25 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_child_pipe_fds(t_data *data)
{
	if (data->pipe_pos == 0)
		child_first_pipe_setup(data);
	else if (data->pipe_pos > 0 && data->pipe_pos < data->pipe_num)
		child_between_pipe_setup(data);
	else if (data->pipe_pos > 0 && data->pipe_pos == data->pipe_num)
		child_last_pipe_setup(data);
}

void	set_parent_pipe_fds(t_data *data)
{
	if (data->pipe_pos == 0)
		parent_first_pipe_setup(data);
	else if (data->pipe_pos > 0 && data->pipe_pos < data->pipe_num)
		parent_between_pipe_setup(data);
	else if (data->pipe_pos > 0 && data->pipe_pos == data->pipe_num)
		parent_last_pipe_setup(data);
}