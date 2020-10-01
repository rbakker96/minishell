/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execution_error.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 14:33:38 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/01 11:17:59 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	redirection_error(t_data *data, char *filename, int i, int *token)
{
	int errno;

	print(2, "minishell: ");
	print(2, filename);
	print(2, " : ");
	print(2, strerror(errno));

	(*token) = data->commands[i]->token_amount;
}

void	malloc_error(t_data *data)
{
	print(2, "minishell : error due to malloc failure\n");

	free_struct(data);
	exit(1);
}
