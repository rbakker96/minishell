/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:50:49 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/20 21:40:23 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_unset(t_data *data, int cmd, int tkn, int needed_tokens)
{
	int		index;
	int		x;
	int		envp_size;
	char	*string;
	char	**new_envp;

	index = 0;
	x = 0;
	needed_tokens =calculate_needed_tokens(data, cmd, tkn);
	if (needed_tokens == 1)
		return ;
	envp_size = get_array_size(data->envp);
	string = data->commands[cmd]->tokens[tkn + 1];
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


//thing to do
// -> whole variable until = sign needs to be the same
// -> if centrain the unset value is there malloc one spot les
// -> if no arguments nothing happens if not found nothing happens
// -> look at other egde cases what can be input and what causes error message
