/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 14:39:39 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/12 11:15:40 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	meta_token(char *command, int *cmd, int *tkn)
{
	(*tkn)++;
	if (command[(*cmd)] == '>' && command[(*cmd) + 1] == '>')
		(*cmd) += 2;
	else
		(*cmd)++;
}

void	quoted_sentence(char *command, int *cmd, int quote_type)
{
	int quotes;

	quotes = 1;
	(*cmd)++;
	while (quotes != 0 && command[(*cmd)] != '\0')
	{
		if (char_type(command[(*cmd)]) == quote_type)
			quotes--;
		(command[(*cmd)] == '\\' && quote_type != single_quote) ? (*cmd) += 2 :
																(*cmd)++;
	}
}

void	normal_token(char *command, int *cmd, int *tkn)
{
	(*tkn)++;
	while (command[(*cmd)] != '\0' && command[(*cmd)] != ' ')
	{
		while (char_type(command[(*cmd)]) == normal_char && command[(*cmd)] != '\0')
			(command[(*cmd)] == '\\') ? (*cmd) += 2 : (*cmd)++;
		if (char_type(command[(*cmd)]) == single_quote ||
			char_type(command[(*cmd)]) == double_quote)
			quoted_sentence(command, cmd, char_type(command[(*cmd)]));
		if (char_type(command[(*cmd)] == meta_char))
			break ;
	}
}
