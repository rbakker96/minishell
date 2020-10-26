/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:50:36 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/26 14:53:28 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_export(t_data *data, int cmd, int tkn)
{
	int		envp_size;
	char	**new_envp;

	execute_unset(data, cmd, tkn, 0);
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
		while (ft_isalpha(value[i]))
			i++;
		if (value[i] == '=')
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

int		validate_export_token(char *token)
{
	int i;

	i = 0;
	while (ft_isalpha(token[i]))
		i++;
	if (token[i] == '=' && i != 0)
		return (valid);
	else if (token[i] == '\0')
		return (0);
	else
		return (error);
}

void	add_new_env_to_envp(t_data *data, char **new_envp, int cmd, int tkn)
{
	int ret;
	int i;

	i = get_array_size(data->envp);
	while (tkn < calculate_needed_tokens(data, cmd, 0))
	{
		ret = validate_export_token(data->commands[cmd]->tokens[tkn]);
		if (ret == valid)
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
