/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:49:34 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/23 16:04:11 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// get fd to write to --> create_fd() (no input redirection)

// acces te amount of tokens that needs to be handeld

// see if -n option is used

// write tokens one by one to the right fd

void	execute_echo(t_data *data, int i, int *token, int token_amount)
{
//	char	*value;
//	int		newline;
//	int		fd;

//	fd = create_fd(data, i, (*token), &token_amount);


//	newline = new_line_option(value, token_amount, token);
	while((*token) < token_amount)
	{
		print(data->commands[i]->tokens[(*token)]);
		(*token)++;
	}
//	if (!newline)
//		print("\n");
	return ;
}

//int	new_line_option(char *value, int token_amount, int *token)
//{
//	if (ft_strncmp("-n", value, ft_strlen((*value))) == 0)
//	{
//		((*token) < token_amount ) ? (*token)++ : (*token);
//		return (1);
//	}
//	else
//		return (0);
//}
