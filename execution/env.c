/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:51:19 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/24 13:51:53 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_env(t_data *data, int command, int *token)
{
	int index;

	index = 0;
	while(data->env[index] != 0)
	{
		print(1, data->env[index]);
		printf("\n");
		index++;
	}
	if (command && (*token))
		print(1, ".");
	*token = *token + 1;
}
