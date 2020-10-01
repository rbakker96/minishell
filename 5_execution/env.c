/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:51:19 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/01 16:56:40 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_env(t_data *data, int *token)
{
	int index;

	index = 0;
	while(data->envp[index] != 0)
	{
		print(1, data->envp[index]);
		printf("\n");
		index++;
	}
	*token = *token + 1;
}
