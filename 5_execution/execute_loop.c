/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 16:36:24 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/19 15:27:38 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execution_loop(t_data *data, int cmd, int tkn)
{
	int		status;

	while (cmd < data->command_amount)
	{
		preform_shell_expansions(data, cmd, 0);
		initialize_pipes(data, cmd);
		while (tkn < data->commands[cmd]->token_amount)
		{
			if (set_iostream(data, cmd, tkn) == -1)
				break ;
			update_token_list(data, cmd, &tkn);
			if (!data->commands[cmd]->pipe_nb && identify_custom(data, cmd, tkn))
				execute_command(data, cmd, &tkn);
			else
				fork_command(data, cmd, &tkn);
			close_used_fds(data, cmd);
			update_token_position(data, cmd, &tkn);
			data->commands[cmd]->pipe_pos++;
		}
		close_all_fds(data, cmd);
		while (wait(&status) > 0) //removed ;
		if (WIFEXITED(status))
		{
			printf("exit->code set by WEXITSTATUS\n");
			data->exit_code = WEXITSTATUS(status);
		}
		// if (WCOREDUMP(status) > 0)
		// {
		// 	printf("HERE 3\n");
		// 	data->exit_code = 1;
		// }
		// if (WIFSTOPPED(status))
		// 	printf("Child stopped because of signal number %d.\n", WSTOPSIG(status));
		cmd++;
	}
	free_struct(data);
}

void	fork_command(t_data *data, int cmd, int *tkn)
{
	int pid;

	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		close_not_used_fds(data, cmd);
		if (dup2(data->iostream[READ], STDIN) == -1)
			exit(1);
		if (dup2(data->iostream[WRITE], STDOUT) == -1)
			exit(1);
		execute_command(data, cmd, tkn);
		exit(0); //needs to set the exit code for custom functions
	}
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
		run_executable(data, cmd, tkn);
}
