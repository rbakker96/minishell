/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_arguments.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/25 15:05:59 by qli           #+#    #+#                 */
/*   Updated: 2020/10/20 13:29:04 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	create_args(t_data *data, int cmd, int tkn)
{
	int	x;
	int args_num;

	x = 1;
	args_num = check_args_num(data, cmd, tkn);
	data->args = (char **)malloc(sizeof(char *) * (args_num + 1));
	if (data->args == NULL)
		malloc_error(data, data->command_amount, 0);
	if (!check_relative_path(data->commands[cmd]->tokens[tkn]))
		data->args[0] = get_abs_path(data, cmd, tkn, 0);
	else
	{
		data->args[0] = ft_strdup(data->commands[cmd]->tokens[tkn]);
		if (data->args[0] == NULL)
			malloc_error(data, data->command_amount, 0);
	}
	if (data->args[0])
		while (x < args_num)
		{
			data->args[x] = ft_strdup(data->commands[cmd]->tokens[tkn + x]);
			if (data->args[x] == NULL)
				malloc_error(data, data->command_amount, 0);
			x++;
		}
	data->args[args_num] = NULL;
}

int		check_args_num(t_data *data, int cmd, int tkn)
{
	int args_num;

	args_num = 0;
	while (tkn < data->commands[cmd]->token_amount)
	{
		if (ft_strncmp(data->commands[cmd]->tokens[tkn], ">", 1) == 0 || \
		ft_strncmp(data->commands[cmd]->tokens[tkn], "<", 1) == 0 || \
		ft_strncmp(data->commands[cmd]->tokens[tkn], "|", 1) == 0)
		{
			return (args_num);
		}
		tkn++;
		args_num++;
	}
	return (args_num);
}

char	*get_abs_path(t_data *data, int cmd, int tkn, int x)
{
	char		**path;
	char		*path_token;
	char		*abs_path;

	path = ft_split(find_path(data), ':');
	if (path == NULL)
		malloc_error(data, data->command_amount, 0);
	path_token = ft_strjoin("/", data->commands[cmd]->tokens[tkn]);
	if (path_token == NULL)
		malloc_error(data, data->command_amount, path);
	while (path[x] != NULL)
	{
		abs_path = check_path_array(data, path, path_token, x);
		if (abs_path)
			return (abs_path);
		x++;
	}
	free(path_token);
	free_array(path);
	return (0);
}

char	*check_path_array(t_data *data, char **path, char *path_token, int x)
{
	char		*abs_path;
	struct stat stats;

	abs_path = ft_strjoin(path[x], path_token);
	if (abs_path == NULL)
	{
		free(path_token);
		malloc_error(data, data->command_amount, path);
	}
	if (stat(abs_path, &stats) == 0)
	{
		free(path_token);
		free_array(path);
		return (abs_path);
	}
	free(abs_path);
	return (0);
}
