/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:50:49 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/09 17:29:50 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_unset(t_data *data, int command, int *token)
{
	int index;
	int i;
	int env_size;
	char *string;
	char **new_env;

	index = 0;
	i = 0;
	env_size = get_array_size(data->env) - 1;
	string = data->commands[command]->tokens[(*token) + 1];
	new_env = (char**)malloc(sizeof(char*) * env_size);
	while (index < env_size)
	{
		printf("i = %d\n", i);
		if (ft_strncmp(new_env[index], string, ft_strlen(string))== 0)
			i++;
		new_env[index] = ft_strdup(data->env[index + i]);
//		CLEAR STRUCT WHEN FAIL
//
		index++;
	}
	data->env = new_env;
	if (command && (*token))
		print(".");
}

// have to update token correctly
// have to check if input value of export is correct
// free old env if needed
