/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/04 15:02:22 by qli           #+#    #+#                 */
/*   Updated: 2020/09/10 17:58:30 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	identfy_command(t_data *data, int command, int *token)
{
	if(ft_strncmp("echo", data->commands[command]->tokens[(*token)], 4) == 0)
		execute_echo(data, command, token);
	else if(ft_strncmp("cd", data->commands[command]->tokens[(*token)], 2) == 0)
		execute_cd(data, command, token);
	else if(ft_strncmp("pwd", data->commands[command]->tokens[(*token)], 3) == 0)
		execute_pwd(data, command, token);
	else if(ft_strncmp("export", data->commands[command]->tokens[(*token)], 6) == 0)
		execute_export(data, command, token);
	else if(ft_strncmp("unset", data->commands[command]->tokens[(*token)], 5) == 0)
		execute_unset(data, command, token);
	else if(ft_strncmp("env", data->commands[command]->tokens[(*token)], 3) == 0)
		execute_env(data, command, token);
	else if(ft_strncmp("exit", data->commands[command]->tokens[(*token)], 4) == 0)
		execute_exit(data, command, token);
	else
		execute_executable(data, command, token);
}

void		execution_loop(t_data *data, int command, int token)
{
	while(command < data->command_amount)
	{
		token = 0;
		while(token < data->commands[command]->token_amount)
			identfy_command(data, command, &token);
		command++;
	}
	return ;
}
