/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_two.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/04 12:50:32 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/08 16:49:17 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		get_amount_of_commands(char *line, int i)
{
	int count;

	count = 0;
	while (line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] != '\0' && line[i] != ';')
			count++;
		while (line[i] != '\0')
		{
			if (line[i] == ';')
				break ;
			else if (line[i] == '\\')
				i += 2;
			else
				i++;
		}
		if (line[i] != '\0')
			i++;
	}
	return (count);
}

int			get_amount_of_tokens(char *command, int i, int token)
{
	while (command[i] == ' ' && command[i] != '\0')
		i++;
	while (command[i] != '\0')
	{
		if (char_type(command[i]) == space)
			i++;
		else if (char_type(command[i]) == meta_char)
			meta_token(command, &i, &token);
		else
			normal_token(command, &i, &token);
	}
	if (token == 0)
		return (1);
	return (token);
}

int			char_type(char c)
{
	if (c == ' ')
		return (space);
	else if (c == '>' || c == '<' || c == '|')
		return (meta_char);
	else if (c == '\"')
		return (double_quote);
	else if (c == '\'')
		return (single_quote);
	else
		return (normal_char);
}
