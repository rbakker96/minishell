/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirections.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 14:15:21 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/09 17:37:29 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		redirections(t_data *data, int cmd, int token)
{
	char	*value;
	int		ret;

	ret = 0;
	data->fd[0] = 0;
	data->fd[1] = 1;
	value = data->commands[cmd]->tokens[token];
	while (token < data->commands[cmd]->token_amount && ret != -1)
	{
		if (value[0] == '\0')
			return (ret);
		if (ft_strncmp(">", value, ft_strlen(value)) == 0)
			data->fd[1] = overwrite_file(data, cmd, &token, &ret);
		else if (ft_strncmp(">>", value, ft_strlen(value)) == 0)
			data->fd[1] = append_file(data, cmd, &token, &ret);
		else if (ft_strncmp("<", value, ft_strlen(value)) == 0)
			data->fd[0] = input_file(data, cmd, &token, &ret);
		else if (value[0] == '|')
			break ;
		else
			token++;
		value = data->commands[cmd]->tokens[token];
	}
	return (ret);
}

int		append_file(t_data *data, int cmd, int *token, int *ret)
{
	int		fd;
	char	*filename;

	filename = data->commands[cmd]->tokens[(*token) + 1];
	fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0664);
	if (fd == -1)
		redirection_error(data, filename, ret);
	(*token) += 2;
	return (fd);
}

int		overwrite_file(t_data *data, int cmd, int *token, int *ret)
{
	int		fd;
	char	*filename;

	filename = data->commands[cmd]->tokens[(*token) + 1];
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
		redirection_error(data, filename, ret);
	(*token) += 2;
	return (fd);
}

int		input_file(t_data *data, int cmd, int *token, int *ret)
{
	int		fd;
	char	*filename;

	filename = data->commands[cmd]->tokens[(*token) + 1];
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		redirection_error(data, filename, ret);
	(*token) += 2;
	return (fd);
}
