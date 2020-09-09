/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_command.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/04 15:02:22 by qli           #+#    #+#                 */
/*   Updated: 2020/09/09 11:21:50 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// ** To use the executable within the bin folder **
// int main(void)
// {
// 	char *args[] = {"/usr/bin/ls", "-la", NULL};
// 	char *envp[] = {NULL};
// 	execve(args[0], args, envp);
// }

int		execute_executable(t_data *data)
{
	int	pid;
	int status;
	int errno;
	char *args[] = {"data->commands[data->i]->tokens[0]", NULL};
	char *env[] = {NULL};

	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
	{
		execve(args[0], args, env);
		if (errno == ENOENT)
			print("Executable not found in the current directory\n");
		else if (errno == ENOMEM)
			print("Not enough memory to execute the executable\n");
		else
			printf("error #%d trying to execute the executable\n", errno);
	}
	wait(&status);
	return (0);
}

int		execute_command(t_data *data)
{
	if (check_executable_path(data->commands[data->i]->tokens[0]) == 0)
		execute_executable(data);
	if (ft_strncmp("pwd", data->commands[data->i]->tokens[0], 3) == 0)
		execute_pwd();
	return (0);
}
