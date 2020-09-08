/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_two.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/04 12:50:32 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/08 16:08:57 by roybakker     ########   odam.nl         */
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

int			get_amount_of_tokens(char *command)
{
	int i;
	int token;

	token = 0;
	i = 0;
	while (command[i] == ' ' && command[i] != '\0')
		i++;
	while (command[i] != '\0')
	{
		if (token_id(command[i]) == 1)
			special_char(command, &i, &token);
		else if (token_id(command[i]) == 3)
			dubbel_quotes(command, &i, &token);
		else if (token_id(command[i]) == 4)
			single_qoutes(command, &i, &token);
		else if (token_id(command[i]) == 0)
			basic_word(command, &i, &token);
		else
			i++;
	}
	if (token == 0)
		return (1);
	return (token);
}

int			token_id(char c)
{
	if (c == '>' || c == '<' || c == '|')
		return (1);
	else if (c == ' ')
		return (2);
	else if (c == 34)
		return (3);
	else if (c == 39)
		return (4);
	else
		return (0);
}

int		begin_token(char *command, int i)
{
	while (command[i] == ' ' && command[i] != '\0')
		i++;
	return (i);
}

int		len_token(char *command, int start, int len, int *space)
{
	int x;

	x = (token_id(command[start]) == 0) ? 0 : 1;
	if (x != 0)
		x = (token_id(command[start]) > 1) ? 3 : 1;
	else if (x > 1)
		x = (token_id(command[start]) > 3) ? 4 : 3;
	if (token_id(command[start]) == x && x < 2)
		while (token_id(command[start + len]) == x && command[start + len] != '\0')
		{
			len++;
			if (token_id(command[start + len]) == 2)
				(*space)++;
		}
	else
		len++;
	if (x > 2)
		while (token_id(command[start + len]) != x && command[start + len] != '\0')
		{
			len++;
			if (token_id(command[start + len]) == x)
				len++;
		}
	return (len);
}
