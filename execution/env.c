/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:51:19 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/09 16:01:18 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_env(t_data *data, int command, int *token)
{
	if (data && command && (*token))
		print(".");
	return ;
}
