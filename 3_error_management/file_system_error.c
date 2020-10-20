/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_system_error.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/05 10:18:54 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/20 14:30:09 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	retrive_child_exit_status(t_data *data, int status)
{
	if (WIFEXITED(status))
		data->exit_code = WEXITSTATUS(status);
	if (WCOREDUMP(status) > 0)
		data->exit_code = 1;
	if (WIFSTOPPED(status))
		data->exit_code = WSTOPSIG(status);
}

void	check_file_permission(t_data *data, char *path)
{
	struct stat stats;

	if (stat(path, &stats) != 0)
	{
		free(data->args);
		data->args = NULL;
		print_builtin_errno(data, path, 127);
	}
	else
	{
		if ((stats.st_mode & S_IFDIR) == 16384) //need to check 16384
			print_special_errno(data, path, "is a directory", 126);
		if ((stats.st_mode & S_IXUSR) == 0)
			print_special_errno(data, path, "Permission denied", 126);
	}
}

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
		free_struct(data);
		exit(exit_code);
	}
}

void	print_builtin_errno(t_data *data, char *filename, int exit_code)
{
	int errno;

	print(data, 2, "minishell : ", 0);
	print(data, 2, filename, 0);
	print(data, 2, " : ", 0);
	print(data, 2, strerror(errno), 0);
	print_char(data, 2, '\n', 0);
	free_struct(data);
	exit(exit_code);
}

void	get_directory_error(t_data *data)
{
	print(data, 2, "minishell : getcwd function failed\n", 0);
	free_struct(data);
	exit(1);
}
