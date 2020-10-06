/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:50:32 by roybakker         #+#    #+#             */
/*   Updated: 2020/10/06 17:42:07 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		get_amount_of_commands(char *line, int i)
{
	int count;

	count = 0;
	while (line[i] != '\0')
	{
		while(line[i] == ' ')
			i++;
		if (token_id(line[i]) >= normal_char && line[i] != '\0' && line[i] != ';')
			count++;
		while (line[i] != '\0')
		{
			if (line[i] == ';' && line[i - 1] != '\\')
				break ;
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
		if (token_id(command[i]) == space)
			i++;
		else if (token_id(command[i]) == meta_char)
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
	else if (c == '\"')
		return (2);
	else if (c == '\'')
		return (3);
	else
		return (4);
}
