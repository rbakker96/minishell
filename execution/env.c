/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:51:19 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/10 17:38:53 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_env(t_data *data, int command, int *token)
{
	int index;

	index = 0;
	while(data->env[index] != 0)
	{
		print(data->env[index]);
		printf("\n");
		index++;
	}
	if (command && (*token))
		print(".");
	*token = *token + 1;
}
