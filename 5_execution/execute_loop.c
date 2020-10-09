/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/04 15:02:22 by qli           #+#    #+#                 */
/*   Updated: 2020/10/09 17:33:14 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_command(t_data *data, int cmd, int *token, char *value)
{
	printf("current token is [%s]\n", data->commands[cmd]->tokens[*token]);
	printf("token number is [%d]\n", *token);
	if (ft_strncmp("echo", value, ft_strlen(value)) == 0)
		execute_echo(data, cmd, token, data->commands[cmd]->token_amount);
	else if (ft_strncmp("cd", value, ft_strlen(value)) == 0)
		execute_cd(data, cmd, token, data->commands[cmd]->token_amount);
	else if (ft_strncmp("pwd", value, ft_strlen(value)) == 0)
		execute_pwd(data, cmd, token, data->commands[cmd]->token_amount);
	else if (ft_strncmp("export", value, ft_strlen(value)) == 0)
		execute_export(data, cmd, token);
	else if (ft_strncmp("unset", value, ft_strlen(value)) == 0)
		execute_unset(data, cmd, token);
	else if (ft_strncmp("env", value, ft_strlen(value)) == 0)
		execute_env(data, token);
	else if (ft_strncmp("exit", value, ft_strlen(value)) == 0)
		execute_exit(data, cmd, token);
	else
		execute_executable(data, cmd, token, data->commands[cmd]->token_amount);
}

void		initialise_struct_elements(t_data *data, int cmd)
{
	data->args = 0;
	data->commands[cmd]->error_flag = 0;
	data->pipe_num = 0; //reset pipe number for each command
}

void		execution_loop(t_data *data, int cmd, int token)
{
	char	*value;

	value = data->commands[cmd]->tokens[token];
	while (cmd < data->command_amount)
	{
		token = 0;
		initialise_struct_elements(data, cmd);
		shell_expansions(data, cmd, token);
		while (token < data->commands[cmd]->token_amount)
		{
			if (redirections(data, cmd, token) != -1)
			{
				update_arguments_list(data, cmd, token, 0);
				create_pipe_fd(data, cmd);
				value = data->commands[cmd]->tokens[token];
				execute_command(data, cmd, &token, value);
			}
			//maybe update token to go past pipe
		}
		cmd++;
	}
	free_struct(data);
}
