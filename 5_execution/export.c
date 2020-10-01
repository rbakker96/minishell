/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:50:36 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/01 17:00:46 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_export(t_data *data, int i, int *token)
{
	int index;
	int envp_size;
	char **new_envp;

	index = 0;
	envp_size = get_array_size(data->envp);
	new_envp = (char**)malloc(sizeof(char*) * (envp_size + 2));
	while (index < envp_size)
	{
		new_envp[index] = ft_strdup(data->envp[index]);
		if (new_envp[index] == NULL)
			malloc_error(data, data->command_amount, new_envp);
		index++;
	}
	new_envp[index] = data->commands[i]->tokens[(*token) + 1];
	new_envp[index + 1] = 0;
	data->envp = new_envp;
}
// have to update token correctly
// have to check if input value of export is correct
// free old env if needed
