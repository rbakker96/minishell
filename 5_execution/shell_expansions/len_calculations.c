/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_calculations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 21:08:41 by roybakker         #+#    #+#             */
/*   Updated: 2020/10/06 17:09:11 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	single_quotes_len(char *token, int *i, int *len)
{
	(*i)++;
	while (token[(*i)] != '\'')
	{
		(*i)++;
		(*len)++;
	}
	(*i)++;
}

void	double_quotes_len(t_data *data, char *token, int *i, int *len)
{
	(*i)++;
	while (token[(*i)] != '\"')
	{
		if (token[(*i)] == '\\')
			(*len) += escape_len_double_quotes(token, i, 0);
		else if (token[(*i)] == '$')
		{
			(*len) += env_variable_len(data, token, i, 0);
			(*i) += env_var_len(token, (*i));
		}
		else
		{
			(*i)++;
			(*len)++;
		}
	}
	(*i)++;
}

int		escape_len_double_quotes(char *token, int *i, int len)
{
	(*i)++;
	if (token[(*i)] == '$' || token[(*i)] == '`' || \
		token[(*i)] == '\"' || token[(*i)] == '\\')
		len = 1;
	else
		len = 2;
	(*i)++;
	return (len);
}

int		env_variable_len(t_data *data, char *token, int *i, int len)
{
	char	*variable;
	int		var_len;
	int		x;

	(*i)++;
	var_len = 0;
	var_len = env_var_len(token, (*i));
	variable = ft_substr(token, (*i), var_len);
	if (variable == NULL)
		return (-1); // add ;ater
	x = 0;
	while (x < get_array_size(data->envp))
	{
		if (ft_strncmp(data->envp[x], variable, ft_strlen(variable)) == 0)
		{
			len = ft_strlen(data->envp[x]) - ft_strlen(variable) - 1;
			free(variable);
			return (len);
		}
		x++;
	}
	free(variable);
	return (len);
}
