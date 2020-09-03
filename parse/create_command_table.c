/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_command_table.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 11:00:03 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/03 14:04:42 by roybakker     ########   odam.nl         */
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
//	input_validate(data, line);
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
	data->table = (t_command_table**)malloc(sizeof(t_command_table*) * (count + 1));
// 	CLEAR STRUCT WHEN FAIL
//
	while(commands[index] != 0)
	{
		printf("%d\n", index);
		interpert_command(data, commands[index], index);
		index++;
	}
	free(commands);
}

void	interpert_command(t_data *data, char *command, int index)
{
	int count;
	data->table[index] = (t_command_table*)malloc(sizeof(t_command_table) * 1);
// 	CLEAR STRUCT WHEN FAIL
//
	count = (arguments_count(command) == 0) ? 1 : arguments_count(command);

	if (count == 1)
	{
		small_command(data, command, index);
	}
	else if (count <= 3 || command_type_check(command) != 0)
		average_command(data, command, index);
	else
		big_command(data, command, index);
}
