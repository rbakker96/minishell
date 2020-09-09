/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unset.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:50:49 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/09 16:01:45 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_unset(t_data *data, int command, int *token)
{
	if (data && command && (*token))
		print(".");
	return ;
}
