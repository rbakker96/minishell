/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:39:39 by roybakker         #+#    #+#             */
/*   Updated: 2020/10/06 17:40:24 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	special_char(char *command, int *i, int *token)
{
	(*token)++;
	if (command[(*i)] == '>' && command[(*i) + 1] == '>')
		(*i) += 2;
	else
		(*i)++;
}

void	quoted_sentence(char *command, int *i, int x)
{
	int quotes;

	quotes = 1;
	(*i)++;
	while (quotes != 0 && command[(*i)] != '\0')
	{
		if (command[(*i)] == '\\' && x != 3)
			(*i) += 2;
		if (token_id(command[(*i)]) == x)
			quotes--;
		(*i)++;
	}
}

void	basic_word(char *command, int *i, int *token)
{
	(*token)++;
	while (command[(*i)] != '\0' && command[(*i)] != ' ')
	{
		while (token_id(command[(*i)]) == 4 && command[(*i)] != '\0')
		{
			if (command[(*i)] == '\\')
				(*i) += 2;
			else
				(*i)++;
		}
		if (token_id(command[(*i)]) == 2 || token_id(command[(*i)]) == 3)
			quoted_sentence(command, i, token_id(command[(*i)]));
		if (token_id(command[(*i)] == meta_char))
			break ;
	}
}
