/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 11:20:52 by qli           #+#    #+#                 */
/*   Updated: 2020/09/29 20:26:12 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_pwd(t_data *data, int i, int *token, int needed_tokens)
{
	char	buf[PATH_MAX];
	char	*value;

	value = getcwd(buf, (size_t)PATH_MAX);
	create_fd(data, i, (*token), &needed_tokens);
	print(data->fd[1], value);
	print_char(data->fd[1], '\n');
	(*token) = needed_tokens;
}
