/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 14:51:19 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/15 18:07:22 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_env(t_data *data, int *tkn)
{
	int index;

	index = 0;
	while (data->envp[index] != 0)
	{
		print(data, data->iostream[1], data->envp[index], 0);
		print_char(data, data->iostream[1], '\n', 0);
		index++;
	}
	*tkn = *tkn + 1;
}
