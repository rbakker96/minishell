/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:51:32 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/22 14:58:50 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_exit(t_data *data, int cmd, int tkn, int needed_tokens)
{
	int exit_code;

	needed_tokens = calculate_needed_tokens(data, cmd, tkn);
	if (needed_tokens == 1)
	{
		clear_memory(data);
		exit(0);
	}
	if (numeric_arg_check(data, cmd) == -1)
		return ;
	if (needed_tokens > 2)
	{
		too_many_args(data);
		return ;
	}
	exit_code = ft_atoi(data->commands[cmd]->tokens[1]);
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
	while (ft_isdigit(value[len]))
		len++;
	if (len != len_comparison)
	{
		print(data, 2, "exit\n", 0);
		print(data, 2, "bash: exit: ", 0);
		print(data, 2, value, 0);
		print(data, 2, ": numeric argument required\n", 0);
		g_exit_code = 1;
		return (-1);
	}
	return (0);
}

void	too_many_args(t_data *data)
{
	print(data, 2, "bash: exit: too many arguments\nexit\n", 0);
	g_exit_code = 1;
}
