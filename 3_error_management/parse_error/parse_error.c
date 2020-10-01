/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_error.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/14 10:53:18 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/30 14:19:46 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_error(char charachter, int *ret)
{
	if (*ret != -1)
	{
		print(2, "minishell: parse error near ");
		print_char(2, charachter);
		print_char(2, '\n');
	}
	(*ret) = -1;
}
