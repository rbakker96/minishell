/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 16:36:24 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/16 13:57:29 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		execution_loop(t_data *data, int cmd, int tkn)
{
	int		pid;
	int		status;

	while (cmd < data->command_amount)
	{
		preform_shell_expansions(data, cmd, 0);
		initialize_pipes(data, cmd);
		tkn = 0;
		while (tkn < data->commands[cmd]->token_amount)
		{
			if (set_iostream(data, cmd, tkn) == -1)
				break ;
			update_token_list(data, cmd, tkn);
			tkn = 0;
			pid = fork();
			if (pid == -1)
				exit(1);
			if (pid == 0)
			{
				close_not_used_fds(data, cmd); // complete
				execute_command(data, cmd, &tkn); // to update the execute executable function
				exit(1);
			}
			close_used_fds(data, cmd); // complete
			data->commands[cmd]->pipe_pos++;
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
