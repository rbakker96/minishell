/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   single_quotes.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 11:58:02 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/24 14:21:45 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	single_quotes(t_data *data, int i, int *token)
{
	print(data->commands[i]->fd.output, data->commands[i]->tokens[(*token)]);
	(*token)++;
}
