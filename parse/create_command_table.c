/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_command_table.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 11:00:03 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/03 16:24:58 by qli           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parse_command(t_data *data)
{
	int 	res;
	char 	*line;

	res = get_next_line(0, &line);
	if (res == -1)
		return (-1);
//	CLEAR STRUCT WHEN FAIL
	if (input_validate(line) == -1)
		return (-1);
	create_command_table(data, line);
	free(line);
	return (0);
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
		interpert_command(data, commands[index], index);
		index++;
	}
	free(commands);
}

void	interpert_command(t_data *data, char *command, int index)
{
	int size;
	char **tokens;

	tokens = ft_split(command, ' ');
//	CLEAR STRUCT WHEN FAIL
//
	data->table[index] = (t_command_table*)malloc(sizeof(t_command_table) * 1);
// 	CLEAR STRUCT WHEN FAIL
//
	size = commands_count(tokens);
	if (size <= 3 && command_type_check(command) == 0)
		small_command(data, tokens, index, size);
	else
		big_command(data, tokens, index);
}
