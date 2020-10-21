/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell_expansions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/05 19:44:06 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/21 19:40:15 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	preform_shell_expansions(t_data *data, int cmd, int tkn)
{
	int		len;
	char	*new_token;

	len = 0;
	while (tkn < data->commands[cmd]->token_amount)
	{
		data->current_token = data->commands[cmd]->tokens[tkn];
		len = expansion_len(data, 0, 0);
		new_token = malloc(sizeof(char) * (len + 1));
		if (new_token == NULL)
			malloc_error(data, data->command_amount, 0);
		expand_token(data, &new_token, 0, 0);
		free(data->commands[cmd]->tokens[tkn]);
		data->commands[cmd]->tokens[tkn] = new_token;
		printf("updated token [%d] = %s\n", tkn, data->commands[cmd]->tokens[tkn]);
		tkn++;
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
			if (data->current_token[i + 1] == '?')
				len += exit_code_len(data, 0);
			else
				len += env_var_len(data, data->current_token, i, 0);
			i += token_var_len(data->current_token, i);
		}
		else
		{
			(data->current_token[i] == '\\') ? i += 2 : i++;
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
			if (data->current_token[i + 1] == '?')
				exit_code(data, new_token, &x);
			else
				env_variable(data, new_token, i, &x);
			i += token_var_len(data->current_token, i);
		}
		else
		{
			(data->current_token[i] == '\\') ? i++ : i;
			(*new_token)[x] = data->current_token[i];
			x++;
			i++;
		}
	}
	(*new_token)[x] = '\0';
}

void	exit_code(t_data *data, char **new_token, int *x)
{
	char	*exit_code;
	int		i;

	i = 0;
	exit_code = ft_itoa(g_exit_signal);
	if (exit_code == NULL)
		malloc_error(data, data->command_amount, 0);
	while (exit_code[i] != '\0')
	{
		(*new_token)[(*x)] = exit_code[i];
		(*x)++;
		i++;
	}
	free(exit_code);
}
