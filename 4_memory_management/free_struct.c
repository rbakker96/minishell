/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 10:27:35 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/22 13:18:34 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_struct(t_data *data)
{
	int i;

	i = 0;
	while (i < data->command_nb)
	{
		free_array(data->commands[i]->tokens);
		free(data->commands[i]);
		i++;
	}
	if (data->command_nb != 0)
		free(data->commands);
	if (data->args)
		free_array(data->args);
	free(data->input);
	// free_array(data->envp);
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
