/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_executable.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 20:12:02 by qli           #+#    #+#                 */
/*   Updated: 2020/10/12 15:45:46 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_executable(t_data *data, int cmd, int *tkn, int needed_tokens)
{
	create_args(data, cmd, (*tkn));
	if (check_relative_path(data->commands[cmd]->tokens[(*tkn)]) == 1)
		fork_executable(data, cmd, *tkn);
	else
		execute_absolute_executable(data, cmd, tkn, 0);
	(*tkn) = needed_tokens;
}

void	execute_absolute_executable(t_data *data, int cmd, int *tkn, int x)
{
	char	**path;
	char	*path_token;

	path = ft_split(find_path(data), ':');
	if (path == NULL)
		malloc_error(data, data->command_amount, 0);
	path_token = ft_strjoin("/", data->commands[cmd]->tokens[(*tkn)]);
	if (path_token == NULL)
		malloc_error(data, data->command_amount, path);
	while (path[x] != NULL)
	{
		data->args[0] = ft_strjoin(path[x], path_token);
		if (data->args[0] == NULL)
		{
			free(path_token);
			malloc_error(data, cmd, path);
		}
		if (!fork_executable(data, cmd, *tkn))
			break ;
		x++;
	}
	free_array(path);
	free(path_token);
}

int		fork_executable(t_data *data, int cmd, int tkn)
{
	int		pid;
	int		status;
	int		errno;

	if (tkn)
		tkn++;
	pid = fork();
	if (pid == -1)
		fork_error(data, cmd);
	if (pid == 0)
	{
		dup2(data->fd[0], 0);
		dup2(data->fd[1], 1);
		//set_child_pipe_fds(data, cmd, tkn);
		execve(data->args[0], data->args, data->envp);
		exit(1);
	}
	//set_parent_pipe_fds(data, cmd, tkn);
	wait(&status);
	return (status);
}
