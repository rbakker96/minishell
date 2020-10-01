/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execution_error.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/30 14:33:38 by roybakker     #+#    #+#                 */
/*   Updated: 2020/10/01 16:06:19 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	redirection_error(t_data *data, char *filename, int i, int *token)
{
	int errno;

	print(2, "minishell: ");
	print(2, filename);
	print(2, " : ");
	print(2, strerror(errno));

	(*token) = data->commands[i]->token_amount;
}

void	malloc_error(t_data *data, int index, char **malloced_array)
{
	int i;

	i = 0;
	index++;
	print(2, "minishell : error due to malloc failure\n");
	if (malloced_array)
		free_array(malloced_array);
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

void	fork_error(t_data *data, int index)
{
	int i;

	i = 0;
	index++;
	print(2, "minishell : error due to fork failure\n");
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
