/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executable.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:06:18 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/09 17:56:54 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_executable(t_data *data, int command, int *token)
{
	if (check_relative_path(data->commands[command]->tokens[(*token)]) == 1)
		relative_path(data, command, token);
	else
		absolute_path(data, command, token);
}

void	relative_path(t_data *data, int command, int *token)
{
	int pid;
	int status;
	int errno;
	char *error_message;
	char *args[] = {"data->commands[command]->tokens[(*token)]", NULL};
	char *envp[] = {NULL};

	pid = fork();
//	CLEAR STRUCT WHEN FAIL
//
	if (pid == 0)
	{
		execve(data->commands[command]->tokens[(*token)], args, envp);
		error_message = strerror(errno);
		print(error_message);
		print("\n");
		//	CLEAR STRUCT WHEN FAIL
		//
	}
	wait(&status);
}

void	absolute_path(t_data *data, int command, int *token)
{
	int		i;
	char	*path;
	char	**path_array;

	i = 0;
	path = find_path(data);
	path_array = ft_split(path, ':');
//	CLEAR STRUCT WHEN FAIL
//

	while (path_array[i] != NULL)
	{
		search_path(data, command, token, path_array[i]);
		i++;
	}
}

void	search_path(t_data *data, int command, int *token, char *path_array)
{
	int		pid;
	int		status;
	char	*updated_token;
	char	*updated_path;
	char	*args[] = {"updated_path", data->commands[command]->tokens[(*token) + 1], NULL};
	char	*envp[] = {NULL};


	//move up
	updated_token = ft_strjoin("/", data->commands[command]->tokens[(*token)]);
//	CLEAR STRUCT WHEN FAIL
//	
	updated_path = ft_strjoin(path_array, updated_token);
//	CLEAR STRUCT WHEN FAIL
//
	pid = fork();
//	CLEAR STRUCT WHEN FAIL
//
	if (pid == 0)
		execve(updated_path, args, envp);
	wait(&status);
}
