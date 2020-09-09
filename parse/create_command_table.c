/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_command_table.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 11:00:03 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/09 12:01:21 by roybakker     ########   odam.nl         */
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
	int		i;

	i = 0;
	data->command_amount = get_amount_of_commands(line, ';');
	printf("command amount = %d\n", data->command_amount);
	data->commands = (t_command_table**)malloc(sizeof(t_command_table*) * data->command_amount);
// 	CLEAR STRUCT WHEN FAIL
//
	commands = ft_split(line, ';');
// 	CLEAR STRUCT WHEN FAIL
//
	while(i < data->command_amount)
	{
		data->commands[i] = (t_command_table*)malloc(sizeof(t_command_table) * 1);
// 		CLEAR STRUCT WHEN FAIL
//
		data->commands[i]->token_amount = get_amount_of_tokens(commands[i]);
		printf("token amount = %d\n", data->commands[i]->token_amount);
		data->commands[i]->tokens = (char**)malloc(sizeof(char*) * data->commands[i]->token_amount);
// 		CLEAR STRUCT WHEN FAIL
//
		save_tokens(data, commands[i], i, 0);
		i++;
	}
	free_split_array(commands);
}


void	save_tokens(t_data *data, char *command, int i, int len)
{
	int start;
	int index;
	int space;
	int c;

	c = 0;
	index = 0;
	while (command[c] == ' ' && command[c] != '\0')
		c++;
	while (command[c] != '\0' && index < data->commands[i]->token_amount)
	{
		space = 0;
		start = begin_token(command, c);
		len = len_token(command, start, 0, &space);
		data->commands[i]->tokens[index] = ft_substr(command, start, len);
		printf("token [%d] = [%s]\n", index, data->commands[i]->tokens[index]);
// 		CLEAR STRUCT WHEN FAIL
//
		c += len + space;
		index++;
	}
}
