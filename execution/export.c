/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   export.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:50:36 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/09 16:01:36 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_export(t_data *data, int command, int *token)
{
	if (data && command && (*token))
		print(".");
	return ;
}
