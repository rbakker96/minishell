/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_executable.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 20:12:02 by qli           #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2020/10/19 13:36:39 by qli           ########   odam.nl         */
=======
/*   Updated: 2020/10/19 12:00:14 by rbakker       ########   odam.nl         */
>>>>>>> 3dab93c6ebbb9be54af5e6c9e28fcffd8ac908a0
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
}
