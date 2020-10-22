/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 10:42:36 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/22 14:58:43 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 1 || !argv)
		return (-1);
	initialize(&data);
	signal_handler();
	while (1)
	{
		prompt(&data);
		if (parse_command(&data, envp) != -1)
			execution_loop(&data, 0, 0);
		// printf("g_exit_code is %d\n", g_exit_code);
	}
	return (0);
}
