/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:49:34 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/29 17:07:39 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_echo(t_data *data, int i, int *token, int needed_tokens)
{
	int		newline;
	int		type;
	int		index;

	(*token)++;
	create_fd(data, i, (*token), &needed_tokens, data->fd);
	while(redirection_check(data->commands[i]->tokens[(*token)]) == redirected)
		(*token) += 2;
	newline = newline_option(data->commands[i]->tokens[(*token)], needed_tokens,
																		token);
	while((*token) < needed_tokens)
	{
		type = quotes_check(data->commands[i]->tokens[(*token)]);
		index = 0;
		if (type == normal_char)
			no_quotes(data, i, token, &index);
		else if (type == double_quote)
			double_quotes(data, i, token, &index);
		else if (type == single_quote)
			single_quotes(data, i, token, &index);
		if ((*token) != (needed_tokens - 1))
			print_char(data->fd[1], ' ');
		(*token)++;
	}
	if (!newline)
		print(data->fd[1], "\n");
	return ;
}

int	newline_option(char *value, int needed_tokens, int *token)
{
	if (!value)
		return (0);
	else if (ft_strncmp("-n", value, ft_strlen(value)) == 0)
	{
		((*token) < needed_tokens ) ? (*token)++ : (*token);
		return (1);
	}
	else
		return (0);
}

void	echo_variable(t_data *data, int i, int *token, int *index)
{
	char 	*value;
	char 	*variable;
	int		x;

	x = 0;
	value = data->commands[i]->tokens[(*token)];
	(*index)++;
	variable = get_variable(data, value, (*index), 0, 0);
	while(value[(*index)] != '\0' && value[(*index) + 1] != ' ')
		(*index)++;
	if (!variable)
		return ;
	while (variable[x] != '\0')
	{
		print_char(data->fd[1], variable[x]);
		x++;
	}
}

char	*get_variable(t_data *data, char *value, int index, int i, int len)
{
	char	*variable;
	int		env_size;
	int		var_len;

	env_size = get_array_size(data->env);
	while(value[index + len] != '\0')
		len++;
	variable = ft_substr(value, index, len);
//	CLEAR STRUCT WHEN FAIL
//
	while (i < env_size)
	{
		if (ft_strncmp(data->env[i], variable, ft_strlen(variable)) == 0)
		{
			free(variable);
			var_len = ft_strlen(data->env[i]);
			variable = ft_substr(data->env[i], (len + 1), (var_len - len - 1));
			//	CLEAR STRUCT WHEN FAIL
			//
			return (variable);
		}
		i++;
	}
	free(variable);
	return (0);
}
