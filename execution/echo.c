/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   echo.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:49:34 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/09 16:01:03 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_echo(t_data *data, int command, int *token)
{
	if (data && command && (*token))
		print(".");
	return ;
}
