/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:50:20 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/10 11:44:07 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	go_to_home(t_data *data, int command, int *token)
// {
	
// }

void	execute_cd(t_data *data, int command, int *token)
{
	chdir(data->commands[command]->tokens[(*token) + 1]);
//		CLEAR STRUCT WHEN FAIL
//
	return ;
}
