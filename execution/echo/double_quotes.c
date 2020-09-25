/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   double_quotes.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 11:57:35 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/25 15:24:55 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	double_quotes(t_data *data, int i, int *token, int *index)
{
	char	*value;

	value = data->commands[i]->tokens[(*token)];
	(*index)++;
	while(value[(*index)] != '\"')
	{
		if (value[(*index)] == '\\')
			double_quotes_escape(data, i, token, index);
		else if (value[(*index)] == '$')
			echo_variable(data, i, token, index);
		else
			print_char(data->commands[i]->fd.output, value[(*index)]);
		if (value[(*index)] != '\0')
			(*index)++;
	}
	(*index)++;
	if (value[(*index)] == '\'')
		single_quotes(data, i, token, index);
	if (value[(*index)] == '\"')
		double_quotes(data, i, token, index);
	if (value[(*index)] != '\0')
		no_quotes(data, i, token, index);
	return ;
}

void	double_quotes_escape(t_data *data, int i, int *token, int *index)
{
	char *value;

	value = data->commands[i]->tokens[(*token)];
	(*index)++;
	if (value[(*index)] == '$' || value[(*index)] == '`' ||
		value[(*index)] == '\"' || value[(*index)] == '\\')
		print_char(data->commands[i]->fd.output, value[(*index)]);
	else
	{
		print_char(data->commands[i]->fd.output, '\\');
		print_char(data->commands[i]->fd.output, value[(*index)]);
	}
}
