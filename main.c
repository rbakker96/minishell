/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 10:42:36 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/03 14:28:23 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "minishell.h"
#include <stdio.h>

// also made some changes

int		main(void)
{
	t_data	data;

	while(1)
	{
		print("minishel :: ");
		parse_command(&data);
	}
	return (0);
}
