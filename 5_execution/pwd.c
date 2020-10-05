/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 11:20:52 by qli           #+#    #+#                 */
/*   Updated: 2020/10/05 11:19:59 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_pwd(t_data *data, int i, int *token, int needed_tokens)
{
	char	buf[PATH_MAX];
	char	*value;

	create_fd(data, i, (*token), &needed_tokens);
	if (data->commands[i]->error_flag == -1)
	{
		(*token) = needed_tokens;
		return ;
	}
	value = getcwd(buf, (size_t)PATH_MAX);
	if (value == NULL)
		get_directory_error(data);
	if (data->commands[i]->error_flag != -1)
	{
		(*token) = data->commands[i]->token_amount;
		return ;
	}
	print(data, data->fd[1], value, 0);
	print_char(data, data->fd[1], '\n', 0);
	(*token) = needed_tokens;
}
