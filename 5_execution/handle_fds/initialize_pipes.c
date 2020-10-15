/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_pipes.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbakker <rbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/13 14:29:01 by rbakker       #+#    #+#                 */
/*   Updated: 2020/10/15 19:16:09 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// discuss whether we need + 1 for an int array as they don't need to end with NULL
void	initialize_pipes(t_data *data, int cmd)
{
	int		pipe_nb;
	int		i;

	i = 0;
	pipe_nb = get_pipes_amount(data, cmd, 0);
	printf("pipe amount = %d\n", pipe_nb);
	data->commands[cmd]->pipes = (int **)malloc(sizeof(int *) * (pipe_nb + 1));
	if (data->commands[cmd]->pipes == NULL)
		malloc_error(data, data->command_amount, 0);
	while (i < pipe_nb)
	{
		data->commands[cmd]->pipes[i] = (int *)malloc(sizeof(int) * 2);
		if (data->commands[cmd]->pipes == NULL)
			malloc_error(data, data->command_amount, 0);
		if (pipe(data->commands[cmd]->pipes[i]) == -1)
			printf("pipe error\n"); // change later
		i++;
	}
	data->commands[cmd]->pipes[i] = NULL;
	data->commands[cmd]->pipe_pos = 0;
}

int		get_pipes_amount(t_data *data, int cmd, int i)
{
	char	*value;

	value = data->commands[cmd]->tokens[i];
	data->commands[cmd]->pipe_nb = 0;
	while (i < data->commands[cmd]->token_amount)
	{
		if (value[0] != '\0' && ft_strncmp("|", value, ft_strlen(value)) == 0)
			data->commands[cmd]->pipe_nb++;
		i++;
		value = data->commands[cmd]->tokens[i];
	}
	return (data->commands[cmd]->pipe_nb);
}