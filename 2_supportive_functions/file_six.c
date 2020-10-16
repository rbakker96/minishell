/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_six.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 13:11:44 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/16 13:50:51 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		compare_command(char *command, char *token_command, int len)
{
	int token_len;

	token_len = ft_strlen(token_command);
	if (token_len != len)
		return (-1);
	return (ft_strncmp(command, token_command, len));
}

int		check_token_usability(char **tokens, int i)
{
	int x;

	x = i;
	while (x > 0)
	{
		if (tokens[x][0] == '|')
			return (0);
		x--;
	}
	if (ft_strncmp(tokens[i], "<", ft_strlen(tokens[i]) == 0 ||
		ft_strncmp(tokens[i], ">", ft_strlen(tokens[i])) == 0 ||
		ft_strncmp(tokens[i], ">>", ft_strlen(tokens[i])) == 0))
		return (-1);
	else
		return (0);
}

int		calculate_needed_tokens(t_data *data, int cmd, int tkn)
{
	int		count;
	char	*value;

	count = 0;
	value = data->commands[cmd]->tokens[tkn];
	while (value != NULL && value[0] != '|')
	{
		count++;
		tkn++;
		value = data->commands[cmd]->tokens[tkn];
	}
	return (count++);
}

void	update_token_position(t_data *data, int cmd, int *tkn)
{
	char	*value;

	value = data->commands[cmd]->tokens[(*tkn)];
	if (value == NULL)
		return ;
	else if (data->commands[cmd]->tokens[(*tkn)][0] == '|')
		(*tkn)++;
	return ;
}

int		create_path_array(t_data *data, int cmd, int tkn, int x)
{
	char	**path;
	char	*path_token;

	path = ft_split(find_path(data), ':');
	if (path == NULL)
		malloc_error(data, data->command_amount, 0);
	if (path[x] == NULL)
	{
		free_array(path);
		return (-1);
	}
	path_token = ft_strjoin("/", data->commands[cmd]->tokens[tkn]);
	if (path_token == NULL)
		malloc_error(data, data->command_amount, path);
	data->args[0] = ft_strjoin(path[x], path_token);
	free_array(path);
	free(path_token);
	if (data->args[0] == NULL)
		malloc_error(data, cmd, 0);
	return (0);
}
