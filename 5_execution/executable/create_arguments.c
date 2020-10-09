/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_arguments.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/25 15:05:59 by qli           #+#    #+#                 */
/*   Updated: 2020/10/09 17:05:32 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	create_args(t_data *data, int cmd, int token)
{
	int	x;
	int args_num;

	x = 1;
	args_num = check_args_num(data, cmd, token);
	data->args = (char **)malloc(sizeof(char *) * (args_num + 1));
	if (data->args == NULL)
		malloc_error(data, data->command_amount, 0);
	data->args[0] = ft_strdup(data->commands[cmd]->tokens[token]);
	if (data->args[0] == NULL)
		malloc_error(data, data->command_amount, 0);
	while (x < args_num)
	{
		data->args[x] = ft_strdup(data->commands[cmd]->tokens[token + x]);
		if(data->args[x] == NULL)
			malloc_error(data, data->command_amount, 0);
		x++;
	}
	data->args[args_num] = NULL;
}

int		check_args_num(t_data *data, int cmd, int token)
{
	int args_num;

	args_num = 0;
	while (token < data->commands[cmd]->token_amount)
	{
		if (ft_strncmp(data->commands[cmd]->tokens[token], ">", 1) == 0 || \
		ft_strncmp(data->commands[cmd]->tokens[token], "<", 1) == 0 || \
		ft_strncmp(data->commands[cmd]->tokens[token], "|", 1) == 0)
		{
			return (args_num);
		}
		token++;
		args_num++;
	}
	return (args_num);
}
