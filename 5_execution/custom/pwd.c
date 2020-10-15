/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 11:20:52 by qli           #+#    #+#                 */
/*   Updated: 2020/10/15 17:47:56 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_pwd(t_data *data, int cmd, int *tkn, int needed_tokens)
{
	char	buf[PATH_MAX];
	char	*value;

	cmd++;
	value = getcwd(buf, (size_t)PATH_MAX);
	if (value == NULL)
		get_directory_error(data);
	print(data, data->fd[1], value, 0);
	print_char(data, data->fd[1], '\n', 0);
	(*tkn) = needed_tokens;
}
