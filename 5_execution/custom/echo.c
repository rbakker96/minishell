/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:49:34 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/15 17:48:01 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_echo(t_data *data, int cmd, int *tkn, int needed_tokens)
{
	char	*value;
	int		newline;

	needed_tokens = calculate_needed_tokens(data, cmd, (*tkn));
	(*tkn)++;
	value = data->commands[cmd]->tokens[(*tkn)];
	newline = newline_option(value, needed_tokens, tkn);
	while ((*tkn) < needed_tokens)
	{
		print(data, data->fd[1], data->commands[cmd]->tokens[(*tkn)], 0);
		if ((*tkn) != (needed_tokens - 1))
			print(data, data->fd[1], " ", 0);
		(*tkn)++;
	}
	if (newline)
		print_char(data, 1, '\n', 0);
	update_token_position(data, cmd, tkn);
}

int		newline_option(char *value, int needed_tokens, int *tkn)
{
	if (!value)
		return (0);
	else if (compare_command("-n", value, 2) == 0)
	{
		((*tkn) < needed_tokens) ? (*tkn)++ : (*tkn);
		return (0);
	}
	else
		return (1);
}
