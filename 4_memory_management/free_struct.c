/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 10:27:35 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/30 13:21:30 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_array(char **array)
{
	int i;

	i = 0;
	if (!array)
		return ;
	while (array[i] != 0)
			i++;
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

void	free_command_table(t_command_table **array)
{
	int i;

	i = 0;
	if (!array)
		return ;
	while (array[i] != 0)
			i++;
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}
