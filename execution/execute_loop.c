/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/04 15:02:22 by qli           #+#    #+#                 */
/*   Updated: 2020/09/23 11:41:14 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	identfy_command(t_data *data, int i, int *token, char *value)
{
	if(ft_strncmp("echo", value, ft_strlen(value)) == 0)
		execute_echo(data, i, token, data->commands[i]->token_amount);
	else if(ft_strncmp("cd", value, ft_strlen(value)) == 0)
		execute_cd(data, i, token);
	else if(ft_strncmp("pwd", value, ft_strlen(value)) == 0)
		execute_pwd(data, i, token);
	else if(ft_strncmp("export", value, ft_strlen(value)) == 0)
		execute_export(data, i, token);
	else if(ft_strncmp("unset", value, ft_strlen(value)) == 0)
		execute_unset(data, i, token);
	else if(ft_strncmp("env", value, ft_strlen(value)) == 0)
		execute_env(data, i, token);
	else if(ft_strncmp("exit", value, ft_strlen(value)) == 0)
		execute_exit(data, i, token);
	else
		execute_executable(data, i, token);
}

void		execution_loop(t_data *data, int command, int token)
{
	while(command < data->command_amount)
	{
		token = 0;
		while(token < data->commands[command]->token_amount)
			identfy_command(data, command, &token,
										data->commands[command]->tokens[token]);
		command++;
	}
	return ;
}
