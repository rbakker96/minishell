/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 10:42:36 by roybakker     #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2020/09/03 15:01:49 by roybakker     ########   odam.nl         */
=======
/*   Updated: 2020/09/03 15:11:41 by qli           ########   odam.nl         */
>>>>>>> 02432e6cc341da81b5353fb0d5cc58068adda42a
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "minishell.h"
#include <stdio.h>

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
