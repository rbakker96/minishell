/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_command_table.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 11:00:03 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/08 15:57:20 by roybakker     ########   odam.nl         */
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

	data->i = 0;
	data->command_amount = get_amount_of_commands(line, ';');
	printf("command amount = %d\n", data->command_amount);
	data->commands = (t_command_table**)malloc(sizeof(t_command_table*) * data->command_amount);
// 	CLEAR STRUCT WHEN FAIL
//
	commands = ft_split(line, ';');
// 	CLEAR STRUCT WHEN FAIL
//
	while(data->i < data->command_amount)
	{
		data->commands[data->i] = (t_command_table*)malloc(sizeof(t_command_table) * data->command_amount);
// 		CLEAR STRUCT WHEN FAIL
//
		data->commands[data->i]->token_amount = get_amount_of_tokens(commands[data->i]);
		printf("token amount = %d\n", data->commands[data->i]->token_amount);
		data->commands[data->i]->tokens = (char**)malloc(sizeof(char*) * data->commands[data->i]->token_amount);
// 		CLEAR STRUCT WHEN FAIL
//
		process_tokens(data, commands[data->i], 0, 0);
		data->i++;
	}
	// free array commands
}


void	process_tokens(t_data *data, char *command, int i, int len)
{
	int start;
	int index;
	int space;

	index = 0;
	while (command[i] == ' ' && command[i] != '\0')
		i++;

	while (command[i] != '\0' && index < data->commands[data->i]->token_amount)
	{
		space = 0;
		start = begin_token(command, i);
		len = len_token(command, start, 0, &space);
		data->commands[data->i]->tokens[index] = ft_substr(command, start, len);
		printf("token [%d] = [%s]\n", index, data->commands[data->i]->tokens[index]);
// 		CLEAR STRUCT WHEN FAIL
//
		i += len + space;
		index++;
	}
}
