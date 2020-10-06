/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 21:11:22 by roybakker         #+#    #+#             */
/*   Updated: 2020/10/06 17:10:18 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	single_quotes(t_data *data, char **new_token, int *i, int *x)
{
	char *token;

	token = data->current_token;
	(*i)++;
	while (token[(*i)] != '\'')
	{
		(*new_token)[(*x)] = token[(*i)];
		(*x)++;
		(*i)++;
	}
	(*i)++;
}

void	double_quotes(t_data *data, char **new_token, int *i, int *x)
{
	char *token;

	token = data->current_token;
	(*i)++;
	while ((*x) < expansion_len(data, 0, 0))
	{
		if (token[(*i)] == '\\')
			escape_double_quotes(data, new_token, i, x);
		else if (token[(*i)] == '$')
		{
			env_variable(data, new_token, i, x);
			(*i) += env_var_len(token, (*i));
		}
		else
		{
			(*new_token)[(*x)] = token[(*i)];
			(*x)++;
			(*i)++;
		}
	}
	(*i)++;
}

void	escape_double_quotes(t_data *data, char **new_token, int *i, int *x)
{
	char *token;

	token = data->current_token;
	(*i)++;
	if (token[(*i)] == '$' || token[(*i)] == '`' || \
		token[(*i)] == '\"' || token[(*i)] == '\\')
	{
		(*new_token)[(*x)] = token[(*i)];
		(*x)++;
		(*i)++;
	}
	else
	{
		(*new_token)[(*x) - 1] = token[(*i)];
		(*i)++;
		(*new_token)[(*x)] = token[(*i)];
		(*x)++;
		(*i)++;
	}
}

void	env_variable(t_data *data, char **new_token, int *i, int *x)
{
	char	*token;
	int		var_len;
	char	*variable;
	int		z;

	(*i)++;
	var_len = 0;
	token = data->current_token;
	var_len = env_var_len(token, (*i));
	variable = ft_substr(token, (*i), var_len);
	if (variable == NULL)
		return ; // add later
	z = 0;
	while (z < get_array_size(data->envp))
	{
		if (ft_strncmp(data->envp[z], variable, ft_strlen(variable)) == 0)
		{
			save_env_variable(data->envp[z], new_token, x);
			break ;
		}
		z++;
	}
	free(variable);
}

void	save_env_variable(char *variable, char **new_token, int *x)
{
	int i;

	i = 0;
	while (variable[i - 1] != '=')
		i++;
	while (variable[i] != '\0')
	{
		(*new_token)[(*x)] = variable[i];
		(*x)++;
		i++;
	}
}
