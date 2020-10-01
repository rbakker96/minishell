/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_redirection_files.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 14:14:27 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/30 14:52:19 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		append_file(t_data *data, int i, int *token)
{
	int fd;
	char *filename;

	filename = data->commands[i]->tokens[(*token) + 1];
	fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0664);
	if (fd == -1)
		redirection_error(data, filename, i, token);
	else
		(*token) += 2;
	return (fd);
}

int		overwrite_file(t_data *data, int i, int *token)
{
	int fd;
	char *filename;

	filename = data->commands[i]->tokens[(*token) + 1];
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
		redirection_error(data, filename, i, token);
	else
		(*token) += 2;
	return (fd);
}

int		input_file(t_data *data, int i, int *token)
{
	int fd;
	char *filename;

	filename = data->commands[i]->tokens[(*token) + 1];
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		redirection_error(data, filename, i, token);
	else
		(*token) += 2;
	return (fd);
}
