/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/04 15:02:22 by qli           #+#    #+#                 */
/*   Updated: 2020/10/12 16:35:17 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//update token position in each execute function
void	execute_command(t_data *data, int cmd, int *tkn, char *value)
{
	printf("current token is [%s]\n", data->commands[cmd]->tokens[*tkn]);
	if (ft_strncmp("echo", value, ft_strlen(value)) == 0)
		execute_echo(data, cmd, tkn, 0);
	else if (ft_strncmp("cd", value, ft_strlen(value)) == 0)
		execute_cd(data, cmd, tkn, data->commands[cmd]->token_amount);
	else if (ft_strncmp("pwd", value, ft_strlen(value)) == 0)
		execute_pwd(data, cmd, tkn, data->commands[cmd]->token_amount);
	else if (ft_strncmp("export", value, ft_strlen(value)) == 0)
		execute_export(data, cmd, tkn);
	else if (ft_strncmp("unset", value, ft_strlen(value)) == 0)
		execute_unset(data, cmd, tkn);
	else if (ft_strncmp("env", value, ft_strlen(value)) == 0)
		execute_env(data, tkn);
	else if (ft_strncmp("exit", value, ft_strlen(value)) == 0)
		execute_exit(data, cmd, tkn);
	else
		execute_executable(data, cmd, tkn);
}

void		initialise_struct_elements(t_data *data, int cmd)
{
	data->args = 0;
	data->commands[cmd]->error_flag = 0;
	data->pipe_num = 0;
	data->pipe_pos = 0;
}

void		execution_loop(t_data *data, int cmd, int tkn)
{
	char	*value;

	while (cmd < data->command_amount)
	{
		initialise_struct_elements(data, cmd);
		shell_expansions(data, cmd, 0);
		create_pipe_fd(data, cmd);
		while (tkn < data->commands[cmd]->token_amount)
		{
			if (redirections(data, cmd, tkn) != -1)
			{
				update_token_list(data, cmd, tkn, 0);
				tkn = 0;
				value = data->commands[cmd]->tokens[tkn];
				if (value != NULL)
					execute_command(data, cmd, &tkn, value);
				data->pipe_pos++;
			}
		}
		cmd++;
	}
	free_struct(data);
}
