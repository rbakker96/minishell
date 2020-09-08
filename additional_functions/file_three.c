/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 14:39:39 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/08 16:13:41 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	special_char(char *command, int *i, int *token)
{
	(*token)++;
	while(token_id(command[(*i)]) == 1 && command[(*i)] != '\0')
		(*i)++;
}

void	dubbel_quotes(char *command, int *i, int *token)
{
	(*token)++;
	(*i)++;
	while(token_id(command[(*i)]) != 3 && command[(*i)] != '\0')
		(*i)++;
	if (command[(*i)] != '\0')
		(*i)++;
}

void	single_qoutes(char *command, int *i, int *token)
{
	(*token)++;
	(*i)++;
	while(token_id(command[(*i)]) != 4 && command[(*i)] != '\0')
		(*i)++;
	if (command[(*i)] != '\0')
		(*i)++;
}

void	basic_word(char *command, int *i, int *token)
{
	(*token)++;
	while(token_id(command[(*i)]) == 0 && command[(*i)] != '\0')
		(*i)++;
}
