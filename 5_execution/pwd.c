/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 11:20:52 by qli           #+#    #+#                 */
/*   Updated: 2020/10/02 14:51:44 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_pwd(t_data *data, int i, int *token, int needed_tokens)
{
	char	buf[PATH_MAX];
	char	*value;

	value = getcwd(buf, (size_t)PATH_MAX);
	//if (value == NULL)
	//
	create_fd(data, i, (*token), &needed_tokens);
	if (data->commands[i]->error_flag != -1)
	{
		(*token) = data->commands[i]->token_amount;
		return ;
	}
	print(data->fd[1], value);
	print_char(data->fd[1], '\n');
	(*token) = needed_tokens;
}
