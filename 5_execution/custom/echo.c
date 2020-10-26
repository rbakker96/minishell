/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:49:34 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/26 10:05:28 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_echo(t_data *data, int cmd, int tkn, int needed_tokens)
{
	int		newline;

	needed_tokens = calculate_needed_tokens(data, cmd, tkn);
	tkn++;
	newline = newline_option(data, cmd, &tkn);
	while (tkn < needed_tokens)
	{
		print(data, data->iostream[1], data->commands[cmd]->tokens[tkn], 0);
		if (tkn != (needed_tokens - 1)&& data->commands[cmd]->tokens[tkn][0] != '\0') // make function check empty string
			print(data, data->iostream[1], " ", 0);
		tkn++;
	}
	if (!newline)
		print_char(data, 1, '\n', 0);
}

int		newline_option(t_data *data, int cmd, int *tkn)
{
	char	*value;

	value = data->commands[cmd]->tokens[*tkn];
	if (!value)
		return (0);
	else if (compare_command("-n", value, 2) == 0)
	{
		while (compare_command("-n", value, 2) == 0)
		{
			(*tkn)++;
			value = data->commands[cmd]->tokens[(*tkn)];
		}
		return (1);
	}
	else
		return (0);
}
