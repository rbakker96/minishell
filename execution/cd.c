/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:50:20 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/10 12:00:40 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	go_to_home(t_data *data)
{
	char	*home_path;
	int		i;

	i = 0;
	while (data->env[i] != NULL)
	{
		if (ft_strncmp("HOME", data->env[i], 4) == 0)
			home_path = data->env[i] + 5;
		i++;
	}
	chdir(home_path);
//		CLEAR STRUCT WHEN FAIL
//
}

void	execute_cd(t_data *data, int command, int *token)
{
	if (data->commands[command]->token_amount == 1 || \
	ft_strncmp("~", data->commands[command]->tokens[(*token) + 1], 1) == 0)
		go_to_home(data);
	chdir(data->commands[command]->tokens[(*token) + 1]);
//		CLEAR STRUCT WHEN FAIL
//
	return ;
}
