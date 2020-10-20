/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_system_error.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/05 10:18:54 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/20 13:53:36 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_errno(t_data *data, int cmd, char *filename, int exit_code)
{
	int errno;

	print(data, 2, "minishell : ", 0);
	print(data, 2, filename, 0);
	print(data, 2, " : ", 0);
	print(data, 2, strerror(errno), 0);
	print_char(data, 2, '\n', 0);
	if (data->commands[cmd]->pipe_nb == 0)
		data->exit_code = exit_code;
	else
	{
		free_struct(data); // free struct before exiting
		exit(exit_code);
	}
}

void	get_directory_error(t_data *data)
{
	print(data, 2, "minishell : getcwd function failed\n", 0);
	free_struct(data);
	exit(1);
}

void	command_not_found_error(t_data *data, int cmd, int tkn)
{
	print(data, 2, "minishell : ", 0);
	print(data, 2, data->commands[cmd]->tokens[tkn], 0);
	print(data, 2, " : ", 0);
	print(data, 2, "command not found", 0);
	print_char(data, 2, '\n', 0);
	exit(127);
}
