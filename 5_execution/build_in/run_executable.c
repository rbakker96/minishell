/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_executable.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 20:12:02 by qli           #+#    #+#                 */
/*   Updated: 2020/10/19 14:46:53 by qli           ########   odam.nl         */
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
		ft_printf("minishell : no abs path");
		exit (127); // no abs path
	}
	execve(data->args[0], data->args, data->envp);
	// print errno
	exit(1); // only error will come here
}
