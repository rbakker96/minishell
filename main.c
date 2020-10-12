/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 10:42:36 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/12 15:15:56 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "minishell.h"

int		main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 1 || !argv)
	{
		print(&data, 1, "Only the executable ./minishell is sufficient\n", 0);
		return (-1);
	}
	while (1)
	{
		prompt(&data);
		if (parse_command(&data, envp) != -1)
			execution_loop(&data, 0, 0);
	}
	return (0);
}
