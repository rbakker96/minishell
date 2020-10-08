/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 14:39:39 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/08 16:57:01 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	meta_token(char *command, int *i, int *token)
{
	(*token)++;
	if (command[(*i)] == '>' && command[(*i) + 1] == '>')
		(*i) += 2;
	else
		(*i)++;
}

void	quoted_sentence(char *command, int *i, int quote_type)
{
	int quotes;

	quotes = 1;
	(*i)++;
	while (quotes != 0 && command[(*i)] != '\0')
	{
		if (char_type(command[(*i)]) == quote_type)
			quotes--;
		(command[(*i)] == '\\' && quote_type != single_quote) ? i += 2 : i++;
	}
}

void	normal_token(char *command, int *i, int *token)
{
	(*token)++;
	while (command[(*i)] != '\0' && command[(*i)] != ' ')
	{
		while (char_type(command[(*i)]) == normal_char && command[(*i)] != '\0')
			(command[(*i)] == '\\') ? i += 2 : i++;
		if (char_type(command[(*i)]) == single_quote ||
			char_type(command[(*i)]) == double_quote)
			quoted_sentence(command, i, char_type(command[(*i)]));
		if (char_type(command[(*i)] == meta_char))
			break ;
	}
}
