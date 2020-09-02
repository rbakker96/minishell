/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_command_table.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 11:00:03 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/02 17:41:06 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_command(t_data *data)
{
	int 	res;
	char 	*line;

	res = get_next_line(0, &line);
//	CLEAR STRUCT WHEN FAIL
//
	create_command_table(data, line);
	free(line);
	return ;
}

void	create_command_table(t_data *data, char *line)
{
	int		count;
	int 	index;
	char	**commands;

	index = 0;
	commands = ft_split(line , ';');
//	CLEAR STRUCT WHEN FAIL
//
	count = commands_count(commands);
	printf("%d \n", count);
//	CLEAR STRUCT WHEN FAIL
//
	data->table = (t_command_table**)malloc(sizeof(t_command_table*) * (count + 1));
// 	CLEAR STRUCT WHEN FAIL
//
	while(commands[index] != 0)
	{
		interpert_command(data, commands[index], index);
		index++;
	}
	free(commands);
}

void	interpert_command(t_data *data, char *command, int index)
{
	int count;

	count = (arguments_count(command) == 0) ? 1 : arguments_count(command);
	printf("testinggggg\n");
	if (count == 1)
	{
		printf("testasdfasdfasdf\n");
		small_command(data, command, index);
	}
	if (count <= 3 && redirection_pipe_check(command) == 0)
		average_command(data, command, index);
	else
		big_command(data, command, index);
}
