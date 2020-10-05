/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shell_expansions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/05 19:44:06 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/05 21:13:59 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	shell_expansions(t_data *data, int i, int token)
{
	int len;
	char *token;
	char *new_token;

	token = data->commands[i]->tokens[token];
	while (token < data->commands[i]->token_amount)
	{
		len = expansion_len(data, token, 0, 0);
		new_token = malloc(sizeof(char) * (len + 1));
		if (new_token == NULL)
		//malloc error
		expand_token(data, token, new_token, 0);
	}
}
