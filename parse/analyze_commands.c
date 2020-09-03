/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   analyze_commands.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 15:56:23 by roybakker     #+#    #+#                 */
/*   Updated: 2020/09/03 17:52:29 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	small_command(t_data *data, char **tokens, int index, int size)
{
	data->table[index]->command = (t_command**)malloc(sizeof(t_command*) * 1);
//	CLEAR STRUCT WHEN FAIL
//
	data->table[index]->command[0] = (t_command*)malloc(sizeof(t_command) * 1);
//	CLEAR STRUCT WHEN FAIL
//
	data->table[index]->command[0]->small.command = tokens[0];
	if (size == 1)
	{
		data->table[index]->command[0]->small.option = 0;
		data->table[index]->command[0]->small.input = 0;
	}
	else if (option_check(tokens[1]) != 0)
	{
		data->table[index]->command[0]->small.option = 0;
		data->table[index]->command[0]->small.input = tokens[1];
	}
	else
	{
		data->table[index]->command[0]->small.option = tokens[1][1];
		data->table[index]->command[0]->small.input = tokens[2];
	}
	data->table[index]->command[0]->small.exit_code = 0;
	printf("command in small struct : %s\n", data->table[index]->command[0]->small.command);
	printf("option in small struct : %c\n", data->table[index]->command[0]->small.option);
	printf("input in small struct : %s\n", data->table[index]->command[0]->small.input);
	return ;
}

void	big_command(t_data *data, char *command, int index)
{
	int count;
	int id;
	char **tokens;

	id = 0;
	tokens = ft_split(command, '|');
//	CLEAR STRUCT WHEN FAIL
//
	count = commands_count(tokens);
	data->table[index]->command = (t_command**)malloc(sizeof(t_command*) * count);
//	CLEAR STRUCT WHEN FAIL
//
	data->table[index]->command[0] = (t_command*)malloc(sizeof(t_command) * 1);
//	CLEAR STRUCT WHEN FAIL
//
	data->table[index]->command[0]->small.command = tokens[0];
	data->table[index]->command[0]->big.option = ;
	data->table[index]->command[0]->big.input = ;
	data->table[index]->command[0]->big.output = ;
	data->table[index]->command[0]->small.exit_code = 0;

	return ;
}
