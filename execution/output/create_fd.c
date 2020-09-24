/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_fd.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 14:15:21 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/24 14:58:42 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_fd		create_fd(t_data *data, int i, int token, int *token_amount)
{
	char 	*value;
	t_fd	fd;

	fd.input = 0;
	fd.output = 1;
	value = data->commands[i]->tokens[token];
	while (token < (*token_amount) || (fd.input != 0 && value[0] == '|'))
	{
		if (ft_strncmp(">", value, ft_strlen(value)) == 0)
			fd.output = overwrite_file(data, i, &token);
		else if (ft_strncmp(">>", value, ft_strlen(value)) == 0)
			fd.output = append_file(data, i, &token);
		else if (ft_strncmp("<", value, ft_strlen(value)) == 0)
			fd.input = input_file(data, i, &token);
//		else if (ft_strncmp("|", value, ft_strlen(value)) == 0)
//			fd = 1; //function that returns fd to pipe
		else
			token++;
		value = data->commands[i]->tokens[token];
	}
	token_amount = &token;
	return (fd);
}
