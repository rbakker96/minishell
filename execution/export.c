/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:50:36 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/09 17:03:30 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_export(t_data *data, int command, int *token)
{
	int index;
	int	i;
	int env_size;
	char **new_env;

	i = 0;
	index = 0;
	env_size = get_array_size(data->env);
	new_env = (char**)malloc(sizeof(char*) * (env_size + 1));
	while (index < env_size)
	{
		new_env[index] = ft_strdup(data->env[index]);
//		CLEAR STRUCT WHEN FAIL
//
		index++;
	}
	new_env[index] = data->commands[command]->tokens[(*token) + 1];
	new_env[index + 1] = 0;
	data->env = new_env;
	if (command && (*token))
		print(".");
}
// have to update token correctly
// have to check if input value of export is correct
// free old env if needed
