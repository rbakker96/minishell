/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   external_function_error.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 14:33:38 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/05 15:10:47 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	fork_error(t_data *data, int index)
{
	int i;

	i = 0;
	index++;
	print(data, 2, "minishell : error due to fork failure\n", 0);
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

void	write_error(t_data *data, char *malloced_str)
{
	print(data, 2, "minishell : write function failed\n", 0);
	if (malloced_str)
		free(malloced_str);
	if (data->envp)
		free_array(data->envp);
	if (data->args)
		free_array(data->args);
	free_struct(data);
	exit(1);
}
