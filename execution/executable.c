/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executable.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:06:18 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/09 15:54:30 by roybakker     ########   odam.nl         */
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

void	execute_executable(t_data *data, int command, int *token)
{
	int	pid;
	int status;
	int errno;
	char *args[] = {"data->commands[command]->tokens[(*token)]", NULL};
	char *env[] = {NULL};

	if (data)
	pid = fork();
//	CLEAR STRUCT WHEN FAIL
//
	if (pid == 0)
	{
		execve(data->commands[command]->tokens[(*token)], args, env);
		if (errno == ENOENT)
			print("Executable not found in the current directory\n");
		else if (errno == ENOMEM)
			print("Not enough memory to execute the executable\n");
		else
			printf("error #%d trying to execute the executable\n", errno);
	}
	wait(&status);
	return ;
}
