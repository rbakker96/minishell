/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_error.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/14 10:53:18 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/15 11:27:53 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_error(char charachter)
{
	print("minishell: parse error near ");
	if (charachter == '>')
		print("> \n");
	else if (charachter == '<')
		print("< \n");
	else if (charachter == '|')
		print("| \n");
	else if (charachter == ';')
		print("; \n");
	else if (charachter == '\"')
		print("\" \n");
	else if (charachter == '\'')
		print("\' \n");
//	CLEAR STRUCT WHEN FAIL
//
	exit(1);
}
