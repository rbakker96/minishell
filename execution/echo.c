/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:49:34 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/10 13:23:20 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_echo(t_data *data, int command, int *token)
{
	char *current_token;
	int newline;

	(*token)++;
	current_token = data->commands[command]->tokens[(*token)];
	newline = identify_new_line_option(data, command, token, &current_token);
	while((*token) < data->commands[command]->token_amount)
	{
		print(data->commands[command]->tokens[(*token)]);
		(*token)++;
	}
	if (newline)
		print("\n");
	return ;
}

int		identify_new_line_option(t_data *data, int command, int *token, char **current_token)
{
	if (ft_strncmp("-n", (*current_token), ft_strlen((*current_token))) == 0)
	{
		(*token)++;
		(*current_token) = data->commands[command]->tokens[(*token)];
		return (1);
	}
	else
		return (1);
}

//void	identify_echo_input()
//{
//	if ()
//}
