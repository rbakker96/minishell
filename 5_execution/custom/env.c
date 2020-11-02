/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:51:19 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/31 17:26:40 by roybakker     ########   odam.nl         */
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
		if (env_with_value(data->envp[index]))
		{
			print(data, data->iostream[1], data->envp[index], 0);
			print_char(data, data->iostream[1], '\n', 0);
		}
		index++;
	}
}

int		env_with_value(char *variable)
{
	int i;

	i = 0;
	while (variable[i] != '\0')
	{
		if (variable[i] == '=')
			return (1);
		i++;
	}
	return (0);
}
