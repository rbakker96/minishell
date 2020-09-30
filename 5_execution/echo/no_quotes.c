/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   no_quotes.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 11:57:21 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/29 17:08:36 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	no_quotes(t_data *data, int i, int *token, int *index)
{
	char	*value;

	value = data->commands[i]->tokens[(*token)];
	while(value[(*index)] != '\0')
	{
		if(redirection_check(value) == redirected)
		{
			(*token) += 2;
			value = data->commands[i]->tokens[(*token)];
			if (value == NULL)
				return ;
		}
		if (value[(*index)] == '\"')
			double_quotes(data, i, token, index);
		else if (value[(*index)] == '\'')
			single_quotes(data, i, token, index);
		if (value[(*index)] == '\\')
			no_quotes_escape(data, i, token, index);
		else if (value[(*index)] == '$')
			echo_variable(data, i, token, index);
		else
			print_char(data->fd[1], value[(*index)]);
		if (value[(*index)] != '\0')
			(*index)++;
	}
}

void	no_quotes_escape(t_data *data, int i, int *token, int *index)
{
	char *value;

	value = data->commands[i]->tokens[(*token)];
	print_char(data->fd[1], value[(*index) + 1]);
	(*index)++;
}
