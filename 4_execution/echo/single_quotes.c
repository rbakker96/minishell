/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   single_quotes.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 11:58:02 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/28 14:17:45 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	single_quotes(t_data *data, int i, int *token, int *index) //think with parsing that 'something \' something' is not allowed
{
	char	*value;

	value = data->commands[i]->tokens[(*token)];
	(*index)++;
	while (value[(*index)] != '\'')
	{
		print_char(data->fd[1], value[(*index)]);
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
