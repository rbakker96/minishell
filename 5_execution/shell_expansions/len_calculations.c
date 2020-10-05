/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   len_calculations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/05 21:08:41 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/05 21:18:01 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		expansion_len(t_data *data, char *token, int i, int len)
{
	while (token[i] != '\0')
	{
		if (token[i] == '\'')
			single_quotes_len(token, &i, &len);
		else if (token[i] == '\"')
			double_quotes_len(data, token, &i, &len);
		else if (token[i] == '$')
			len += env_variable_len(data, token, &i, i, 0);
		else if (token[i] == '\\')
		{
			len++;
			i += 2;
		}
		else
		{
			i++;
			len++;
		}
	}
	return (len);
}

void	single_quotes_len(char *token, int *i, int *len)
{
	(*i)++;
	while(token[(*i)] != '\'')
	{
		(*i)++;
		(*len)++;
	}
	(*i)++;
}

void	double_quotes_len(t_data *data, char *token, int *i, int *len)
{
	(i++);
	while (token[(*i)] != '\"')
	{
		if (token[(*i)] == '\\')
			len += escape_len_double_quotes(token, i, 0);
		else if (token[(*i)] == '$')
			len += env_variable_len(data, token, &i, i, 0);
		else
		{
			(*i)++;
			(*len)++;
		}
	}
	(i++);
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

int		env_variable_len(t_data *data, char *token, int *i, int x, int len)
{
	int		envp_size;
	char 	*variable;
	int		var_len;

	(*i)++;
	envp_size = get_array_size(data->envp);
	while(token[x + (*i)] != '\0' && token[x + (*i)] != ' ' &&
														token[x + (*i)] != '\"')
		(*i)++;
	variable = ft_substr(token, x, (*i));
	if (variable == NULL)
	//malloc error
	x = 0;
	while(x < envp_size)
	{
		if (ft_strncmp(data->envp[x], variable, ft_strlen(variable)) == 0)
		{
			free(variable);
			len = ft_strlen(data->envp[x]) - (*i) - 1;
			return (len);
		}
		x++;
	}
	free(variable);
	return (len);
}
