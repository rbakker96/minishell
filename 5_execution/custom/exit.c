/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:51:32 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/29 14:41:33 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_exit(t_data *data, int cmd, int tkn, int needed_tokens)
{
	int exit_code;

	needed_tokens = calculate_needed_tokens(data, cmd, tkn);
	if (needed_tokens == 1)
	{
		if (data->commands[cmd]->pipe_nb == 0)
			print(data, data->iostream[1], "exit\n", 0);
		clear_memory(data);
		exit(0);
	}
	numeric_arg_check(data, cmd);
	if (needed_tokens > 2)
	{
		too_many_args(data, cmd);
		return ;
	}
	exit_code = ft_atoi(data->commands[cmd]->tokens[1]);
	if (exit_code == 0 && data->commands[cmd]->tokens[1][0] != '0')
		numeric_error(data, cmd);
	if (data->commands[cmd]->pipe_nb == 0)
		print(data, data->iostream[1], "exit\n", 0);
	clear_memory(data);
	exit(exit_code);
}

int		numeric_arg_check(t_data *data, int cmd)
{
	int		len;
	int		len_comparison;
	char	*value;

	value = data->commands[cmd]->tokens[1];
	len_comparison = ft_strlen(value);
	len = 0;
	while (ft_isdigit(value[len]) || value[len] == '-' || value[len] == '+')
		len++;
	if (len != len_comparison)
		numeric_error(data, cmd);
	return (0);
}

void	too_many_args(t_data *data, int cmd)
{
	if (data->commands[cmd]->pipe_nb == 0)
		print(data, 2, "exit\n", 0);
	print(data, 2, "minishell: exit: too many arguments\n", 0);
	g_exit_code = 1;
}

void	numeric_error(t_data *data, int cmd)
{
	if (data->commands[cmd]->pipe_nb == 0)
		print(data, 2, "exit\n", 0);
	print(data, 2, "minishell: exit: ", 0);
	print(data, 2, data->commands[cmd]->tokens[1], 0);
	print(data, 2, ": numeric argument required\n", 0);
	g_exit_code = 2;
	exit(2);
}
