/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:51:19 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/22 20:30:06 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_env(t_data *data, int cmd, int tkn, int needed_tokens)
{
	int index;

	index = 0;
	needed_tokens = calculate_needed_tokens(data, cmd, tkn);
	if (needed_tokens > 1)
	{
		print(data, 2, "minishell : env : no arguments allowed\n", 0);
		g_exit_code = 1;
		return ;
	}
	while (data->envp[index] != 0)
	{
		print(data, data->iostream[1], data->envp[index], 0);
		print_char(data, data->iostream[1], '\n', 0);
		index++;
	}
}
