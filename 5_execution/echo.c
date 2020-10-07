/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 14:49:34 by roybakker         #+#    #+#             */
/*   Updated: 2020/10/07 13:32:36 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_echo(t_data *data, int i, int *token, int needed_tokens)
{
	char	*value;
	int		newline;

	(*token)++;
	value = data->commands[i]->tokens[(*token)];
	newline = 1;
	while ((*token) < needed_tokens)
	{
		print(data, data->fd[1], data->commands[i]->tokens[(*token)], 0);
		print(data, data->fd[1], " ", 0);
		(*token)++;
	}
	if (newline)
		print_char(data, 1, '\n', 0);
	return ;
}


// void	execute_echo(t_data *data, int i, int *token, int needed_tokens)
// {
// 	int		newline;
// 	int		type;
// 	int		index;

// 	(*token)++;
// 	create_fd(data, i, (*token), &needed_tokens);
// 	if (data->commands[i]->error_flag == -1)
// 	{
// 		(*token) = data->commands[i]->token_amount;
// 		return ;
// 	}
// 	while(redirection_check(data->commands[i]->tokens[(*token)]) == redirected)
// 		(*token) += 2;
// 	newline = newline_option(data->commands[i]->tokens[(*token)], needed_tokens,
// 																		token);
// 	while((*token) < needed_tokens)
// 	{
// 		type = quotes_check(data->commands[i]->tokens[(*token)]);
// 		index = 0;
// 		if (type == normal_char)
// 			no_quotes(data, i, token, &index);
// 		else if (type == double_quote)
// 			double_quotes(data, i, token, &index);
// 		else if (type == single_quote)
// 			single_quotes(data, i, token, &index);
// 		if ((*token) != (needed_tokens - 1))
// 			print_char(data, data->fd[1], ' ', 0);
// 		if ((*token) < needed_tokens)
// 			(*token)++;
// 	}
// 	if (!newline)
// 		print_char(data, data->fd[1], '\n', 0);
// 	return ;
// }

// int	newline_option(char *value, int needed_tokens, int *token)
// {
// 	if (!value)
// 		return (0);
// 	else if (ft_strncmp("-n", value, ft_strlen(value)) == 0)
// 	{
// 		((*token) < needed_tokens) ? (*token)++ : (*token);
// 		return (1);
// 	}
// 	else
// 		return (0);
// }

// void	echo_variable(t_data *data, int i, int *token, int *index)
// {
// 	char 	*value;
// 	char 	*variable;
// 	int		x;

// 	x = 0;
// 	value = data->commands[i]->tokens[(*token)];
// 	(*index)++;
// 	variable = get_variable(data, value, (*index), 0, 0);
// 	if (variable == NULL)
// 		malloc_error(data, data->command_amount, 0);
// 	while(value[(*index)] != '\0' && value[(*index) + 1] != ' ' && value[(*index) + 1] != '\"')
// 		(*index)++;
// 	while (variable[x] != '\0')
// 	{
// 		print_char(data, data->fd[1], variable[x], variable);
// 		x++;
// 	}
// 	free(variable);
// }

// char	*get_variable(t_data *data, char *value, int index, int i, int len)
// {
// 	char	*variable;
// 	int		envp_size;
// 	int		var_len;

// 	envp_size = get_array_size(data->envp);
// 	while (value[index + len] != '\0' && value[index + len] != '\"'  && value[index + len] != ' ')
// 		len++;
// 	variable = ft_substr(value, index, len);
// 	if (variable == NULL)
// 		return (0);
// 	while (i < envp_size)
// 	{
// 		if (ft_strncmp(data->envp[i], variable, ft_strlen(variable)) == 0)
// 		{
// 			free(variable);
// 			var_len = ft_strlen(data->envp[i]);
// 			variable = ft_substr(data->envp[i], (len + 1), (var_len - len - 1));
// 			if (variable == NULL)
// 				return (0);
// 			return (variable);
// 		}
// 		i++;
// 	}
// 	free(variable);
// 	return (0);
// }
