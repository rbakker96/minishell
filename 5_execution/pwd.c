/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 11:20:52 by qli           #+#    #+#                 */
/*   Updated: 2020/10/09 17:36:40 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_pwd(t_data *data, int cmd, int *token, int needed_tokens)
{
	char	buf[PATH_MAX];
	char	*value;

	// create_fd(data, cmd, (*token), &needed_tokens);
	// if (data->commands[cmd]->error_flag == -1)
	// {
	// 	(*token) = needed_tokens;
	// 	return ;
	// }
	cmd++;
	value = getcwd(buf, (size_t)PATH_MAX);
	if (value == NULL)
		get_directory_error(data);
	print(data, data->fd[1], value, 0);
	print_char(data, data->fd[1], '\n', 0);
	(*token) = needed_tokens;
}
