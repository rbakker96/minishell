/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_functions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/05 21:11:22 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/05 21:20:51 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	expand_token(t_data *data, char *token, char *new_token, int i, int x)
{
	while (token[i] != '\0')
	{
		if (token[i] == '\'')
			single_quotes();
		else if (token[i] == '\"')
			double_quotes();
		else if (token[i] == '$')
			env_variable();
		else if (token[i] == '\\')
		{


		}
		else
		{


		}
	}
}

void	single_quotes(t_data *data, char *token, char *new_token, int *i, int *x)
{
	(*i)++;
	while(token[(*i)] != '\'')
	{
		(*i)++;
		(*len)++;
	}
	(*i)++;
}
