/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_loop.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/12 16:36:24 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/19 13:42:26 by qli           ########   odam.nl         */
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
		run_command(data, cmd, &tkn);
		close_all_fds(data, cmd);
		while (wait(&status) > 0);
		if (WIFEXITED(status)) //returns a nonzero value if the child process terminated normally with exit
			printf("Child exited with exit status %d.\n", WEXITSTATUS(status));
			//if WIFEXITED is true of status, WEXITSTATUS returns the low-order 8 bits of the exit status value from the child process
		if (WCOREDUMP(status) > 0) //returns a nonzero value if the child process terminated and produced a core dump
			printf("The child process terminated and produced a core dump. \n");
		if (WIFSTOPPED(status)) //returns a nonzero value if the child process is stopped
			printf("Child stopped because of signal number %d.\n", WSTOPSIG(status));
			// If WIFSTOPPED is true of status, WSTOPSIG returns the signal number of the signal that caused the child process to stop. 
		cmd++;
	}
	free_struct(data);
}

void	run_command(t_data *data, int cmd, int *tkn)
{
	int		pid;

	while ((*tkn) < data->commands[cmd]->token_amount)
	{
		if (set_iostream(data, cmd, (*tkn)) == -1)
			break ;
		update_token_list(data, cmd, tkn);
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
			identify_command(data, cmd, tkn);
			exit(1); //needs to set the exit code for custom functions
		}
		close_used_fds(data, cmd);
		update_token_position(data, cmd, tkn);
		data->commands[cmd]->pipe_pos++;
	}
}

void	identify_command(t_data *data, int cmd, int *tkn)
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
