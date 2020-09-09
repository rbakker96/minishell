/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:51:19 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/09 16:37:24 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_env(t_data *data, int command, int *token)
{
	int index;

	index = 0;
	if (command && (*token))
		print(".");
	while(data->env[index] != 0)
	{
		print(data->env[index]);
		printf("\n");
		index++;
	}
}
