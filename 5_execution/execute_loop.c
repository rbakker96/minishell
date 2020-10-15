/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 16:36:24 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/15 19:35:46 by qli           ########   odam.nl         */
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
		// discuss whether it's best to keep the 0 in local functions
		preform_shell_expansions(data, cmd, 0);
		initialize_pipes(data, cmd);
		tkn = 0;
		while (tkn < data->commands[cmd]->token_amount)
		{
			// set iostream to replace -> redirections(data, cmd, tkn) != -1 - ROY
			// QUESTION: Are all unrequired redirection fds already closed after this step?
			// update_token_list(data, cmd, tkn, 0); //remove > < tokens, do not remove non-existing tokens - ROY
			// QUESTION: updated token list will handle the token update right?
			// data->iostream[READ] / data->iostream[WRITE]
			tkn = 0;
			// QING process below
			pid = fork();
			if (pid == -1)
				fork_error(data, cmd);
			else if (pid == 0)
			{
				close_not_used_fds(data, cmd); // complete
				execute_command(data, cmd, &tkn); // to update the execute executable function
				// maybe need to free all the malloced memory available in the child process
				exit(1);
			}
			else
			{
				close_used_fds(data, cmd); // complete
				data->commands[cmd]->pipe_pos++;
				wait(&status);
			}
		}
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