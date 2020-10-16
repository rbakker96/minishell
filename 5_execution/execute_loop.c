/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 16:36:24 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/16 13:53:45 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		execution_loop(t_data *data, int cmd, int tkn)
{
	char	*value;
	int		pid;
	int		status;

	while (cmd < data->command_amount)
	{
		preform_shell_expansions(data, cmd, 0);
		initialize_pipes(data, cmd);
		tkn = 0;
		while (tkn < data->commands[cmd]->token_amount)
		{
			// set iostream to replace -> redirections(data, cmd, tkn) != -1 - ROY
			update_token_list(data, cmd, tkn);
			tkn = 0;
			pid = fork();
			if (pid == -1)
				fork_error(data, cmd);
			else if (pid == 0)
			{
				close_not_used_fds(data, cmd);
				execute_command(data, cmd, &tkn);
				// free_struct(data); // also make sure to free args
				exit(1); // change the exit code later
			}
			else
			{
				close_used_fds(data, cmd);
				data->commands[cmd]->pipe_pos++;
				// if wait returns -1, need to handle run_executable_error
				// need to double check whether we closed all open files
			}
		}
		wait(&status);
		cmd++;
	}
	free_struct(data);
}

void	execute_command(t_data *data, int cmd, int *tkn)
{
	char	*value;

	value = data->commands[cmd]->tokens[*tkn];
	printf("current token is [%s]\n", value);
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