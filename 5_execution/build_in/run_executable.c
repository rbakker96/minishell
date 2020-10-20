/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_executable.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 20:12:02 by qli           #+#    #+#                 */
/*   Updated: 2020/10/20 08:46:31 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	run_executable(t_data *data, int cmd, int *tkn)
{
	create_args(data, cmd, *tkn);
	if (data->commands[cmd]->tokens[*tkn][0] == '\0')
	{
		close(data->iostream[READ]);
		close(data->iostream[WRITE]);
	}
	if (data->args[0] == NULL)
	{
		print_errno(data, cmd, data->args[0], 127);
		// ft_printf("minishell : command not found\n"); //this needs to change to print to 2
		// printf("came here\n");
		// exit (127); // no abs path
		// //update print errno str function
	}
	execve(data->args[0], data->args, data->envp);
	// print_errno(data, cmd, data->args[0], 1);
	exit(1);
}
