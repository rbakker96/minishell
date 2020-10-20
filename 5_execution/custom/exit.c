/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:51:32 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/20 14:39:29 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_exit(t_data *data, int cmd, int tkn, int needed_tokens)
{
	if (data && cmd && tkn && needed_tokens)
		print(data, 1, ".", 0);
	return ;
}
