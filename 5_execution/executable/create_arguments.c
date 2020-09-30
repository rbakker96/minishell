/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_arguments.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/25 15:05:59 by qli           #+#    #+#                 */
/*   Updated: 2020/09/30 13:02:01 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	create_args(t_data *data, int i, int token)
{
	int	x;
	int args_num;

	x = 1;
	args_num = check_args_num(data, i, token);
	data->args = (char **)malloc(sizeof(char *) * args_num + 1);
	data->args[0] = ft_strdup(data->commands[i]->tokens[token]);
	//ERROR
	//
	while (x < args_num)
	{
		data->args[x] = ft_strdup(data->commands[i]->tokens[token + x]);
		//ERROR
		//
		x++;
	}
	data->args[args_num] = NULL;
}

int		check_args_num(t_data *data, int command, int token)
{
	int args_num;

	args_num = 0;
	while (token < data->commands[command]->token_amount)
	{
		if (ft_strncmp(data->commands[command]->tokens[token], ">", 1) == 0 || \
		ft_strncmp(data->commands[command]->tokens[token], "<", 1) == 0 || \
		ft_strncmp(data->commands[command]->tokens[token], "|", 1) == 0)
		{
			return (args_num);
		}
		token++;
		args_num++;
	}
	return (args_num);
}
