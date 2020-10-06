/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_expansions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 19:44:06 by roybakker         #+#    #+#             */
/*   Updated: 2020/10/06 17:34:18 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	shell_expansions(t_data *data, int i, int token)
{
	int		len;
	char	*new_token;

	len = 0;
	while (token < data->commands[i]->token_amount)
	{
		data->current_token = data->commands[i]->tokens[token];
		len = expansion_len(data, 0, 0);
		new_token = malloc(sizeof(char) * (len + 1));
		if (new_token == NULL)
			return ; // add later
		expand_token(data, &new_token, 0, 0);
		free(data->commands[i]->tokens[token]);
		data->commands[i]->tokens[token] = new_token;
		printf("new token [%d] = %s\n", token, data->commands[i]->tokens[token]);
		token++;
	}
}

int		expansion_len(t_data *data, int i, int len)
{
	while (data->current_token[i] != '\0')
	{
		if (data->current_token[i] == '\'')
			single_quotes_len(data->current_token, &i, &len);
		else if (data->current_token[i] == '\"')
			double_quotes_len(data, data->current_token, &i, &len);
		else if (data->current_token[i] == '$')
		{
			len += env_variable_len(data, data->current_token, &i, 0);
			i += env_var_len(data->current_token, i);
		}
		else if (data->current_token[i] == '\\')
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

void	expand_token(t_data *data, char **new_token, int i, int x)
{
	while (x < expansion_len(data, 0, 0))
	{
		if (data->current_token[i] == '\'')
			single_quotes(data, new_token, &i, &x);
		else if (data->current_token[i] == '\"')
			double_quotes(data, new_token, &i, &x);
		else if (data->current_token[i] == '$')
		{
			env_variable(data, new_token, &i, &x);
			i += env_var_len(data->current_token, i);
		}
		else if (data->current_token[i] == '\\')
		{
			i++;
			(*new_token)[x] = data->current_token[i];
			x++;
			i++;
		}
		else
		{
			(*new_token)[x] = data->current_token[i];
			x++;
			i++;
		}
	}
	(*new_token)[x] = '\0';
}
