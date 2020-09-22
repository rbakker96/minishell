/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokens.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/19 13:23:47 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/22 14:30:13 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	save_tokens(t_data *data, char *command, int i, int len)
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
// 		CLEAR STRUCT WHEN FAIL
//
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
	if(token_id(command[start]) == meta_char)
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
	int quotes;
	int x;

	while(token_id(command[start + len]) == normal_char && command[start + len] != '\0')
		(command[start + len] == '\\') ? len += 2 : len++;
	if (token_id(command[start + len]) == double_quote || token_id(command[start + len]) == single_quote)
	{
		x = token_id(command[start + len]);
		quotes = quotes_count(command, start, x);
		len++;
		while(quotes != 0 && command[start + len] != '\0')
		{
			if (token_id(command[start + len]) == x)
				quotes--;
			if (command[start + len] == '\\')
				len += 2;
			else
				len++;
		}
		len++;
	}
	if (token_id(command[start + len]) == space)
		(*spaces)++;
	return (len);
}
