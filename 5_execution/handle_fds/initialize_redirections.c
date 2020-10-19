/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_redirections.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 14:15:21 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/19 15:54:21 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	create_output_file(t_data *data, int cmd, int *tkn, int *fd)
{
	char *filename;

	filename = data->commands[cmd]->tokens[(*tkn) + 1];
	if ((*fd) != unused)
		close((*fd));
	if (redirection(data->commands[cmd]->tokens[(*tkn)]) == overwrite)
		(*fd) = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	else
		(*fd) = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0664);
	if ((*fd) == -1)
		print_errno_str(data, cmd, data->commands[cmd]->tokens[(*tkn)]);
	(*tkn)++;
}

void	create_input_file(t_data *data, int cmd, int *tkn, int *fd)
{
	char *filename;

	filename = data->commands[cmd]->tokens[(*tkn) + 1];
	if ((*fd) != unused)
		close((*fd));
	(*fd) = open(filename, O_RDONLY);
	if ((*fd) == -1)
		print_errno_str(data, cmd, data->commands[cmd]->tokens[(*tkn)]);
	(*tkn)++;
}
