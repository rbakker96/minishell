/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:49:34 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/17 11:24:31 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_echo(t_data *data, int command, int *token)
{
	char	*value;
	int		newline;

	(*token)++;
	value = data->commands[command]->tokens[(*token)];
	newline = new_line_option(data, command, token, &value);
	while(value[0] != '>' || value[0] != '<' || value[0] != '|')
	{
		print(data->commands[command]->tokens[(*token)]);
		(*token)++;
//		if ((*token) == data->commands[command]->token_amount)
//			break ;
//		else if(value[0] == '\'')
//			single_quotes_input(data, command, token, &value);
//		else if (value[0] == '\"')
//			double_quotes_input(data, command, token, &value);
//		else
//			basic_input(data, command, token, &value);
	}
	if (newline)
		print("\n");
	return ;
}

int		new_line_option(t_data *data, int command, int *token, char **value)
{
	if (ft_strncmp("-n", (*value), ft_strlen((*value))) == 0)
	{
		(*token)++;
		*value = data->commands[command]->tokens[(*token)];
		return (1);
	}
	else
		return (0);
}

//void	basic_input(t_data *data, int command, int *token, char **value)
//{
//	int i;
//
//	i = 0;
//	while(value[i] != '\0')
//	{
//		if (value[i] == '\\')
//			len--;
//	}
//}

//void	single_quotes_input(t_data *data, int command, int *token, char **value)
//{
//
//}

//void	dubbel_quotes_input(t_data *data, int command, int *token, char **value)
//{

//}
