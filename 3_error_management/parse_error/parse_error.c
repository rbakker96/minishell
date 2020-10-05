/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_error.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/14 10:53:18 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/05 15:11:20 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_error(char charachter, int *ret)
{
	if (*ret != -1)
	{
		print(0, 2, "minishell: parse error near ", 0);
		print_char(0, 2, charachter, 0);
		print_char(0, 2, '\n', 0);
	}
	(*ret) = -1;
}
