/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_command_table.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 11:00:03 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/22 13:19:01 by roybakker     ########   odam.nl         */
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
	input_validation(&line);
	create_command_table(data, line);
	free(line);
	return (0);
}

void	create_command_table(t_data *data, char *line)
{
	char	**commands;
	int		i;

	i = 0;
	data->command_amount = get_amount_of_commands(line, 1);
	printf("command amount = %d\n", data->command_amount);
	data->commands = (t_command_table**)malloc(sizeof(t_command_table*) * (data->command_amount + 1));
// 	CLEAR STRUCT WHEN FAIL
//
	commands = save_commands(line, data->command_amount, 0, 0);
	while(i < data->command_amount)
	{
		data->commands[i] = (t_command_table*)malloc(sizeof(t_command_table) * 1);
// 		CLEAR STRUCT WHEN FAIL
//
		data->commands[i]->token_amount = get_amount_of_tokens(commands[i], 0, 0);
		printf("token amount = %d\n", data->commands[i]->token_amount);
		data->commands[i]->tokens = (char**)malloc(sizeof(char*) * (data->commands[i]->token_amount + 1));
// 		CLEAR STRUCT WHEN FAIL
//
		save_tokens(data, commands[i], i, 0);
		i++;
	}
	free_array(commands);
}
