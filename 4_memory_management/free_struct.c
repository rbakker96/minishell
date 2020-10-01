/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 10:27:35 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/01 11:34:09 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_struct(t_data *data)
{
	int i;

	i = 0;
	while (i < data->command_amount)
	{
		free_array(data->commands[i]->tokens);
		i++;
	}
	free_command_table(data->commands);
	//free_array(data->envp); -> only when export or unset is used
}

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
