/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:51:32 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/01 16:58:36 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_exit(t_data *data, int i, int *token)
{
	if (data && i && (*token))
		print(1, ".");
	return ;
}
