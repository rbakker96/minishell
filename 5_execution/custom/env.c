/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:51:19 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/15 17:48:00 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_env(t_data *data, int *tkn)
{
	int index;

	index = 0;
	while (data->envp[index] != 0)
	{
		print(data, data->fd[1], data->envp[index], 0);
		print_char(data, data->fd[1], '\n', 0);
		index++;
	}
	*tkn = *tkn + 1;
}
