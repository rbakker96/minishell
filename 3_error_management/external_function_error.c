/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_function_error.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakker <rbakker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 14:33:38 by roybakker         #+#    #+#             */
/*   Updated: 2020/10/07 13:47:14 by rbakker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	fork_error(t_data *data, int index)
{
	int i;

	i = 0;
	index++;
	print(data, 2, "minishell : error due to fork failure\n", 0);
	free(data->input);
	free_array(data->envp);
	if (data->args)
		free_array(data->args);
	while(i < index)
	{
		free_array(data->commands[i]->tokens);
		free(data->commands[i]);
		i++;
	}
	free(data->commands);
	exit(1);
}

void	write_error(t_data *data, char *malloced_str)
{
	print(data, 2, "minishell : write function failed\n", 0);
	if (malloced_str)
		free(malloced_str);
	if (data->envp)
		free_array(data->envp);
	if (data->args)
		free_array(data->args);
	free_struct(data);
	exit(1);
}
