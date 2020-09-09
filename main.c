/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 10:42:36 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/09 14:50:00 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "minishell.h"

int		main(void)
{
	t_data	data;

	while(1)
	{
		prompt();
		parse_command(&data);
		execution_loop(&data, 0, 0);
	}
	return (0);
}
