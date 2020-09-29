/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:50:20 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/29 16:55:11 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_cd(t_data *data, int i, int *token, int needed_tokens)
{
	char *value;

	(*token)++;
	value = data->commands[i]->tokens[(*token)];
	create_fd(data, i, (*token), &needed_tokens, data->fd);
	if (needed_tokens > 2)
	{
		print(2, "cd : too many arguments\n"); // have to count without redirection values
		(*token) = data->commands[i]->token_amount;
		return ;
	}
	if (needed_tokens == 1 || ft_strncmp("~", value, ft_strlen(value)) == 0)
		go_to_home(data, 0);
	else
	{
		chdir(value);
	//	CLEAR STRUCT WHEN FAIL
	//
	}
	(*token) = needed_tokens;
	return ;
}

void	go_to_home(t_data *data, int i)
{
	char	*home_path;

	while (data->env[i] != NULL)
	{
		if (ft_strncmp("HOME", data->env[i], 4) == 0)
			home_path = data->env[i] + 5;
		i++;
	}
	chdir(home_path);
//	CLEAR STRUCT WHEN FAIL
//
}
