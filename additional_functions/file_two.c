/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_two.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/04 12:50:32 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/10 17:56:19 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		get_amount_of_commands(char *line, char c)
{
	char	**array;
	int 	i;

	i = 0;
	array = ft_split(line, c);
//	CLEAR STRUCT WHEN FAIL
//
	while (array[i] != 0)
		i++;
	free_split_array(array);
	return (i);
}

int			get_amount_of_tokens(char *command, int i, int token)
{
	while (command[i] == ' ' && command[i] != '\0')
		i++;
	while (command[i] != '\0')
	{
		if (token_id(command[i]) == 0)
			i++;
		else if (token_id(command[i]) == 1)
			special_char(command, &i, &token);
		else
			basic_word(command, &i, &token);
	}
	if (token == 0)
		return (1);
	return (token);
}

int			token_id(char c)
{
	if (c == ' ')
		return (0);
	else if (c == '>' || c == '<' || c == '|')
		return (1);
	else if (c == 34)
		return (2);
	else if (c == 39)
		return (3);
	else
		return (4);
}

int		begin_token(char *command, int i)
{
	while (command[i] == ' ' && command[i] != '\0')
		i++;
	return (i);
}


int		len_token(char *command, int start, int len, int *space)
{
	if(token_id(command[start]) == 1)
	{
		start++;
		len = (token_id(command[start]) == 1) ? 2 : 1;
		if (len == 2)
			start++;
		if (token_id(command[start]) == 2)
			(*space)++;
	}
	else
		len = len_sentence(command, start, len, space);
	return (len);
}

int		len_sentence(char *command, int start, int len, int *space)
{
	int quotes;
	int x;

	while(token_id(command[start + len]) == 4 && command[start + len] != '\0')
		len++;
	if (token_id(command[start + len]) == 2 || token_id(command[start + len]) == 3)
	{
		len++;
		x = token_id(command[start + len]);
		quotes = quotes_count(command, start, x);
		while((token_id(command[start + len]) != x || quotes != 0) && command[start + len] != '\0')
		{
			if (token_id(command[start + len]) != x)
				quotes--;
			len++;
		}
		len++;
	}
	if (token_id(command[start + len]) == 2)
		(*space)++;
	return (len);
}


//int		len_token(char *command, int start, int len, int *space)
//{
//	int x;
//
//	x = (token_id(command[start]) == 0) ? 0 : 1;
//	if (x != 0)
//		x = (token_id(command[start]) > 1) ? 3 : 1;
//	else if (x > 1)
//		x = (token_id(command[start]) > 3) ? 4 : 3;
//	if (token_id(command[start]) == x && x < 2)
//		while (token_id(command[start + len]) == x && command[start + len] != '\0')
//			len++;
//	if (x > 2)
//	{
//		len++;
//		while (token_id(command[start + len]) != x  && command[start + len] != '\0')
//			len++;
//		if (command[start + len] != '\0')
//			len++;
//	}
//	if (token_id(command[start + len]) == 2)
//		(*space)++;
//	return (len);
//}
