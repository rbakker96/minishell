/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 14:50:49 by roybakker         #+#    #+#             */
/*   Updated: 2020/10/06 10:33:37 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_unset(t_data *data, int i, int *token)
{
	int		index;
	int		x;
	int		envp_size;
	char	*string;
	char	**new_envp;

	index = 0;
	x = 0;
	envp_size = get_array_size(data->envp);
	string = data->commands[i]->tokens[(*token) + 1];
	new_envp = (char**)malloc(sizeof(char*) * (envp_size + 1));
	while (index < envp_size)
	{
		if (ft_strncmp(data->envp[index], string, ft_strlen(string)) == 0)
			x++;
		if (data->envp[index + x] == 0)
			break ;
		new_envp[index] = ft_strdup(data->envp[index + x]);
		if (new_envp[index] == NULL)
			malloc_error(data, data->command_amount, new_envp);
		index++;
	}
	new_envp[index] = 0;
	free_array(data->envp);
	data->envp = new_envp;
}

// have to update token correctly
// have to check if input value of export is correct
// free old env if needed
