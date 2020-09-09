/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:51:32 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/09 16:01:29 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_exit(t_data *data, int command, int *token)
{
	if (data && command && (*token))
		print(".");
	return ;
}
