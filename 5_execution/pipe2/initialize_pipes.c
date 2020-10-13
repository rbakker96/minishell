/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_pipes.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/13 14:29:01 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/13 16:50:58 by rbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	initialize_pipes(t_data *data, int cmd)
{
	int		pipe_amount;
	int		i;

	i = 0;
	pipe_amount = get_pipes_amount(data, cmd);
	printf("pipe amount = %d\n", pipe_amount);
	data->commands[cmd]->fd = (int **)malloc(sizeof(int *) * (pipe_amount + 1));
	if (data->commands[cmd]->fd == NULL)
		malloc_error(data, data->command_amount, 0);
	while (i < pipe_amount)
	{
		data->commands[cmd]->fd[i] = (int *)malloc(sizeof(int) * 2);
		if (data->commands[cmd]->fd == NULL)
			malloc_error(data, data->command_amount, 0);
		if (pipe(data->commands[cmd]->fd[i]) == -1)
			printf("pipe error\n"); // change later
		printf("\npipe fd [%d][0] = %d\n", i, data->commands[cmd]->fd[i][0]);
		printf("pipe fd [%d][1] = %d\n\n", i, data->commands[cmd]->fd[i][1]);
		i++;
	}
	data->commands[cmd]->fd[i] = NULL;
	data->commands[cmd]->pipe_index = 0;
}

int		get_pipes_amount(t_data *data, int cmd)
{
	char	*value;
	int		i;

	i = 0;
	value = data->commands[cmd]->tokens[i];
	data->commands[cmd]->pipe_amount = 0;
	while (i < data->commands[cmd]->token_amount)
	{
		if (value[0] != '\0' && ft_strncmp("|", value, ft_strlen(value)) == 0)
			data->commands[cmd]->pipe_amount++;
		i++;
		value = data->commands[cmd]->tokens[i];
	}
	return (data->commands[cmd]->pipe_amount);
}
