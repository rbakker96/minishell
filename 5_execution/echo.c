/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:49:34 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/12 11:30:15 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_echo(t_data *data, int cmd, int *tkn, int needed_tokens)
{
	char	*value;
	int		newline;

	(*tkn)++;
	value = data->commands[cmd]->tokens[(*tkn)];
	newline = 1;
	while ((*tkn) < needed_tokens)
	{
		print(data, data->fd[1], data->commands[cmd]->tokens[(*tkn)], 0);
		print(data, data->fd[1], " ", 0);
		(*tkn)++;
	}
	if (newline)
		print_char(data, 1, '\n', 0);
	return ;
}
