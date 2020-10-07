/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_executable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:12:02 by qli               #+#    #+#             */
/*   Updated: 2020/10/07 11:09:21 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_executable(t_data *data, int i, int *token, int needed_tokens)
{
	// create_fd(data, i, (*token), &needed_tokens);
	create_args(data, i, (*token));
	if (check_relative_path(data->commands[i]->tokens[(*token)]) == 1)
		fork_executable(data, i);
	else
		execute_absolute_executable(data, i, token, 0);
	(*token) = needed_tokens;
}

void	execute_absolute_executable(t_data *data, int i, int *token, int x)
{
	char	**path;
	char	*path_token;

	path = ft_split(find_path(data), ':');
	if (path == NULL)
		malloc_error(data, data->command_amount, 0);
	path_token = ft_strjoin("/", data->commands[i]->tokens[(*token)]);
	if (path_token == NULL)
		malloc_error(data, data->command_amount, path);
	while (path[x] != NULL)
	{
		data->args[0] = ft_strjoin(path[x], path_token);
		if (data->args[0] == NULL)
		{
			free(path_token);
			malloc_error(data, i, path);
		}
		if (!fork_executable(data, i))
			break ;
		x++;
	}
	free_array(path);
	free(path_token);
}

int		fork_executable(t_data *data, int i)
{
	int		pid;
	int		status;
	int		errno;

	pid = fork();
	if (pid == -1)
		fork_error(data, i);
	if (pid == 0)
	{
		dup2(data->fd[0], 0);
		dup2(data->fd[1], 1);
		execve(data->args[0], data->args, data->envp);
		exit(1);
	}
	wait(&status);
	return (status);
}
