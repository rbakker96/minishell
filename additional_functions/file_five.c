/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_five.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 16:44:49 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/14 13:30:44 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		get_array_size(char **array)
{
	int 	i;

	i = 0;
	while (array[i] != 0)
		i++;
	return (i);
}
