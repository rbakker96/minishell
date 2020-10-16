/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_executable.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 20:12:02 by qli           #+#    #+#                 */
/*   Updated: 2020/10/16 13:23:16 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_executable(t_data *data, int cmd, int *tkn)
{
	create_args(data, cmd, *tkn);
	// LOOK FURTHER: can we free the args before executing the child, if not, as need to move this to earlier stages
	// apparently execve wipes all the address memory of a child process
	// but maybe need to free the allocated memory when execve fails
	if (check_relative_path(data->commands[cmd]->tokens[*tkn]) == 1)
		run_executable(data);
		// if (run_executable(data, cmd)) // QUESTION: what does this mean?
		// 	run_executable_error(data, data->commands[cmd]->tokens[*tkn]); // this error is probably needed to be captured earlier
	else
		execute_absolute_executable(data, cmd, tkn);
}

void	execute_absolute_executable(t_data *data, int cmd, int *tkn)
{
	struct	stat stats;
	int		i;

	i = 0;
	while (create_path_array(data, cmd, *tkn, i) != -1)
	{
		if (stat(data->args[0], &stats) == 0)
		{
			run_executable(data);
			return ;
		}
		i++;
	}
	// run_executable_error(data, data->commands[cmd]->tokens[*tkn]);  // this error is probably needed to be captured earlier
}

void		run_executable(t_data *data)
{
	dup2(data->iostream[0], 0);
	dup2(data->iostream[1], 1);
	execve(data->args[0], data->args, data->envp);
}
