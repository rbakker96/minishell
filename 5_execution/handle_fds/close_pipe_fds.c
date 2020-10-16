/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   close_pipe_fds.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/15 18:50:30 by qli           #+#    #+#                 */
/*   Updated: 2020/10/16 14:11:38 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	close_unused_fds(t_data *data, int cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (data->commands[cmd]->pipe_nb == 0)
		return ;
	while (i < data->commands[cmd]->pipe_nb)
	{
		j = 0;
		while (j < 1)
		{
			if (data->commands[cmd]->pipes[i][j] != data->iostream[READ] \
			&& data->commands[cmd]->pipes[i][j] != data->iostream[WRITE])
				close(data->commands[cmd]->pipes[i][j]);
			j++;
		}
		i++;
	}
}

//close READ / WRITE STREAM
void	close_used_fds(t_data *data, int cmd)
{
	if (data->commands[cmd]->pipe_nb == 0)
		return ;
	if (data->iostream[READ] != STDIN)
		close(data->iostream[READ]);
	if (data->iostream[WRITE] != STDOUT)
		close(data->iostream[WRITE]);
}
