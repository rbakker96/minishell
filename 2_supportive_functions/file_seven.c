/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_seven.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/22 14:10:21 by rbakker       #+#    #+#                 */
/*   Updated: 2020/11/02 11:44:08 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		command_check(char check_value, char charachter)
{
	if (charachter == check_value || charachter == '|' || charachter == ';' ||
		charachter == '\0')
		return (-1);
	else
		return (0);
}

int		redirection_check(char *str)
{
	if (!str)
		return (0);
	else if (ft_strncmp(str, "<", ft_strlen(str)) == 0)
		return (redirected);
	else if (ft_strncmp(str, ">", ft_strlen(str)) == 0)
		return (redirected);
	else if (ft_strncmp(str, ">>", ft_strlen(str)) == 0)
		return (redirected);
	return (0);
}

int		quotes_check(char *str)
{
	if (str[0] == '\"')
		return (double_quote);
	else if (str[0] == '\'')
		return (single_quote);
	else
		return (normal_char);
}

int		envp_new_value_check(char *new_envp)
{
	int i;

	i = 0;
	while (new_envp[i] != '\0')
	{
		if (new_envp[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int		unique_var(t_data *data, char *var)
{
	int		envp_size;
	int		var_len;
	int		i;

	envp_size = get_array_size(data->envp);
	var_len = token_var_len(var, 0);
	i = 0;
	while (i < envp_size)
	{
		if (ft_strncmp(data->envp[i], var, var_len) == 0
			&& data->envp[i][var_len] == '=')
			return (1);
		i++;
	}
	return (0);
}
