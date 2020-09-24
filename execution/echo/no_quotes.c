/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   no_quotes.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 11:57:21 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/24 14:21:55 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	no_quotes(t_data *data, int i, int *token)
{
	print(data->commands[i]->fd.output, data->commands[i]->tokens[(*token)]);
	(*token)++;
}
