/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:23:47 by roybakker         #+#    #+#             */
/*   Updated: 2020/10/06 17:41:58 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	save_tokens(t_data *data, char **array, char *command, int i, int len)
{
	int start;
	int index;
	int spaces;
	int c;

	c = 0;
	index = 0;
	while (command[c] == ' ' && command[c] != '\0')
		c++;
	while (command[c] != '\0' && index < data->commands[i]->token_amount)
	{
		spaces = 0;
		start = begin_token(command, c);
		len = len_token(command, start, 0, &spaces);
		data->commands[i]->tokens[index] = ft_substr(command, start, len);
		printf("token [%d] = [%s]\n", index, data->commands[i]->tokens[index]);
		if (data->commands[i]->tokens[index] == NULL)
			malloc_error(data, i, array);
		c += len + spaces;
		index++;
	}
	data->commands[i]->tokens[index] = 0;
}

int		begin_token(char *command, int i)
{
	while (command[i] == ' ' && command[i] != '\0')
		i++;
	return (i);
}

int		len_token(char *command, int start, int len, int *spaces)
{
	if (token_id(command[start]) == meta_char)
	{
		start++;
		len = (command[start] == '>' && command[start - 1] == '>') ? 2 : 1;
		if (len == 2)
			start++;
		if (token_id(command[start]) == space)
			(*spaces)++;
	}
	else
		len = len_sentence(command, start, len, spaces);
	return (len);
}

int		len_sentence(char *command, int start, int len, int *spaces)
{
	int current_char;

	while (command[start + len] != '\0')
	{
		current_char = token_id(command[start + len]);
		if (current_char == normal_char)
			non_quoted_len(command, start, &len, &current_char);
		else if (current_char == double_quote || current_char == single_quote)
			quoted_len(command, start, &len, &current_char);
		else if (token_id(command[start + len] == meta_char))
			break ;
		if (current_char == space)
		{
			(*spaces)++;
			return (len);
		}
	}
	return (len);
}

void	non_quoted_len(char *command, int start, int *len, int *current_char)
{
	while ((*current_char) == normal_char && command[start + (*len)] != '\0')
	{
		if (command[start + (*len)] == '\\')
			(*len) += 2;
		else
			(*len)++;
		*current_char = token_id(command[start + (*len)]);
	}
}

void	quoted_len(char *command, int start, int *len, int *current_char)
{
	int quotes;
	int	quote_type;

	quotes = 1;
	quote_type = (*current_char);
	(*len)++;
	*current_char = token_id(command[start + (*len)]);
	while (quotes != 0 && command[start + (*len)] != '\0')
	{
		if ((*current_char) == quote_type)
			quotes--;
		if (command[start + (*len)] == '\\' && quote_type != 3)
			(*len) += 2;
		else
			(*len)++;
		*current_char = token_id(command[start + (*len)]);
	}
}
