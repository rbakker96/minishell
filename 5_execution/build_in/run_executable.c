/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_executable.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 20:12:02 by qli           #+#    #+#                 */
/*   Updated: 2020/10/20 14:25:26 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	run_executable(t_data *data, int cmd, int *tkn)
{
	char *value;

	value = data->commands[cmd]->tokens[*tkn];
	if (value[0] == '\0')
	{
		close(data->iostream[READ]);
		close(data->iostream[WRITE]);
	}
	else
		create_args(data, cmd, *tkn);
	if (data->args[0] == NULL)
		print_special_errno(data, value, "command not found", 127);
	execve(data->args[0], data->args, data->envp);
	exit(1);
}
