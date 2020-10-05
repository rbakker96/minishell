/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memory_error.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/05 10:19:20 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/05 10:59:19 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	malloc_error(t_data *data, int index, char **malloced_array)
{
	int i;

	i = 0;
	index++;
	print(data, 2, "minishell : error due to malloc failure\n", 0);
	if (malloced_array)
		free_array(malloced_array);
	if (data->envp)
		free_array(data->envp);
	if (data->args)
		free_array(data->args);
	while(i < index)
	{
		free_array(data->commands[i]->tokens);
		free(data->commands[i]);
		i++;
	}
	free(data->commands);
	exit(1);
}
