/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 16:36:24 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/13 16:44:52 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//update token position in each execute function
void	execute_command(t_data *data, int cmd, int *tkn, char *value)
{
	printf("current token is [%s]\n", data->commands[cmd]->tokens[*tkn]);
	if (compare_command("echo", value, 4) == 0)
		execute_echo(data, cmd, tkn, 0);
	else if (compare_command("cd", value, 2) == 0)
		execute_cd(data, cmd, tkn, 0);
	else if (compare_command("pwd", value, 3) == 0)
		execute_pwd(data, cmd, tkn, 0);
	else if (compare_command("export", value, 6) == 0)
		execute_export(data, cmd, tkn);
	else if (compare_command("unset", value, 5) == 0)
		execute_unset(data, cmd, tkn);
	else if (compare_command("env", value, 3) == 0)
		execute_env(data, tkn);
	else if (compare_command("exit", value, 4) == 0)
		execute_exit(data, cmd, tkn);
	else
		execute_executable(data, cmd, tkn);
}

void		initialise_struct_elements(t_data *data)
{
	data->args = 0;
	data->pipe_num = 0;
	data->pipe_pos = 0;
}

void		execution_loop(t_data *data, int cmd, int tkn)
{
	char	*value;

	while (cmd < data->command_amount)
	{
		initialise_struct_elements(data);
		shell_expansions(data, cmd, 0);
		//create_pipe_fd(data, cmd);
		initialize_pipes(data, cmd);
		tkn = 0;
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
			else
				break ;
		}
		cmd++;
	}
	free_struct(data);
}
