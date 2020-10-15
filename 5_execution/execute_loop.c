/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 16:36:24 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/15 16:59:33 by qli           ########   odam.nl         */
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
		//create_pipe_fd(data, cmd); - ROY
		// initialize_pipes(data, cmd); - ROY
		tkn = 0;
		while (tkn < data->commands[cmd]->token_amount)
		{
			//set iostream to replace -> redirections(data, cmd, tkn) != -1 - ROY
			// update_token_list(data, cmd, tkn, 0); //remove > < tokens, do not remove non-existing tokens - ROY
			// data->iostream[READ] / data->iostream[WRITE]
			tkn = 0;
			value = data->commands[cmd]->tokens[tkn];
			// QING process below
			//fork()
			// child process
				// close_not_used_fds()
				// execute_command(data, cmd, &tkn, value);
				// exit();
			// parent process
				// close_used_fds()
				// data->pipe_pos++;
				// wait(&status);
		}
		cmd++;
	}
	free_struct(data);
}
