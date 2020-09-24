/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_redirection_files.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 14:14:27 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/24 14:43:54 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		append_file(t_data *data, int i, int *token)
{
	int fd;
	char *filename;

	filename = data->commands[i]->tokens[(*token) + 1];
	fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0664);
//	CLEAR STRUCT WHEN FAIL
//
	(*token) += 2;
	return (fd);
}

int		overwrite_file(t_data *data, int i, int *token)
{
	int fd;
	char *filename;

	filename = data->commands[i]->tokens[(*token) + 1];
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
//	CLEAR STRUCT WHEN FAIL
//
	(*token) += 2;
	return (fd);
}

int		input_file(t_data *data, int i, int *token)
{
	int fd;
	char *filename;

	filename = data->commands[i]->tokens[(*token) + 1];
	fd = open(filename, O_RDONLY);
//	CLEAR STRUCT WHEN FAIL
//
	(*token) += 2;
	return (fd);
}
