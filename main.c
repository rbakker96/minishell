/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 10:42:36 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/03 14:26:34 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "minishell.h"
#include <stdio.h>

// changes made by qli

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
