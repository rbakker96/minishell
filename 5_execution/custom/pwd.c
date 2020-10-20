/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 11:20:52 by qli           #+#    #+#                 */
/*   Updated: 2020/10/20 14:40:48 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_pwd(t_data *data, int cmd, int tkn, int needed_tokens)
{
	char	buf[PATH_MAX];
	char	*value;

	if (needed_tokens && tkn)
		cmd++; // ????
	value = getcwd(buf, (size_t)PATH_MAX);
	if (value == NULL)
		print_errno(data, cmd, "pwd", 1); //need to double check error code
	print(data, data->iostream[1], value, 0);
	print_char(data, data->iostream[1], '\n', 0);
}
