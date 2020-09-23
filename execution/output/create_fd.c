/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_fd.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 14:15:21 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/23 15:53:14 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		create_fd(t_data *data, int i, int token, int *token_amount)
{
	char *value;
	int fd;

	fd = 0;
	while (token < token_amount)
	{
		value = data->commands[i]->tokens[token];
		if (ft_strncmp(">>", value, ft_strlen(value)) == 0)
			fd = 1;//function that returns fd to append
		else if (ft_strncmp(">", value, ft_strlen(value)) == 0)
			fd = 1;//function that returns fd to overwrite
		else if (ft_strncmp("<", value, ft_strlen(value)) == 0)
			fd = 1; //function that returns fd to input
		else if (ft_strncmp("|", value, ft_strlen(value)) == 0)
			fd = 1; //function that returns fd to pipe
		else
			token++;
	}
	token_amount = token;
	return (fd);
}

int		create_fd(t_data *data, int i, int token, int *token_amount)
{
	char *value;
	int fd;

	fd = 0;
	while (token < token_amount)
	{
		value = data->commands[i]->tokens[token];
		if (ft_strncmp(">>", value, ft_strlen(value)) == 0)
			fd = 1;//function that returns fd to append
		else if (ft_strncmp(">", value, ft_strlen(value)) == 0)
			fd = 1;//function that returns fd to overwrite
		else if (ft_strncmp("<", value, ft_strlen(value)) == 0)
			fd = 1; //function that returns fd to input
		else if (ft_strncmp("|", value, ft_strlen(value)) == 0)
			fd = 1; //function that returns fd to pipe
		else
			token++;
	}
	token_amount = token;
	return (fd);
}
