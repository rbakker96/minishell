/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_pipe_fd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: qli <qli@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/09 15:02:51 by qli           #+#    #+#                 */
/*   Updated: 2020/10/12 14:43:31 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	create_pipe_fd(t_data *data, int cmd)
{
	calculate_pipe_num(data, cmd);
	printf("pipe num is %d\n", data->pipe_num);
	malloc_pipe_fd(data, cmd);
}

void	calculate_pipe_num(t_data *data, int cmd)
{
	int i;
	char *value;

	i = 0;
	value = data->commands[cmd]->tokens[i];
	while (i < data->commands[cmd]->token_amount)
	{
		if (value[0] != '\0' && ft_strncmp("|", value, ft_strlen(value)) == 0)
		{
			data->pipe_num++;
		}
		i++;
		value = data->commands[cmd]->tokens[i];
	}
}

void	malloc_pipe_fd(t_data *data, int cmd)
{
	int	i;
	int	pipe_ret;

	i = 0;
	pipe_ret = 0;
	data->pipefd = (int **)malloc(sizeof(int *) * (data->pipe_num + 1));
	// add error management
	while (i < data->pipe_num)
	{
		data->pipefd[i] = (int *)malloc(sizeof(int) * 2);
		// add error management
		pipe_ret = pipe(data->pipefd[i]);
		// add error management
		if (pipe_ret == -1)
			fork_error(data, cmd);
		printf("data->pipefd[i][0] is %d\n", data->pipefd[i][0]);
		printf("data->pipefd[i][1] is %d\n", data->pipefd[i][1]);
		i++;
	}
	data->pipefd[i] = NULL;
}
