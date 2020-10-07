/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 14:15:21 by roybakker         #+#    #+#             */
/*   Updated: 2020/10/07 13:25:14 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		redirections(t_data *data, int i, int token)
{
	char	*value;
	int		ret;

	ret = 0;
	data->fd[0] = 0;
	data->fd[1] = 1;
	value = data->commands[i]->tokens[token];
	if (value[0] == '\0')
		return (ret);
	while (token < data->commands[i]->token_amount && ret != -1)
	{
		if (ft_strncmp(">", value, ft_strlen(value)) == 0)
			data->fd[1] = overwrite_file(data, i, &token, &ret);
		else if (ft_strncmp(">>", value, ft_strlen(value)) == 0)
			data->fd[1] = append_file(data, i, &token, &ret);
		else if (ft_strncmp("<", value, ft_strlen(value)) == 0)
			data->fd[0] = input_file(data, i, &token, &ret);
		else if (value[0] == '|')
			break ;
		else
			token++;
		value = data->commands[i]->tokens[token];
	}
	return (ret);
}

int		append_file(t_data *data, int i, int *token, int *ret)
{
	int		fd;
	char	*filename;

	filename = data->commands[i]->tokens[(*token) + 1];
	fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0664);
	if (fd == -1)
		redirection_error(data, filename, ret);
	(*token) += 2;
	return (fd);
}

int		overwrite_file(t_data *data, int i, int *token, int *ret)
{
	int		fd;
	char	*filename;

	filename = data->commands[i]->tokens[(*token) + 1];
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
		redirection_error(data, filename, ret);
	(*token) += 2;
	return (fd);
}

int		input_file(t_data *data, int i, int *token, int *ret)
{
	int		fd;
	char	*filename;

	filename = data->commands[i]->tokens[(*token) + 1];
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		redirection_error(data, filename, ret);
	(*token) += 2;
	return (fd);
}
