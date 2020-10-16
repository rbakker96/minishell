/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_iostream.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/15 17:46:32 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/16 13:05:28 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_iostream(t_data *data, int cmd, int tkn)
{
	data->iostream[READ] = not_used; // discuss why we need to set it as -1 later
	data->iostream[WRITE] = not_used;
	if (data->commands[cmd]->pipe_nb > 0)
		set_pipe_file_descriptor(data, cmd);
	if (data->commands[cmd]->token_amount > 0)
		set_redirection_file_descriptor(data, cmd, tkn);
}

void	set_pipe_file_descriptor(t_data *data, int cmd)
{
	int pipe_pos;
	int	pipe_nb;

	pipe_pos = data->commands[cmd]->pipe_pos;
	pipe_nb = data->commands[cmd]->pipe_nb;
	if (pipe_pos == 0)
	{
		data->iostream[WRITE] = data->commands[cmd]->pipes[pipe_pos][STDOUT];
	}
	else if (pipe_pos < pipe_nb)
	{
		data->iostream[READ] = data->commands[cmd]->pipes[pipe_pos - 1][STDIN];
		data->iostream[WRITE] = data->commands[cmd]->pipes[pipe_pos][STDOUT];
	}
	else if (pipe_pos > pipe_nb || pipe_pos == pipe_nb) // can this be combined to (pipe_pos >= pipe_nb)
	{
		data->iostream[READ] = data->commands[cmd]->pipes[pipe_pos - 1][STDIN];
	}
}

void	set_redirection_file_descriptor()
{

}
