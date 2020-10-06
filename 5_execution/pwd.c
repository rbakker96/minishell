/* ************************************************************************** */
/*                                                                            */
<<<<<<< HEAD
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 11:20:52 by qli               #+#    #+#             */
/*   Updated: 2020/10/06 14:48:21 by rbakker          ###   ########.fr       */
=======
/*                                                        ::::::::            */
/*   pwd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 11:20:52 by qli           #+#    #+#                 */
/*   Updated: 2020/10/06 14:48:25 by qli           ########   odam.nl         */
>>>>>>> 9eef99e4ffd01b0a205c768ed3e1156b0ba4f26f
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
	print(data, data->fd[1], value, 0);
	print_char(data, data->fd[1], '\n', 0);
	(*token) = needed_tokens;
}
