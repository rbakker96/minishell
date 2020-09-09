/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 10:42:36 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/09 15:55:15 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "minishell.h"

int		main(int argc, char **argv, char **envp)
{
	t_data	data;

	data.env = envp;
	while(1)
	{
		prompt();
		parse_command(&data);
		execution_loop(&data, 0, 0);
	}
	return (0);
}
