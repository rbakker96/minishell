/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:50:36 by roybakker     #+#    #+#                 */
/*   Updated: 2020/11/02 11:55:46 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_export(t_data *data, int cmd, int tkn)
{
	int		envp_size;
	char	**new_envp;
	int		needed_tokens;

	needed_tokens = calculate_needed_tokens(data, cmd, tkn);
	if (needed_tokens == 1)
		print_export_output(data, get_array_size(data->envp), 0, 0);
	validate_export_token(data, cmd, tkn, needed_tokens);
	execute_unset(data, cmd, tkn, 0);
	tkn++;
	envp_size = get_envp_size(data, cmd, tkn);
	new_envp = (char**)malloc(sizeof(char*) * (envp_size + 1));
	if (new_envp == NULL)
		malloc_error(data, 0);
	copy_current_envp(data, new_envp);
	add_new_env_to_envp(data, new_envp, cmd, tkn);
	free_array(data->envp);
	data->envp = new_envp;
}

int		get_envp_size(t_data *data, int cmd, int tkn)
{
	char	*value;
	int		needed_tokens;
	int		size;
	int		i;

	size = get_array_size(data->envp);
	needed_tokens = calculate_needed_tokens(data, cmd, tkn);
	while (tkn < needed_tokens)
	{
		i = 0;
		value = data->commands[cmd]->tokens[tkn];
		while (ft_isalpha(value[i]) || value[i] == '_' || ft_isdigit(value[i]))
			i++;
		if (((value[i] == '=' && i != 0) || value[i] == '\0') &&
													!unique_var(data, value))
			size++;
		tkn++;
	}
	return (size);
}

void	copy_current_envp(t_data *data, char **new_envp)
{
	int envp_size;
	int index;

	index = 0;
	envp_size = get_array_size(data->envp);
	while (index < envp_size)
	{
		new_envp[index] = ft_strdup(data->envp[index]);
		if (new_envp[index] == NULL)
			malloc_error(data, new_envp);
		index++;
	}
}

void	validate_export_token(t_data *data, int cmd, int tkn, int needed_tokens)
{
	char	*value;
	int		i;

	while (tkn < needed_tokens)
	{
		i = 0;
		value = data->commands[cmd]->tokens[tkn];
		if (ft_isdigit(value[i]))
			print_unset_error(data, value);
		while (ft_isalpha(value[i]) || value[i] == '_' || ft_isdigit(value[i]))
			i++;
		if ((value[i] == '=' && i == 0) || (value[i] != '=' &&
			value[i] != '\0'))
			print_unset_error(data, value);
		tkn++;
	}
}

void	add_new_env_to_envp(t_data *data, char **new_envp, int cmd, int tkn)
{
	int i;

	i = get_array_size(data->envp);
	while (tkn < calculate_needed_tokens(data, cmd, 0))
	{
		if (save_token(data->commands[cmd]->tokens[tkn]) == save &&
			!unique_var(data, data->commands[cmd]->tokens[tkn]))
		{
			new_envp[i] = ft_strdup(data->commands[cmd]->tokens[tkn]);
			if (new_envp[i] == NULL)
				malloc_error(data, new_envp);
			i++;
		}
		tkn++;
	}
	new_envp[i] = 0;
}
