/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:49:34 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/11 15:04:01 by roybakker     ########   odam.nl         */
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
//		if()
//			single_quotes_input();
//		else if ()
//			double_quotes_input();
//		else if ()
//			basic_input();
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
		return (0);
}

//void	basic_input()
//{

//}

//void	single_quotes_input()
//{

//}

//void	dubbel_quotes_input()
//{

//}
