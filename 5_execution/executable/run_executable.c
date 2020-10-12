/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_executable.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 20:12:02 by qli           #+#    #+#                 */
/*   Updated: 2020/10/12 11:53:35 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_executable(t_data *data, int cmd, int *token, int needed_tokens)
{
	// create_fd(data, cmd, (*token), &needed_tokens);
	create_args(data, cmd, (*token));
	if (check_relative_path(data->commands[cmd]->tokens[(*token)]) == 1)
		fork_executable(data, cmd, *token);
	else
		execute_absolute_executable(data, cmd, token, 0);
	(*token) = needed_tokens;
}

void	execute_absolute_executable(t_data *data, int cmd, int *token, int x)
{
	char	**path;
	char	*path_token;

	path = ft_split(find_path(data), ':');
	if (path == NULL)
		malloc_error(data, data->command_amount, 0);
	path_token = ft_strjoin("/", data->commands[cmd]->tokens[(*token)]);
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
		if (!fork_executable(data, cmd, *token))
			break ;
		x++;
	}
	free_array(path);
	free(path_token);
}

int		fork_executable(t_data *data, int cmd, int token)
{
	int		pid;
	int		status;
	int		errno;

	printf("Current token is %s\n", data->commands[cmd]->tokens[token]);
	pid = fork();
	if (pid == -1)
		fork_error(data, cmd);
	if (pid == 0)
	{
		// dup2(data->fd[0], 0);
		// dup2(data->fd[1], 1);
		set_child_pipe_fds(data, cmd, token);
		execve(data->args[0], data->args, data->envp);
		exit(1);
	}
	set_parent_pipe_fds(data, cmd, token);
	wait(&status);
	return (status);
}
