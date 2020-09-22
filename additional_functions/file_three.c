/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 14:39:39 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/22 14:50:54 by roybakker     ########   odam.nl         */
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

	quotes = quotes_count(command, (*i), x);
	(*i)++;
	while(quotes != 0 && command[(*i)] != '\0')
	{
		if(command[(*i)] == '\\')
			(*i) += 2;
		if (token_id(command[(*i)]) == x)
			quotes--;
		(*i)++;
	}
	if (command[(*i)] != '\0')
		(*i)++;
}

void	basic_word(char *command, int *i, int *token)
{
	(*token)++;
	while(token_id(command[(*i)]) == 4 && command[(*i)] != '\0')
	{
		if(command[(*i)] == '\\')
			(*i) += 2;
		else
			(*i)++;
	}
	if (token_id(command[(*i)]) == 2 || token_id(command[(*i)]) == 3)
		quoted_sentence(command, i, token_id(command[(*i)]));
	while(token_id(command[(*i)]) == 4 && command[(*i)] != '\0')
	{
		if(command[(*i)] == '\\')
			(*i) += 2;
		else
			(*i)++;
	}
}

int		quotes_count(char *command, int i, int x)
{
	int index;
	int count;

	count = 0;
	index = i + 1;
	while (command[index] != '\0')
	{
		if (token_id(command[index]) == x)
			count++;
		if(command[index] == '\\')
			index += 2;
		else
			index++;
	}
	return (count);
}
