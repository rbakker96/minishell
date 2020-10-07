/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 15:02:22 by qli               #+#    #+#             */
/*   Updated: 2020/10/07 13:29:35 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	identify_command(t_data *data, int i, int *token, char *value)
{
	if (ft_strncmp("echo", value, ft_strlen(value)) == 0)
		execute_echo(data, i, token, data->commands[i]->token_amount);
	else if (ft_strncmp("cd", value, ft_strlen(value)) == 0)
		execute_cd(data, i, token, data->commands[i]->token_amount);
	else if (ft_strncmp("pwd", value, ft_strlen(value)) == 0)
		execute_pwd(data, i, token, data->commands[i]->token_amount);
	else if (ft_strncmp("export", value, ft_strlen(value)) == 0)
		execute_export(data, i, token);
	else if (ft_strncmp("unset", value, ft_strlen(value)) == 0)
		execute_unset(data, i, token);
	else if (ft_strncmp("env", value, ft_strlen(value)) == 0)
		execute_env(data, token);
	else if (ft_strncmp("exit", value, ft_strlen(value)) == 0)
		execute_exit(data, i, token);
	else
		execute_executable(data, i, token, data->commands[i]->token_amount);
}

void		initialise_struct_elements(t_data *data, int command)
{
	data->args = 0;
	data->commands[command]->error_flag = 0;
}

void		execution_loop(t_data *data, int command, int token)
{
	char	*value;

	value = data->commands[command]->tokens[token];
	while (command < data->command_amount)
	{
		token = 0;
		initialise_struct_elements(data, command);
		while (token < data->commands[command]->token_amount)
		{
			shell_expansions(data, command, token);
			if (redirections(data, command, token) != -1)
			{
				update_arguments_list(data, command, token, 0);
				value = data->commands[command]->tokens[token];
				if (data->commands[command]->token_amount > 0)
					identify_command(data, command, &token, value);
			}
		}
		command++;
	}
	free_struct(data);
}
