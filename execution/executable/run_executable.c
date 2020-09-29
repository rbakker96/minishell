/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_executable.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 20:12:02 by qli           #+#    #+#                 */
/*   Updated: 2020/09/29 11:41:37 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_executable(t_data *data, int i, int *token, int needed_tokens, int x)
{
	char	**path;
	char	*path_token;

	create_fd(data, i, (*token), &needed_tokens, data->fd);
	create_args(data, i, (*token));
	if (check_relative_path(data->commands[i]->tokens[*token]) == 1)
		fork_executable(data, 0, 0);
	else
	{
		path = ft_split(find_path(data), ':');
		path_token = ft_strjoin("/", data->commands[i]->tokens[(*token)]);
		//ERROR path or path_token
		//
		while (path[x] != NULL)
		{
			data->args[0] = ft_strjoin(path[x], path_token);
			if (!fork_executable(data, path, x))
				break ;
			x++;
			free(data->args[0]);
		}
	}
	(*token) = needed_tokens;
}

int		fork_executable(t_data *data, char **path, int x)
{
	int		pid;
	int		status;
	int		errno;

	pid = fork();
	//if (pid == -1)
	//ERROR
	if (pid == 0)
	{
		dup2(data->fd[0], 0);
		dup2(data->fd[1], 1);
		execve(data->args[0], data->args, data->envp);
		if (!path || path[x + 1] == NULL)
		{
			print(2, strerror(errno));
			print_char(2, '\n');
		}
		exit(1);
	}
	wait(&status);
	return (status);
}
