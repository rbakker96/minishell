/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_command_table.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 11:00:03 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/03 21:30:07 by roybakker     ########   odam.nl         */
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
//
	if (input_validate(line) == -1)
		return (-1);
	create_command_table(data, line);
	free(line);
	return (0);
}

void	create_command_table(t_data *data, char *line)
{
	char	**commands;

	commands = ft_split(line , ';');
//	CLEAR STRUCT WHEN FAIL
//
	data->index = 0;
	data->size = calculate_table_size(commands);
	data->table = (t_command_table**)malloc(sizeof(t_command_table*) * (data->size));
// 	CLEAR STRUCT WHEN FAIL
//
	while(data->index < data->size)
	{
		if (pipe_check(commands[data->index]) == 0)
			basic_command(data, commands[data->index], 1);
		else
			piped_command(data, commands[data->index]);
		data->index++;
	}
	free(commands);
}

void	basic_command(t_data *data, char *command, int index)
{
	int		size;
	char 	**tokens;

	tokens = ft_split(command, ' ');
// 	CLEAR STRUCT WHEN FAIL
//
	data->table[data->index] = (t_command_table*)malloc(sizeof(t_command_table) * 1);
//	CLEAR STRUCT WHEN FAIL
//
	data->table[data->index]->command = tokens[0];
	data->table[data->index]->exit_code = 0;
	size = commands_count(tokens);
	while(index < size && data->table[data->index]->output == 0)
	{
		if (redirection(tokens[index]) == 0 || option(tokens[index]) == 0)
			data->table[data->index]->operation = tokens[index];
		else if (tokens[index - 1][0] == '>')
			data->table[data->index]->output = tokens[index];
		else if (data->table[data->index]->input == 0)
			data->table[data->index]->input = ft_strdup(tokens[index]);
		else
			data->table[data->index]->input = join(data->table[data->index]->input, tokens[index], 0, 0);
		index++;
	}
	printf("saved command in struct \ncommand = [%s]\n", data->table[data->index]->command);
	printf("operation = [%s]\n", data->table[data->index]->operation);
	printf("input = [%s]\n", data->table[data->index]->input);
	printf("output = [%s]\n", data->table[data->index]->output);
}

void	piped_command(t_data *data, char *command)
{
	if (data && command)
	return ;
}
