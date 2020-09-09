/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:50:20 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/09 16:00:54 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_cd(t_data *data, int command, int *token)
{
	if (data && command && (*token))
		print(".");
	return ;
}
