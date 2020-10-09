/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_pipe_fd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 20:48:16 by qli           #+#    #+#                 */
/*   Updated: 2020/10/09 21:24:39 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		check_token_pipe_pos(t_data *data, int cmd, int token)
{
	int	token_pos;
	int	i;

	token_pos = 0;
	i = 0;
	while (i < token)
	{
		if (ft_strncmp("|", data->commands[cmd]->tokens[i], 1) == 0)
		{
			token_pos++;
		}
		i++;
	}
	return (token_pos);
}


void	set_child_pipe_fds(t_data *data, int cmd, int token)
{
	int	token_pos;

	token_pos = check_token_pipe_pos(data, cmd, token);
	if (token_pos == 0)
		child_first_pipe_setup(data, cmd, token_pos);
}

void	set_parent_pipe_fds(t_data *data, int cmd, int token)
{
	int	token_pos;

	token_pos = check_token_pipe_pos(data, cmd, token);
	if (token_pos == 0)
		parent_first_pipe_setup(data, cmd, token_pos);
}