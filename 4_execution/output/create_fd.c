/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_fd.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 14:15:21 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/29 16:58:18 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	create_fd(t_data *data, int i, int token, int *needed_tokens, int fd[2])
{
	char 	*value;

	fd[0] = 0;
	fd[1] = 1;
	value = data->commands[i]->tokens[token];
	while (token < (*needed_tokens)) // until a pipe is hit
	{
		if (ft_strncmp(">", value, ft_strlen(value)) == 0)
			fd[1] = overwrite_file(data, i, &token);
		else if (ft_strncmp(">>", value, ft_strlen(value)) == 0)
			fd[1] = append_file(data, i, &token);
		else if (ft_strncmp("<", value, ft_strlen(value)) == 0)
			fd[0] = input_file(data, i, &token);
		else if (fd[1] != 1 && value[0] == '|')
			break ;
//		else if (ft_strncmp("|", value, ft_strlen(value)) == 0)
//			fd = 1; //function that returns fd to pipe
		else
			token++;
		value = data->commands[i]->tokens[token];
	}
	*needed_tokens = token;
}
