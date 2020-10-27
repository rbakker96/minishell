/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 10:42:36 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/27 21:41:23 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 1 || !argv)
	{
		print(&data, 2, "only ./minishell is needed\n", 0);
		return (-1);
	}
	initialize(&data);
	signal_handler();
	while (1)
	{
		if (g_exit_code == -1)
		{
			clear_memory(&data);
			exit(1);
		}
		prompt(&data);
		if (parse_command(&data, envp) != -1)
			execution_loop(&data, 0, 0);
		//printf("g_exit_code : [%d]\n", g_exit_code);
	}
	return (0);
}
