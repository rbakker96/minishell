/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:49:34 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/24 14:43:48 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// get fd to write to --> create_fd() (no input redirection)

// acces te amount of tokens that needs to be handeld

// see if -n option is used

// write tokens one by one to the right fd

void	execute_echo(t_data *data, int i, int *token, int token_amount)
{
	int		newline;
	int		type;

	(*token)++;
	data->commands[i]->fd = create_fd(data, i, (*token), &token_amount);
	while(redirection_check(data->commands[i]->tokens[(*token)]) == redirected)
		(*token) += 2;
	newline = newline_option(data->commands[i]->tokens[(*token)], token_amount,
																		token);
	while((*token) < token_amount)
	{
		type = quotes_check(data->commands[i]->tokens[(*token)]);
		if (type == normal_char)
			no_quotes(data, i, token);
		else if (type == double_quote)
			double_quotes(data, i, token);
		else if (type == single_quote)
			single_quotes(data, i, token);
		else
			(*token)++;
	}
	if (!newline)
		print(data->commands[i]->fd.output, "\n");
	return ;
}

int	newline_option(char *value, int token_amount, int *token)
{
	if (!value)
		return (0);
	else if (ft_strncmp("-n", value, ft_strlen(value)) == 0)
	{
		((*token) < token_amount ) ? (*token)++ : (*token);
		return (1);
	}
	else
		return (0);
}
