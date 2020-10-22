/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memory_error.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/05 10:19:20 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/22 14:54:20 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	malloc_error(t_data *data, int cmd, char **malloced_array)
{
	int i;

	i = 0;
	cmd++;
	print(data, 2, "minishell : error due to malloc failure\n", 0);
	g_exit_code = 1;
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
