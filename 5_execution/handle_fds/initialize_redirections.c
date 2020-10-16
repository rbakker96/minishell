/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_redirections.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 14:15:21 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/16 13:07:36 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	create_output_file(t_data *data, int cmd, int *tkn, int *fd)
{
	char *filename;

	filename = data->commands[cmd]->tokens[(*tkn) + 1];
	if ((*fd) != not_used)
		close((*fd));
	if (redirection(data->commands[cmd]->tokens[(*tkn)]) == overwrite)
		(*fd) = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	else
		(*fd) = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0664);
	if ((*fd) == -1)
		redirection_error(data, data->commands[cmd]->tokens[(*tkn)]);
	(*tkn)++;
}

void	create_input_file(t_data *data, int cmd, int *tkn, int *fd)
{
	char *filename;

	filename = data->commands[cmd]->tokens[(*tkn) + 1];
	if ((*fd) != not_used)
		close((*fd));
	(*fd) = open(filename, O_RDONLY);
	if ((*fd) == -1)
		redirection_error(data, data->commands[cmd]->tokens[(*tkn)]);
	(*tkn)++;
}
