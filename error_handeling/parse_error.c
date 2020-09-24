/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_error.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/14 10:53:18 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/24 14:08:50 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_error(char charachter)
{
	print(1, "minishell: parse error near ");
	if (charachter == '>')
		print(1, "> \n");
	else if (charachter == '<')
		print(1, "< \n");
	else if (charachter == '|')
		print(1, "| \n");
	else if (charachter == ';')
		print(1, "; \n");
	else if (charachter == '\"')
		print(1, "\" \n");
	else if (charachter == '\'')
		print(1, "\' \n");
//	CLEAR STRUCT WHEN FAIL
//
	exit(1);
}
