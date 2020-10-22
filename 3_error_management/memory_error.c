/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memory_error.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/05 10:19:20 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/22 14:20:21 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	malloc_error(t_data *data, int cmd, char **malloced_array)
{
	int i;

	i = 0;
	cmd++;
	print(data, 2, "minishell : error due to malloc failure\n", 0);
	free(data->input);
	if (malloced_array)
		free_array(malloced_array);
	if (data->envp)
		free_array(data->envp);
	if (data->args)
		free_array(data->args);
	while (i < cmd)
	{
		free_array(data->commands[i]->tokens);
		free(data->commands[i]);
		i++;
	}
	free(data->commands);
	exit(1);
}

void	envp_malloc_error(t_data *data, char **failed_envp)
{
	if (failed_envp)
		free_array(failed_envp);
	print(data, 2, "minishell : error due to malloc failure\n", 0);
	exit(1);
}
